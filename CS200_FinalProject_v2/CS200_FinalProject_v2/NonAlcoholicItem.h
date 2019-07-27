//
//  NonAlcoholicItem.h
//  CS200_FinalProject_v2
//
//  Created by Jessie Sully on 7/23/19.
//  Copyright © 2019 Jessie Sully. All rights reserved.
//

#ifndef NONALOHOLICITEM_H
#define NONALOHOLICITEM_H

#include "InventoryItem.h"

/*
 -----------------------
 NonAlcoholicItem : InventoryItem
 -----------------------
 - mUnitsPerServing : double
 - mUnitsPerStock : double
 -----------------------
 + ItemType : string
 + NonAlcoholicItem(ID : string, pricePerStock : double, thresholdStock : double,
 unit : Unit::Type , servingPrice : double, unitsPerStock : double,
 unitsPerServing: double, unitsRemaining : double)
 + NonAlcoholicItem(csvLine : istream)
 + NonAlcoholicItem::ItemType = "non-alcoholic"
 + readCSV (csvLine : istream) : void
 + writeCSV (csvLine : ostream) : void
 + setUnitsPerStock(unitsPerStock : double) : void
 + setUnitsPerServing(unitsPerServing : double) : void
 + getUnitsPerStock() : double
 + getUnitsPerServing() : double
 ----------------------
 */

class NonAlcoholicItem : public InventoryItem {
public:
  static const string ItemType;
  
  NonAlcoholicItem(const string &ID, double pricePerStock, double thresholdStock, Unit::Type unit, double servingPrice, double unitsPerStock, double unitsPerServing, double unitsRemaining = 0) :
  InventoryItem(ID, pricePerStock, thresholdStock, unit, servingPrice, unitsRemaining),
  mUnitsPerStock(unitsPerStock), mUnitsPerServing(unitsPerServing) {}
  
  NonAlcoholicItem(istream &csvLine) : InventoryItem() { readCSV(csvLine); }
  
  virtual void readCSV(istream &csvLine);
  virtual void writeCSV(ostream &csvLine) const;
  virtual const string& getItemType() const { return ItemType; }
  
  void setUnitsPerStock(double unitsPerStock)
    { if (unitsPerStock > 0) mUnitsPerStock = unitsPerStock; }
  void setUnitsPerServing(double unitsPerServing)
    { if (unitsPerServing > 0) mUnitsPerServing = unitsPerServing; }
  
  virtual double getUnitsPerStock() const { return mUnitsPerStock; }
  virtual double getUnitsPerServing() const { return mUnitsPerServing; }

private:
  double mUnitsPerStock = 1;
  double mUnitsPerServing = 1;
};

//static
const string NonAlcoholicItem::ItemType = "non-alcoholic";

//virtual
void NonAlcoholicItem::readCSV(istream &csvLine) {
  InventoryItem::readCSV(csvLine);
  getToken(csvLine, mUnitsPerStock);
  getToken(csvLine, mUnitsPerServing);
}

//virtual 
void NonAlcoholicItem::writeCSV(ostream &csvLine) const {
  InventoryItem::writeCSV(csvLine);
  csvLine << ',' << mUnitsPerStock << ',' << mUnitsPerServing;
}


#endif /* NONALOHOLICITEM_H */
