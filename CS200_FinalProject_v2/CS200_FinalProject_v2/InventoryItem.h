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
  InventoryItem(const string &ID, double price, double threshold, Unit::Type unit, double unitsRemaining) : mID(ID), mPrice(price), mLowStockThreshold(threshold), mUnit(unit), mUnitsRemaining(unitsRemaining) {}
  
  void setLowStockThreshold(double threshold) { mLowStockThreshold = threshold; }
  void setID(const string& ID)  { mID = ID; }
  void setPrice(double price) { if(price >= 0) mPrice = price; }
  void setUnitsRemaining(double unitsRemaining) { if (unitsRemaining >= 0) mUnitsRemaining = unitsRemaining;}
  
  const string& getID() const { return mID; }
  double getPrice() { return mPrice; }
  double getLowStockThreshold() const { return mLowStockThreshold; }
  Unit::Type getUnit() const { return mUnit; }
  double getUnitsRemaining() const { return mUnitsRemaining; }
  
  virtual bool hasTax() const { return false; }
  virtual double getTax(double servings) const { return 0; }
  virtual double getTax(double quantity, Unit::Type unit) const { return 0; }
  
  virtual double getUnitsPerStock() const = 0;
  virtual double getUnitsPerServing() const = 0;
  
  double getStockRemaining() const { return mUnitsRemaining / getUnitsPerStock(); }
  virtual void writeStatement(stringstream &output) const;
  void print() const;
  
private:
  string mID;
  double mPrice = 0;
  double mLowStockThreshold = 1; //threshold number of containers
  Unit::Type mUnit = Unit::LAST_UNIT;
  double mUnitsRemaining = 0;
};

//virtual
void InventoryItem::writeStatement(stringstream &output) const {
  const string unit = Unit::getUnitName(mUnit);
  output << "ID: " << mID << endl
  << "Purchase Price: $" << fixed << setprecision(2) << mPrice << setprecision(0)
  << " for " << getUnitsPerStock() << " " << unit << endl
  << "Serving size: " << setprecision(3) << getUnitsPerServing() << " " << unit << endl;
  if (hasTax()) {
    output << "Tax per serving: $" << setprecision(2) << getTax(1) << endl;
  }
  output << "Inventory has: " << setprecision(3) << mUnitsRemaining << ' ' << unit << endl
  << "Stock remaining: " << setprecision(3) << getStockRemaining() << endl;
}

void InventoryItem::print() const {
  stringstream output;
  writeStatement(output);
  cout << output.str() << endl;
}

#endif /* INVENTORYITEM_H */
