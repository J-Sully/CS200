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

#include "Units.h"

using namespace std;

class InventoryItem {
public:
  InventoryItem(const string &ID, double price, unsigned int threshold, Unit unit)
  : mID(ID), mPrice(price), mLowPurchaseThreshold(threshold), mUnit(unit) {}
  
  virtual bool hasTax() const { return false; }
  virtual double getTax(double servings) const { return 0; }
  virtual double getTax(double qty, Unit unit) const { return 0; }
  
  void setLowServingsThreshold(unsigned int threshold) { mLowPurchaseThreshold = threshold; }
  void setID(const string& ID)  { mID = ID; }
  void setPrice(double price) { if(price >= 0) mPrice = price; }
  
  const string& getID() const { return mID; }
  double getPrice() { return mPrice; }
  unsigned int getLowServingsThreshold() const { return mLowPurchaseThreshold; }
  
  virtual double getUnitsPerPurchase() const = 0;
  virtual double getUnitsPerServing() const = 0;
  
  Unit getUnit() const { return mUnit; }
  
  virtual void writeStatement(stringstream &output) const;
  void print() const;
  
private:
  string mID;
  double mPrice = 0;
  unsigned int mLowPurchaseThreshold = 1;
  Unit mUnit = OUNCES;
};

class NonAlcoholicItem : public InventoryItem {
public:
  NonAlcoholicItem(const string &ID, double price, unsigned int threshold,
                   Unit unit, double unitsPerPurchase, double unitsPerServing)
  : InventoryItem(ID, price, threshold, unit)
  , mUnitsPerPurchase(unitsPerPurchase), mUnitsPerServing(unitsPerServing) {}
                  
  virtual double getUnitsPerPurchase() const { return mUnitsPerPurchase; }
  virtual double getUnitsPerServing() const { return mUnitsPerServing; }
  
private:
  double mUnitsPerPurchase = 1;
  double mUnitsPerServing = 1;
};

/* virtual */
void InventoryItem::writeStatement(stringstream &output) const {
  const char* units = getUnitName(mUnit);
  output << "ID: " << mID << endl
         << "Purchase Price: $" << fixed << setprecision(2) << mPrice << setprecision(0)
         << " for " << getUnitsPerPurchase() << " " << units << endl
         << "Serving size: " << setprecision(3) << getUnitsPerServing() << " " << units << endl;
  if (hasTax()) {
    output << "Tax per serving: $" << setprecision(2) << getTax(1) << endl;
  }
}

void InventoryItem::print() const {
  stringstream output;
  writeStatement(output);
  cout << output.str() << endl;
}

#endif /* INVENTORYITEM_H */
