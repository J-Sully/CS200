//
//  AgedAlcoholicItem.h
//  CS200_FinalProject_v2
//
//  Created by Jessie Sully on 7/24/19.
//  Copyright © 2019 Jessie Sully. All rights reserved.
//

#ifndef AgedAlcoholicItem_hpp
#define AgedAlcoholicItem_hpp

#include "AlcoholicItem.h"
#include "Unit.h"

class AgedAlcoholicItem : public AlcoholicItem {
public:
  AgedAlcoholicItem(const string &ID, double pricePerCase, unsigned int year, double thresholdCases, Unit::Type unit, double servingPrice, double unitsRemaining, Alcohol::Type type, double unitsPerServing, double servingsPerBottle, double bottlesPerCase) :
  AlcoholicItem(ID, pricePerCase, thresholdCases, unit, servingPrice, unitsRemaining, type, unitsPerServing, servingsPerBottle, bottlesPerCase), mYear(year) {}
  
  AgedAlcoholicItem(istream &csvLine) : AlcoholicItem() { readCSV(csvLine); }
  
  virtual void readCSV(istream &csvLine);
  virtual void writeCSV(ostream &output) const;
  virtual void writeStatement(ostream &output) const;
  
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

#endif /* AgedAlcoholicItem_hpp */
