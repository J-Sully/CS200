//
//  AlcoholicItem.h
//  CS200_FinalExam
//
//  Created by Jessie Sully on 7/22/19.
//  Copyright © 2019 Jessie Sully. All rights reserved.
//

#ifndef ALCOHOLICITEM_H
#define ALCOHOLICITEM_H

#include <string>

#include "Alcohol.h"
#include "InventoryItem.h"

using namespace std;

/* *NOTE: This is for *bottled* alcohol only.  Does not cover alcohol on tap */
class AlcoholicItem : public InventoryItem, public Alcohol {
public:
  AlcoholicItem(const string &ID, double pricePerCase,
                double thresholdCases, Unit::Type unit, Alcohol::Type type,
                double unitsPerServing, double servingsPerBottle,
                unsigned int bottlesPerCase, double unitsRemaining)
  : InventoryItem(ID, pricePerCase, thresholdCases, unit, unitsRemaining), Alcohol(type)
  , mUnitsPerServing(unitsPerServing), mServingsPerBottle(servingsPerBottle)
  , mBottlesPerCase(bottlesPerCase) {}
  
  AlcoholicItem(istream& csvLine) : Alcohol(), InventoryItem() { readCSV(csvLine); }
  
  virtual bool hasTax() const { return true; }
  virtual double getTax(double servings) const
  { return getTax(servings * getUnitsPerServing(), getUnit()); }
  
  virtual double getTax(double qty, Unit::Type unit) const
  { return getExciseTax(qty, unit); }
  
  virtual const string& getItemType() const { return getAlcoholName(getType()); }
  
  virtual double getUnitsPerStock() const { return getUnitsPerCase(); }

  virtual double getUnitsPerServing() const { return mUnitsPerServing; }
  double getUnitsPerBottle() const { return mUnitsPerServing * mServingsPerBottle; }
  double getUnitsPerCase() const { return mUnitsPerServing * mServingsPerBottle * mBottlesPerCase; }
  double getServingsPerBottle() const { return mServingsPerBottle; }
  double getServingsPerCase() const { return mServingsPerBottle * mBottlesPerCase; }
  double getBottlesPerCase() const { return mBottlesPerCase; }
  double getBottlesRemaining() const { return getUnitsRemaining() / mServingsPerBottle; }
  
  virtual bool readCSV(istream& csvLine);
  virtual void writeCSV(ostream &output) const;
  virtual void writeStatement(ostream &output) const;

protected:
  AlcoholicItem() {}
  
private:
  double mUnitsPerServing = 1;
  double mServingsPerBottle = 1;
  unsigned int mBottlesPerCase = 1;

};

/* virtual */
void AlcoholicItem::writeStatement(ostream &output) const {
  InventoryItem::writeStatement(output);
  output << "Alcohol Type: " << getAlcoholName(getType()) << endl
         << getUnitName(getUnit()) << " per serving: " << mUnitsPerServing << endl
         << "Servings per bottle: " << mServingsPerBottle << endl
         << "Bottles per case " << mBottlesPerCase << endl
         << "Bottles remaining: " << getBottlesRemaining() << endl;
}

/* virtual */
bool AlcoholicItem::readCSV(istream& csvLine) {
  bool success = InventoryItem::readCSV(csvLine);
  
  success &= readToken(csvLine, mUnitsPerServing);
  success &= readToken(csvLine, mServingsPerBottle);
  success &= readToken(csvLine, mBottlesPerCase);
  
  return success;
}

/* virtual */
void AlcoholicItem::writeCSV(ostream &output) const {
  InventoryItem::writeCSV(output);
  output << ',' << mUnitsPerServing << ','
         << mServingsPerBottle << ',' << mBottlesPerCase;
}

class BeerItem : public AlcoholicItem {
public:
  BeerItem(const string &ID, double pricePerCase, double thresholdCases = 2,
           double unitsPerServing = 12, double bottlesPerCase = 24,
           double unitsRemaining = 0)
  : AlcoholicItem(ID, pricePerCase, thresholdCases, Unit::OUNCES, Alcohol::BEER,
                  unitsPerServing, 1, bottlesPerCase, unitsRemaining) {}
  
  BeerItem(istream& csvLine) : AlcoholicItem() { readCSV(csvLine); setType(Alcohol::BEER); }
};

class AgedAlcoholicItem : public AlcoholicItem {
public:
  AgedAlcoholicItem(const string &ID, double pricePerCase, unsigned int year,
                    double thresholdCases, Unit::Type unit, Alcohol::Type type,
                    double unitsPerServing, double servingsPerBottle,
                    double bottlesPerCase, double unitsRemaining = 0)
  : AlcoholicItem(ID, pricePerCase, thresholdCases, unit, type,
                  unitsPerServing, servingsPerBottle, bottlesPerCase,
                  unitsRemaining), mYear(year) {}
  
  AgedAlcoholicItem(istream& csvLine) : AlcoholicItem() { readCSV(csvLine); }
  
  virtual bool readCSV(istream& csvLine);
  virtual void writeCSV(ostream &output) const;
  virtual void writeStatement(ostream &output) const;
  
protected:
  AgedAlcoholicItem() {}
  
private:
  unsigned int mYear = 1970;
};

/* virtual */
bool AgedAlcoholicItem::readCSV(istream& csvLine) {
  bool success = AlcoholicItem::readCSV(csvLine);
  
  success &= readToken(csvLine, mYear);
  
  return success;
}

/* virtual */
void AgedAlcoholicItem::writeCSV(ostream &output) const {
  AlcoholicItem::writeCSV(output);
  output << ',' << mYear;
}

/* virtual */
void AgedAlcoholicItem::writeStatement(ostream &output) const {
  AlcoholicItem::writeStatement(output);
  output << "Year bottled: " << mYear << endl;
}

class WineItem : public AgedAlcoholicItem {
public:
  WineItem(const string &ID, double pricePerCase, unsigned int year,
           double thresholdCases = 2, double unitsPerServing = .15,
           double servingsPerBottle = 5, double bottlesPerCase = 12,
           double unitsRemaining = 0)
  : AgedAlcoholicItem(ID, pricePerCase, year, thresholdCases, Unit::LITERS,
                  Alcohol::WINE, unitsPerServing,
                  servingsPerBottle, bottlesPerCase, unitsRemaining) {}
  
  WineItem(istream& csvLine) : AgedAlcoholicItem() { readCSV(csvLine);  setType(Alcohol::WINE); }
};

class SpiritItem : public AgedAlcoholicItem {
public:
  SpiritItem(const string &ID, double pricePerCase, unsigned int year,
             double thresholdCases = 2, double unitsPerServing = .0375,
             double servingsPerBottle = 20, double bottlesPerCase = 12,
             double unitsRemaining = 0)
  : AgedAlcoholicItem(ID, pricePerCase, year, thresholdCases, Unit::LITERS,
                  Alcohol::SPIRIT, unitsPerServing,
                  servingsPerBottle, bottlesPerCase, unitsRemaining) {}
  
  SpiritItem(istream& csvLine) : AgedAlcoholicItem() { readCSV(csvLine); setType(Alcohol::SPIRIT); }
};


#endif /* ALCOHOLICITEM_H */
