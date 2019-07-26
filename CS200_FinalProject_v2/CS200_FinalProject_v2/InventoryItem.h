//
//  InventoryItem.h
//  CS200_FinalProject_v2
//
//  Created by Jessie Sully on 7/23/19.
//  Copyright © 2019 Jessie Sully. All rights reserved.
//

#ifndef INVENTORYITEM_H
#define INVENTORYITEM_H

#include <iomanip>
#include <string>
#include <sstream>
using namespace std;

#include "Unit.h"

class InventoryItem {
public:
  InventoryItem(const string &ID, double price, double threshold, Unit::Type unit, double servingPrice, double unitsRemaining = 0) : mID(ID), mPrice(price), mLowStockThreshold(threshold), mUnit(unit) {setServingPrice(servingPrice); setUnitsRemaining(unitsRemaining);}
  
  InventoryItem(istream& csvLine) { readCSV(csvLine); }
  
  virtual ~InventoryItem() {}
  
  void setLowStockThreshold(double threshold) { mLowStockThreshold = threshold; }
  void setID(const string& ID)  { mID = ID; }
  void setPrice(double price) { if(price >= 0) mPrice = price; }
  void setUnitsRemaining(double unitsRemaining) { if (unitsRemaining >= 0) mUnitsRemaining = unitsRemaining;}
  void setServingPrice(double servingPrice) {if (servingPrice >= 0) mServingPrice = servingPrice;}
  
  const string& getID() const { return mID; }
  double getPrice() { return mPrice; }
  double getLowStockThreshold() const { return mLowStockThreshold; }
  Unit::Type getUnit() const { return mUnit; }
  double getUnitsRemaining() const { return mUnitsRemaining; }
  
  double getServingPrice() const { return mServingPrice; }
  
  virtual bool hasTax() const { return false; }
  virtual double getTax(double servings) const { return 0; }
  virtual double getTax(double quantity, Unit::Type unit) const { return 0; }
  
  virtual const string& getItemType() const = 0;
  
  virtual double getUnitsPerStock() const = 0;
  virtual double getUnitsPerServing() const = 0;
  
  double getStockRemaining() const { return mUnitsRemaining / getUnitsPerStock(); }
  double getServingsRemaining() const { return mUnitsRemaining / getUnitsPerServing(); }
  bool isOutOfStock() const {return getUnitsPerServing()  - getUnitsRemaining() >= 0;}
  bool isLowStock() const {return !isOutOfStock() && getLowStockThreshold() - getStockRemaining() >= 0; }
  bool isValidOrder(double quantity) {return  getUnitsRemaining() - quantity * getUnitsPerServing() >= 0; }
  bool isValidStockLoss(double quantity) {return getStockRemaining() - quantity >= 0;}
  double placeOrder(double &cost, double quantity = 1);
  
  double addStock(double quantity);
  double loseStock(double quantity);
  bool loseUnits(double quantity);
 
  virtual void readCSV(istream &csvLine);
  virtual void writeCSV(ostream &csvLine) const;
  virtual void writeStatement(ostream &output) const;
  
  void print() const;
  void printLowStockMessaage() const;
  void printOutOfStockMessage() const;
  void printDrinkListing() const;
  void printInventoryListing() const;
  
protected:
  InventoryItem(){}
  
private:
  string mID;
  double mPrice = 0;
  double mLowStockThreshold = 1; //threshold number of containers
  Unit::Type mUnit = Unit::LAST_UNIT;
  double mUnitsRemaining = 0;
  double mServingPrice = 0;
};

double InventoryItem::placeOrder(double &cost, double quantity) {
  double totalPrice = 0;
  if (isValidOrder(quantity)) {
    totalPrice = quantity * mServingPrice + getTax(quantity);
    cost = mPrice * quantity * getUnitsPerServing() / getUnitsPerStock();
    mUnitsRemaining -= quantity * getUnitsPerServing();
  }
  return totalPrice;
}

double InventoryItem::addStock(double quantity) {
  double price = 0;
  mUnitsRemaining += quantity * getUnitsPerStock();
  price = quantity * mPrice;
  return price;
}

double InventoryItem::loseStock(double quantity) {
  bool isValid = quantity <= getStockRemaining();
  double cost = 0;
  if (isValid) {
    mUnitsRemaining -= quantity * getUnitsPerStock();
    cost = quantity * getPrice();
  }
  return cost;
}

bool InventoryItem::loseUnits(double quantity) {
  bool isValid = quantity <= mUnitsRemaining;
  if (isValid) {
    mUnitsRemaining -= quantity * getUnitsPerStock();
  }
  return isValid;
}

//virtual
void InventoryItem::writeStatement(ostream &output) const {
  const string unit = Unit::getUnitName(mUnit);
  output << "ID: " << mID << endl
  << "Purchase Price: $" << fixed << setprecision(2) << mPrice << setprecision(0)
  << " for " << getUnitsPerStock() << " " << unit << endl
  << "Serving size: " << setprecision(3) << getUnitsPerServing() << " " << unit << endl;
  if (hasTax()) {
    output << "Tax per serving: $" << setprecision(2) << getTax(1) << endl;
  }
  output << "Inventory has: " << setprecision(3) << mUnitsRemaining << ' ' << unit << endl
  << "Stock remaining: " << setprecision(3) << getStockRemaining() << endl
  << "Price per serving no tax: $" << setprecision(2) << getServingPrice() << endl;
}

void InventoryItem::print() const {
  stringstream output;
  writeStatement(output);
  cout << output.str() << endl;
}

void InventoryItem::printLowStockMessaage() const {
  cout << '\t' << mID << " - " << getServingsRemaining() << " servings remaining." << endl;
}

void InventoryItem::printOutOfStockMessage() const {
  cout << '\t' << mID << " - out of Stock" << endl;
}

void InventoryItem::printDrinkListing() const {
  cout << mID << ": $" << fixed << setprecision(2) << mServingPrice << " for "
  << setprecision(1) << Unit::convertUnits(getUnitsPerServing(), mUnit, Unit::OUNCES) << " oz" << endl;
}

void InventoryItem::printInventoryListing() const {
  if (!isOutOfStock()) {
    cout << mID << ": Stock Amount: " << getStockRemaining() << ", Servings Remaining: " << fixed << setprecision(1) << getServingsRemaining();
  }
  else {
    cout << mID << " - out of Stock ";
  }
  cout << ", Restock Price: $" << setprecision(2) << mPrice << endl;
}

//helper function for readCSV
template <typename T>
void getToken(istream &csvLine, T &value) {
  string token;
  stringstream ss;
  getline(csvLine, token, ',');
  ss.str(token);
  ss >> value;
}

//helper function for readCSV
void getToken(istream &csvLine, string &value) {
  getline(csvLine, value, ',');
}

//virtual
void InventoryItem::readCSV(istream &csvLine) {
  
  string unitName;
  
  getToken(csvLine, mID);
  getToken(csvLine, mPrice);
  getToken(csvLine, mLowStockThreshold);
  getToken(csvLine, unitName);
  getToken(csvLine, mServingPrice);
  getToken(csvLine, mUnitsRemaining);
  
  mUnit = Unit::getUnit(unitName);
}

//virtual
void InventoryItem::writeCSV(ostream &csvLine) const {
  csvLine << getItemType() << ',' << mID << ',' << fixed << setprecision(6)
          << mPrice << ','
          << mLowStockThreshold << ','
          << Unit::getUnitName(mUnit) << ','
          << mServingPrice << ','
          << mUnitsRemaining;
}

#endif /* INVENTORYITEM_H */
