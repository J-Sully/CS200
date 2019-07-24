//
//  AlcoholicItem.h
//  CS200_FinalProject_v2
//
//  Created by Jessie Sully on 7/23/19.
//  Copyright © 2019 Jessie Sully. All rights reserved.
//

#ifndef ALCOHOLICITEM_H
#define ALCOHOLICITEM_H

#include "Alcohol.h"
#include "InventoryItem.h"

class AlcoholicItem : public InventoryItem, public Alcohol {
public:
  AlcoholicItem(const string &ID, double pricePerUnit, unsigned int thresholdUnits, const string &unitPurchased, string &unitServed, const string &type, double unitsPerServing, double servingsPerBottle, double bottlesPerCase) :
  InventoryItem(ID, pricePerCase, thresholdCases, unit), Alcohol(type), mUnitsPerServing(unitsPerServing), mServingsPerBottle(servingsPerBottle), mBottlesPerCase(bottlesPerCase) {}
  
  virtual bool hasTax() const { return true; }
  virtual double getTax(double servings) const
  { return getTax(servings * getUnitsPerServing(), getUnit()); }
  
  virtual double getTax(double qty, Unit unit) const
  { return getExciseTax(qty, unit); }
  
  virtual double getUnitsPerPurchase() const { return getUnitsPerCase(); }
  
  virtual double getUnitsPerServing() const { return mUnitsPerServing; }
  double getUnitsPerBottle() const { return mUnitsPerServing * mServingsPerBottle; }
  double getUnitsPerCase() const { return mUnitsPerServing * mServingsPerBottle * mBottlesPerCase; }
  double getServingsPerBottle() const { return mServingsPerBottle; }
  double getServingsPerCase() const { return mServingsPerBottle * mBottlesPerCase; }
  double getBottlesPerCase() const { return mBottlesPerCase; }
  
  virtual void writeStatement(stringstream &output) const;
  
private:
  double mUnitsPerServing = 1;
  double mServingsPerBottle = 1;
  double mBottlesPerCase = 1;
  
};

#endif /* ALCOHOLICITEM_H */
