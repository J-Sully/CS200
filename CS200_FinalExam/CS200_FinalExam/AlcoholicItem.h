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

#include "InventoryItem.h"

using namespace std;


class Alcohol {
public:
  enum Type { BEER = 0, WINE, SPIRIT, LAST_TYPE };
  static const char* sTypeStrings[];
  static Type getAlcoholType(const string& type);
  
  Alcohol(Type type) : mType(type) {}
  
  double getExciseTax(double qty, Unit unit) const;
  
private:
  Type mType = SPIRIT;
  
  static const double sExciseTaxPerGallon[];
};

/* static */ const char* Alcohol::sTypeStrings[] = { "beer", "wine", "spirit" };
/* static */ const double Alcohol::sExciseTaxPerGallon[] = { 18, 3.4, 13.5 };

/* *NOTE: This is for *bottled* alcohol only.  Does not cover alcohol on tap */
class AlcoholicItem : public InventoryItem, public Alcohol {
public:
  AlcoholicItem(const string &ID, double pricePerCase,
                unsigned int thresholdCases, Unit unit, Alcohol::Type type,
                double unitsPerServing, double servingsPerBottle,
                double bottlesPerCase)
  : InventoryItem(ID, pricePerCase, thresholdCases, unit), Alcohol(type)
  , mUnitsPerServing(unitsPerServing), mServingsPerBottle(servingsPerBottle)
  , mBottlesPerCase(bottlesPerCase) {}
  
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
  
private:
  double mUnitsPerServing = 1;
  double mServingsPerBottle = 1;
  double mBottlesPerCase = 1;

};

class BeerItem : public AlcoholicItem {
public:
  BeerItem(const string &ID, double pricePerCase, unsigned int thresholdCases = 2,
           double unitsPerServing = 12, double bottlesPerCase = 24)
  : AlcoholicItem(ID, pricePerCase, thresholdCases, OUNCES,
                  Alcohol::BEER, unitsPerServing, 1, bottlesPerCase) {}
};

class Aged {
  Aged(unsigned int year) : mYear(year) {}
  
  void writeStatement(stringstream &output) const;
  
public:
  unsigned int mYear = 1970;
};


class AgedAlcoholicItem : public AlcoholicItem {
public:
  AgedAlcoholicItem(const string &ID, double pricePerCase, unsigned int year,
                unsigned int thresholdCases, Unit unit, Alcohol::Type type,
                double unitsPerServing, double servingsPerBottle,
                double bottlesPerCase)
  : AlcoholicItem(ID, pricePerCase, thresholdCases, unit, type,
                  unitsPerServing, servingsPerBottle, bottlesPerCase), mYear(year) {}
  
  virtual void writeStatement(stringstream &output) const;
  
private:
  unsigned int mYear = 1970;
};

/* virtual */
void AgedAlcoholicItem::writeStatement(stringstream &output) const {
  AlcoholicItem::writeStatement(output);
  output << "Year bottled: " << mYear << endl;
}

class WineItem : public AgedAlcoholicItem {
public:
  WineItem(const string &ID, double pricePerCase, unsigned int year,
           unsigned int thresholdCases = 2, double unitsPerServing = .15,
           double servingsPerBottle = 5, double bottlesPerCase = 12)
  : AgedAlcoholicItem(ID, pricePerCase, year, thresholdCases, LITERS,
                  Alcohol::WINE, unitsPerServing,
                  servingsPerBottle, bottlesPerCase) {}
};

class SpiritItem : public AgedAlcoholicItem {
public:
  SpiritItem(const string &ID, double pricePerCase, unsigned int year,
             unsigned int thresholdCases = 2, double unitsPerServing = .0375,
             double servingsPerBottle = 20, double bottlesPerCase = 12)
  : AgedAlcoholicItem(ID, pricePerCase, year, thresholdCases, LITERS,
                  Alcohol::SPIRIT, unitsPerServing,
                  servingsPerBottle, bottlesPerCase) {}
};


double Alcohol::getExciseTax(double qty, Unit unit) const {
  double gallons = convertUnits(qty, unit, GALLONS);
  double taxPerGallon = sExciseTaxPerGallon[static_cast<int>(unit)];
  return gallons * taxPerGallon;
}

/* static */
Alcohol::Type Alcohol::getAlcoholType(const string& type) {
  int i;
  for (i = 0; i < LAST_TYPE; i++) {
    // *TODO: Lowercase type string.
    if (type == sTypeStrings[i]) break;
  }
  return static_cast<Type>(i);
}

#endif /* ALCOHOLICITEM_H */
