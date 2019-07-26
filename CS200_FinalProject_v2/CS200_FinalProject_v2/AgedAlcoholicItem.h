//
//  AgedAlcoholicItem.h
//  CS200_FinalProject_v2
//
//  Created by Jessie Sully on 7/24/19.
//  Copyright © 2019 Jessie Sully. All rights reserved.
//

#ifndef AGEDALCOHOLICITEM_H
#define AGEDALCOHOLICITEM_H

#include "AlcoholicItem.h"
#include "Unit.h"

/*
-----------------------
AgedAlcoholicItem : AlcoholicItem
-----------------------
- mItems : vector<InventoryItem*>
-----------------------
# AgedAlcoholicItem()
 + AgedAlcoholicItem(ID : string, pricePerCase : double, year : unsigned int,
 thresholdCases : double, unit : Unit::Type , servingPrice : double,
 unitsRemaining : double, type : Alcohol::Type, unitsPerServing: double,
 servingsPerBottle : double, bottlesPerCase : double)
+ AgedAlcoholicItem(csvLine : istream)
+ readCSV (csvLine : istream) : void
+ writeCSV (csvLine : ostream) : void
+ writeStatement(ostream &output) : void
+ setYear(year : unsigned int) : void
+ getYear() : unsigned int
----------------------
*/

class AgedAlcoholicItem : public AlcoholicItem {
public:
  AgedAlcoholicItem(const string &ID, double pricePerCase, unsigned int year,
                    double thresholdCases, Unit::Type unit, double servingPrice,
                    double unitsRemaining, Alcohol::Type type, double unitsPerServing,
                    double servingsPerBottle, double bottlesPerCase) :
  AlcoholicItem(ID, pricePerCase, thresholdCases, servingPrice, unitsRemaining,
                unit, type, unitsPerServing, servingsPerBottle, bottlesPerCase),
mYear(year) {}
  
  AgedAlcoholicItem(istream &csvLine) : AlcoholicItem() { readCSV(csvLine); }
  
  virtual void readCSV(istream &csvLine);
  virtual void writeCSV(ostream &output) const;
  virtual void writeStatement(ostream &output) const;
  
  void setYear(unsigned int year) { mYear = year; }
  
  unsigned int getYear() const { return mYear; }
  
protected:
  AgedAlcoholicItem(){}
  
private:
  unsigned int mYear = 1900;
};

//virtual
void AgedAlcoholicItem::readCSV(istream &csvLine) {
  AlcoholicItem::readCSV(csvLine);
  getToken(csvLine, mYear);
}

//virtual
void AgedAlcoholicItem::writeCSV(ostream &csvLine) const {
  AlcoholicItem::writeCSV(csvLine);
  csvLine << ',' << mYear;
}

// virtual
void AgedAlcoholicItem::writeStatement(ostream &output) const {
  AlcoholicItem::writeStatement(output);
  output << "Year bottled: " << mYear << endl;
}

#endif /* AGEDALCOHOLICITEM_H */
