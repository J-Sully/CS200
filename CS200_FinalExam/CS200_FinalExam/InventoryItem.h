//
//  InventoryItem.h
//  CS200_FinalExam
//
//  Created by Jessie Sully on 7/22/19.
//  Copyright © 2019 Jessie Sully. All rights reserved.
//

#ifndef INVENTORYITEM_H
#define INVENTORYITEM_H

#include <iomanip>
#include <string>
#include <sstream>

#include "Unit.h"

using namespace std;

class InventoryItem {
public:
  InventoryItem(const string &ID, double price, double threshold, Unit::Type unit, double unitsRemaining)
  : mID(ID), mPrice(price), mLowStockThreshold(threshold), mUnit(unit), mUnitsRemaining(unitsRemaining) {}
  
  InventoryItem(istream& csvLine) { readCSV(csvLine); }
  
  virtual ~InventoryItem() {}
  
  virtual bool hasTax() const { return false; }
  virtual double getTax(double servings) const { return 0; }
  virtual double getTax(double qty, Unit::Type unit) const { return 0; }
  virtual const string& getItemType() const = 0;
  
  void setLowStockThreshold(double threshold) { mLowStockThreshold = threshold; }
  void setID(const string& ID)  { mID = ID; }
  void setPrice(double price) { if(price >= 0) mPrice = price; }
  
  const string& getID() const { return mID; }
  double getPrice() { return mPrice; }
  double getLowStockThreshold() const { return mLowStockThreshold; }
  
  virtual double getUnitsPerStock() const = 0;
  virtual double getUnitsPerServing() const = 0;
  double getUnitsRemaining() const { return mUnitsRemaining; }
  double getStockRemaining() const { return mUnitsRemaining / getUnitsPerStock(); }
  bool isLowStock() const { return getStockRemaining() <= mLowStockThreshold; }

  Unit::Type getUnit() const { return mUnit; }
  
  virtual bool readCSV(istream& csvLine);
  virtual void writeCSV(ostream &output) const;
  virtual void writeStatement(ostream &output) const;
  void print() const;
  
protected:
  InventoryItem() {}
  
private:
  string mID;
  double mPrice = 0;
  double mLowStockThreshold = 1;
  double mUnitsRemaining = 0;
  Unit::Type mUnit = Unit::OUNCES;
};

/* virtual */
void InventoryItem::writeStatement(ostream &output) const {
  const string& units = getUnitName(mUnit);
  output << "ID: " << mID << endl
  << "Item Type: " << getItemType() << endl
  << "Purchase Price: $" << fixed << setprecision(2) << mPrice << setprecision(0)
  << " for " << getUnitsPerStock() << " " << units << endl
  << "Serving size: " << setprecision(3) << getUnitsPerServing() << " " << units << endl
  << units << " remaining: " << mUnitsRemaining << endl
  << "Stock remaining: " << getStockRemaining() << endl
  << "Low stock threshold: " << mLowStockThreshold << endl
  << "Low on stock: " << (isLowStock() ? "true" : "false") << endl;
  if (hasTax()) {
    output << "Tax per serving: $" << setprecision(2) << getTax(1) << endl;
  }
}

template <typename T>
bool readToken(istream& csvLine, T& value) {
  string token;
  if (getline(csvLine, token, ',')) {
    stringstream tokenStream(token);
    tokenStream >> value;
    return true;
  }
  return false;
}

bool readToken(istream& csvLine, string& value) {
  string token;
  if (getline(csvLine, token, ',')) {
    value = token;
    return true;
  }
  return false;
}

/* virtual */
bool InventoryItem::readCSV(istream& csvLine) {
  bool success = true;
  
  string unitName;
  
  success &= readToken(csvLine, mID);
  success &= readToken(csvLine, mPrice);
  success &= readToken(csvLine, mLowStockThreshold);
  success &= readToken(csvLine, mUnitsRemaining);
  success &= readToken(csvLine, unitName);
  
  mUnit = Unit::getUnit(unitName);
  success &= (mUnit != Unit::LAST_UNIT);
  
  return success;
}

/* virtual */
void InventoryItem::writeCSV(ostream &output) const {
  output << getItemType() << ',' << mID << ',' << fixed << setprecision(8)
  << mPrice << ','
  << mLowStockThreshold << ','
  << mUnitsRemaining << ','
  << getUnitName(mUnit);
}

void InventoryItem::print() const {
  stringstream output;
  writeStatement(output);
  cout << output.str() << endl;
}

class NonAlcoholicItem : public InventoryItem {
public:
  static const string ItemType;
  NonAlcoholicItem(const string &ID, double price, double threshold,
                   Unit::Type unit, double unitsPerStock, double unitsPerServing,
                   double unitsRemaining = 0)
  : InventoryItem(ID, price, threshold, unit, unitsRemaining)
  , mUnitsPerStock(unitsPerStock), mUnitsPerServing(unitsPerServing) {}
  
  NonAlcoholicItem(istream& csvLine) : InventoryItem() { readCSV(csvLine); }
  
  virtual double getUnitsPerStock() const { return mUnitsPerStock; }
  virtual double getUnitsPerServing() const { return mUnitsPerServing; }
  
  virtual const string& getItemType() const { return ItemType; }
  
  virtual bool readCSV(istream& csvLine);
  virtual void writeCSV(ostream &output) const;
  
private:
  double mUnitsPerStock = 1;
  double mUnitsPerServing = 1;
};

/* static */ const string NonAlcoholicItem::ItemType = "non-alcoholic";

/* virtual */
bool NonAlcoholicItem::readCSV(istream& csvLine) {
  bool success = InventoryItem::readCSV(csvLine);
  
  success &= readToken(csvLine, mUnitsPerStock);
  success &= readToken(csvLine, mUnitsPerServing);
  
  return success;
}

/* virtual */
void NonAlcoholicItem::writeCSV(ostream &output) const {
  InventoryItem::writeCSV(output);
  output << ',' << mUnitsPerStock << ',' << mUnitsPerServing;
}

#endif /* INVENTORYITEM_H */
