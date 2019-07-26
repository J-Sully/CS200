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

/*
 -----------------------
 AlcoholicItem : InventoryItem, Alcohol
 -----------------------
 - mUnitsPerServing : double
 - mServingsPerBottle : double
 - mBottlesPerCase : double
 -----------------------
 # AlcoholicItem()
 + AlcoholicItem(ID : string, pricePerCase : double, thresholdCases : double,
 unit : Unit::Type , servingPrice : double, unitsRemaining : double,
 type : Alcohol::Type, unitsPerServing: double, servingsPerBottle : double,
 bottlesPerCase : double)
 + AlcoholicItem(csvLine : istream)
 + readCSV (csvLine : istream) : void
 + writeCSV (csvLine : ostream) : void
 + writeStatement(ostream &output) : void
 + hasTax() : bool
 + getTax(servings : double) : double
 + getTax(quantity : double, unit : Unit::Type) : double
 + getItemType() : string
 + getUnitsPerStock() : double
 + getUnitsPerServing() : double
 + getServingsPerBottle() : double
 + getBottlesPerCase() : double
 + getUnitsPerBottle() : double
 + getUnitsPerCase() : double
 + setUnitsPerServing(unitsPerServing : double) : void
 + setServingsPerBottle(servingsPerBottle : double) : void
 + setBottlesPerCase(bottlesPerCase : double) : void
 ----------------------
 */

class AlcoholicItem : public InventoryItem, public Alcohol {
public:
  AlcoholicItem(const string &ID, double pricePerCase, double thresholdCases,
                double servingPrice, double unitsRemaining, Unit::Type unit,
                Alcohol::Type type, double unitsPerServing, double servingsPerBottle,
                double bottlesPerCase) :
  InventoryItem(ID, pricePerCase, thresholdCases, unit, servingPrice, unitsRemaining),
  Alcohol(type), mUnitsPerServing(unitsPerServing), mServingsPerBottle(servingsPerBottle),
  mBottlesPerCase(bottlesPerCase) {}
  
  AlcoholicItem(istream &csvLine) : InventoryItem(), Alcohol() { readCSV(csvLine); }
  
  virtual void readCSV(istream &csvLine);
  virtual void writeCSV(ostream &csvLine) const;
  virtual void writeStatement(ostream &output) const;
  
  virtual bool hasTax() const { return true; }
  virtual double getTax(double servings) const
    { return getExciseTax(servings * getUnitsPerServing(), getUnit()); }
  virtual double getTax(double quantity, Unit::Type unit) const
    { return getExciseTax(quantity, unit); }
  
  virtual const string& getItemType() const { return getAlcoholSType(getType()); }
  virtual double getUnitsPerStock() const { return getUnitsPerCase(); }
  virtual double getUnitsPerServing() const { return mUnitsPerServing; }
  
  double getServingsPerBottle() const { return mServingsPerBottle; }
  double getBottlesPerCase() const { return mBottlesPerCase; }
  double getUnitsPerBottle() const { return mUnitsPerServing * mServingsPerBottle; }
  double getUnitsPerCase() const { return getUnitsPerBottle() * mBottlesPerCase; }
  
  void setUnitsPerServing(double unitsPerServing)
    { if (unitsPerServing > 0) mUnitsPerServing = unitsPerServing; }
  void setServingsPerBottle(double servingsPerBottle)
    { if (servingsPerBottle > 0) mServingsPerBottle = servingsPerBottle; }
  void setBottlesPerCase (double bottlesPerCase)
    { if (bottlesPerCase > 0) mBottlesPerCase = bottlesPerCase; }
  
protected:
  AlcoholicItem() {}
  
private:
  double mUnitsPerServing = 1;
  double mServingsPerBottle = 1;
  double mBottlesPerCase = 1;
  
};

//virtual
void AlcoholicItem::readCSV(istream &csvLine) {
  InventoryItem::readCSV(csvLine);
  getToken(csvLine, mUnitsPerServing);
  getToken(csvLine, mServingsPerBottle);
  getToken(csvLine, mBottlesPerCase);
}

//virtual
void AlcoholicItem::writeCSV(ostream &csvLine) const {
  InventoryItem::writeCSV(csvLine);
  csvLine << ',' << mUnitsPerServing
          << ',' << mServingsPerBottle
          << ',' << mBottlesPerCase;
}

//virtual
void AlcoholicItem::writeStatement(ostream &output) const {
  output << "Alcohol Type: " << getAlcoholSType(getType()) << endl;
  InventoryItem::writeStatement(output);
  output << getUnitName(getUnit()) << " per serving: " << mUnitsPerServing << endl
  << "Servings per bottle: " << mServingsPerBottle << endl
  << "Bottles per case " << mBottlesPerCase << endl;
  
}

#endif /* ALCOHOLICITEM_H */
