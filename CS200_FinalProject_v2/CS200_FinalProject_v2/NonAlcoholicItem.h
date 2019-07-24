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
  NonAlcoholicItem(const string &ID, double price, double threshold, Unit::Type unit, double unitsRemaining, double unitsPerPurchase, double unitsPerServing) :
  InventoryItem(ID, price, threshold, unit, unitsRemaining),
  mUnitsPerPurchase(unitsPerPurchase), mUnitsPerServing(unitsPerServing) {}
  
  void setUnitsPerPurchase(double unitsPerPurchase) { mUnitsPerPurchase = unitsPerPurchase; }
  void setUnitsPerServing(double unitsPerServing) { mUnitsPerServing = unitsPerServing; }
  
  virtual double getUnitsPerStock() const { return mUnitsPerPurchase; }
  virtual double getUnitsPerServing() const { return mUnitsPerServing; }
  
private:
  double mUnitsPerPurchase = 1;
  double mUnitsPerServing = 1;
};


#endif /* NONALOHOLICITEM_H */
