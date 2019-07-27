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

/*
 -----------------------
 InventoryItem
 -----------------------
 - mID : string
 - mPrice : double
 - mLowStockThreshould : double
 - mUnit : Unit::Type
 - mUnitsRemaining : double
 - mServingPrice : double
 -----------------------
 # InventoryItem()
 + InventoryItem(ID : string, price : double, threshold : double,
 unit : Unit::Type, servingPrice : double, unitsRemaining : double)
 + InventoryItem(csvLine : istream)
 + ~InventoryItem()
 + readCSV (csvLine : istream) : void
 + writeCSV (csvLine : ostream) : void
 + writeStatement(ostream &output) : void
 + setID(ID : string) : void
 + setPrice(price : double) : void
 + setLowThreshold(threshold : double) : void
 + setUnit(unitName : string) : void
 + setUnitsRemaining(unitsRemaining : double) : void
 + setServingPrice(servingPrice : double) : void
 + getID() : string
 + getPrice() : double
 + getThreshould() : double
 + getUnit() : Unit::Type
 + getUnitsRemaining() : double
 + getServingPrice() : double
 + hasTax() : bool
 + getTax(servings : double) : double
 + getTax(quantity : double, unit : Unit::Type) : double
 + getItemType() : string
 + getUnitsPerStock() : double
 + getUnitsPerServing() : double
 + isOutOfStock() : bool
 + isLowStock() : bool
 + isValidOrder(quantity : double) : bool
 + isValidStockLoss(quantity : double) : bool
 + placeOrder(cose : double, quantity : double) : double
 + addStock(quantity : double) : double
 + loseStock(quantity : double) : double
 + print() : void
 + printLowStockMessage() : void
 + printOutOfStockMessage() : void
 + printDrinkListing() : void
 + printInventoryListing() : void
 ----------------------
 */

class InventoryItem {
public:
  InventoryItem(const string &ID, double price, double threshold,
                Unit::Type unit, double servingPrice, double unitsRemaining = 0) :
  mID(ID), mPrice(price), mLowStockThreshold(threshold), mUnit(unit)
  {setServingPrice(servingPrice); setUnitsRemaining(unitsRemaining);}
  
  InventoryItem(istream& csvLine) { readCSV(csvLine); }
  
  virtual ~InventoryItem() {}
  
  virtual void readCSV(istream &csvLine);
  virtual void writeCSV(ostream &csvLine) const;
  
  void setID(const string& ID)  { mID = ID; }
  void setPrice(double price) { if(price >= 0) mPrice = price; }
  void setLowStockThreshold(double threshold) { mLowStockThreshold = threshold; }
  void setUnit(const string &unitName) { mUnit = Unit::getUnit(unitName); }
  void setUnitsRemaining(double unitsRemaining) { if (unitsRemaining >= 0) mUnitsRemaining = unitsRemaining;}
  void setServingPrice(double servingPrice) {if (servingPrice >= 0) mServingPrice = servingPrice;}
  
  const string& getID() const { return mID; }
  double getPrice() { return mPrice; }
  double getLowStockThreshold() const { return mLowStockThreshold; }
  Unit::Type getUnit() const { return mUnit; }
  double getUnitsRemaining() const { return mUnitsRemaining; }
  double getServingPrice() const { return mServingPrice; }
  
  //Alcoholic items will have tax, nonalcoholic items will not. 
  virtual bool hasTax() const { return false; }
  virtual double getTax(double servings) const { return 0; }
  virtual double getTax(double quantity, Unit::Type unit) const { return 0; }
  
  virtual const string& getItemType() const = 0;
  virtual double getUnitsPerStock() const = 0;
  virtual double getUnitsPerServing() const = 0;
  
  double getStockRemaining() const { return mUnitsRemaining / getUnitsPerStock(); }
  double getServingsRemaining() const { return mUnitsRemaining / getUnitsPerServing(); }
  // Items are either out of stock OR low stock, not both.
  bool isOutOfStock() const { return getUnitsRemaining() < getUnitsPerServing(); }
  bool isLowStock() const { return !isOutOfStock() && getStockRemaining() < getLowStockThreshold(); }
  bool isValidOrder(double quantity) { return  getUnitsRemaining() >= quantity * getUnitsPerServing(); }
  bool isValidStockLoss(double quantity) { return getStockRemaining() >= quantity; }
  
  double placeOrder(double &cost, double quantity = 1);
  double addStock(double quantity);
  double loseStock(double quantity);
 
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
  << "Low Stock Threshold: " << getLowStockThreshold() << " ("
  << getLowStockThreshold() * getUnitsPerStock() << " " << unit << ")" << endl
  << "Stock remaining: " << setprecision(3) << getStockRemaining() << endl
  << "Servings remaining: " << setprecision(1) << getServingsRemaining() << endl
  << "Price per serving no tax: $" << setprecision(2) << getServingPrice() << endl;
}

void InventoryItem::print() const {
  stringstream output;
  writeStatement(output);
  cout << output.str() << endl;
}

void InventoryItem::printLowStockMessaage() const {
  cout << '\t' << mID << " - " << getServingsRemaining() <<  fixed << setprecision(3) << " servings remaining, Need " << getLowStockThreshold() - getStockRemaining() << " more stock to replenish." << endl;
}

void InventoryItem::printOutOfStockMessage() const {
  cout << '\t' << mID << " - out of Stock, Need " << fixed << setprecision(3) << getLowStockThreshold() - getStockRemaining() << " more stock to replenish." << endl;
}

void InventoryItem::printDrinkListing() const {
  cout << mID << ": $" << fixed << setprecision(2) << mServingPrice << " for "
  << setprecision(1) << Unit::convertUnits(getUnitsPerServing(), mUnit, Unit::OUNCES) << " oz" << endl;
}

void InventoryItem::printInventoryListing() const {
  if (!isOutOfStock()) {
    cout << mID << ": Stock Amount: " << getStockRemaining() << ", Servings Remaining: " << fixed << setprecision(1) << getServingsRemaining() << ", Stock Remaining: " << fixed << setprecision(3) << getStockRemaining();
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
