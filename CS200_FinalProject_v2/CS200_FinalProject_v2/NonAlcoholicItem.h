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

class NonAlcoholicItem : public InventoryItem {
public:
  static const string ItemType;
  
  NonAlcoholicItem(const string &ID, double price, double threshold, Unit::Type unit, double servingPrice, double unitsPerStock, double unitsPerServing, double unitsRemaining = 0) :
  InventoryItem(ID, price, threshold, unit, servingPrice, unitsRemaining),
  mUnitsPerStock(unitsPerStock), mUnitsPerServing(unitsPerServing) {}
  
  NonAlcoholicItem(istream &csvLine) : InventoryItem() { readCSV(csvLine); }
  
  void setUnitsPerStock(double unitsPerStock) { mUnitsPerStock = unitsPerStock; }
  void setUnitsPerServing(double unitsPerServing) { mUnitsPerServing = unitsPerServing; }
  
  virtual double getUnitsPerStock() const { return mUnitsPerStock; }
  virtual double getUnitsPerServing() const { return mUnitsPerServing; }
  
  virtual void readCSV(istream &csvLine);
  virtual void writeCSV(ostream &csvLine) const;
  virtual const string& getItemType() const { return ItemType; }
  
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
