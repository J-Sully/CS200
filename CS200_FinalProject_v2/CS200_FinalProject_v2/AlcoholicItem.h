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
#include "Unit.h"

class AlcoholicItem : public InventoryItem, public Alcohol {
public:
  AlcoholicItem(const string &ID, double pricePerCase, double thresholdCases, Unit::Type unit, double unitsRemaining, Alcohol::Type type, double unitsPerServing, double servingsPerBottle, double bottlesPerCase) :
  InventoryItem(ID, pricePerCase, thresholdCases, unit, unitsRemaining), Alcohol(type),
  mUnitsPerServing(unitsPerServing), mServingsPerBottle(servingsPerBottle),
  mBottlesPerCase(bottlesPerCase) {}
  
  virtual bool hasTax() const { return true; }
  virtual double getTax(double servings) const
    { return getTax(servings * getUnitsPerServing(), getUnit()); }
  
  virtual double getTax(double quantity, Unit::Type unit) const
    { return getExciseTax(quantity, unit); }
  
  double getServingsPerBottle() const { return mServingsPerBottle; }
  double getBottlesPerCase() const { return mBottlesPerCase; }
  
  double getUnitsPerBottle() const { return mUnitsPerServing * mServingsPerBottle; }
  double getUnitsPerCase() const { return getUnitsPerBottle() * mBottlesPerCase; }
  double getServingsPerCase() const { return mServingsPerBottle * mBottlesPerCase; }
  
  virtual double getUnitsPerStock() const { return getUnitsPerCase(); }
  virtual double getUnitsPerServing() const { return mUnitsPerServing; }
  
  virtual void writeStatement(stringstream &output) const;
  
private:
  double mUnitsPerServing = 1;
  double mServingsPerBottle = 1;
  unsigned int mBottlesPerCase = 1;
  
};

//virtual
void AlcoholicItem::writeStatement(stringstream &output) const {
  output << "Alcohol Type: " << getAlcoholSType(getType()) << endl;
  InventoryItem::writeStatement(output);
  output << getUnitName(getUnit()) << " per serving: " << mUnitsPerServing << endl
  << "Servings per bottle: " << mServingsPerBottle << endl
  << "Bottles per case " << mBottlesPerCase << endl;
  
}

#endif /* ALCOHOLICITEM_H */
