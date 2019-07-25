//
//  Alcohol.h
//  CS200_FinalProject_v2
//
//  Created by Jessie Sully on 7/23/19.
//  Copyright © 2019 Jessie Sully. All rights reserved.
//

#ifndef ALCOHOL_H
#define ALCOHOL_H

#include <string>
#include <ctype.h>
using namespace std;

#include "Unit.h"

class Alcohol {
public:
  enum Type {BEER = 0, WINE, SPIRIT, LAST_TYPE};
  
  Alcohol(Type type) : mType(type) {}
  
  void setType (Type type) { mType = type; }
  Type getType() const { return mType; }
  double getExciseTax(double quantity, Unit::Type unit) const;
  
  static Type getAlcoholType(const string &type);
  static const string& getAlcoholSType(Alcohol::Type type);
  
  static double getPricePerUnit(Alcohol::Type type);
  static double getStandardServingPrice(Alcohol::Type type);
  static double getStandardPriceForOrder(Alcohol::Type type, unsigned int quantity = 1);
  static double getPriceForOrder(Alcohol::Type type, double unitsServed, unsigned int quantity = 1);
  
protected:
  Alcohol (){}
  
private:
  Type mType;
  
  static const double sExciseTaxPerGallon[];
  static const string sTypeStrings[];
  static const double sPriceForStandardServing[]; // 12oz Beer, .15L Wine, .0375L Spirit
  static const double sUnitsPerStandardServing[];
};

//static
const string Alcohol::sTypeStrings[] = { "beer", "wine", "spirit" };
//static
const double Alcohol::sExciseTaxPerGallon[] = { 18, 3.4, 13.5 };
//static
const double Alcohol::sPriceForStandardServing[] = {10.99, 14.99, 9.99};
//static
const double Alcohol::sUnitsPerStandardServing[] = {12, 0.15, 0.0375}; // beer is in oz, rest in L

//static
Alcohol::Type Alcohol::getAlcoholType(const string& type) {
  int i;
  string lower = type;
  
  for ( char &c : lower) {
    c = tolower(c);
  }
  
  for (i = 0; i < LAST_TYPE; i++) {
    if (lower == sTypeStrings[i]) break;
  }
  return static_cast<Type>(i);
}

//static
const string& Alcohol::getAlcoholSType(Alcohol::Type type) {
  return sTypeStrings[static_cast<int>(type)];
}

double Alcohol::getExciseTax(double quantity, Unit::Type unit) const {
  double gallons = convertUnits(quantity, unit, Unit::GALLONS);
  double taxPerGallon = sExciseTaxPerGallon[static_cast<int>(mType)];
  return gallons * taxPerGallon;
}

//static
double Alcohol::getPricePerUnit(Type type) {
  return sPriceForStandardServing[static_cast<int>(type)] / sUnitsPerStandardServing[static_cast<int>(type)];
}

//static
double Alcohol::getStandardServingPrice(Type type) {
  return sPriceForStandardServing[static_cast<int>(type)];
}

//static
double Alcohol::getStandardPriceForOrder(Type type, unsigned int quantity) {
  return quantity * getStandardServingPrice(type);
}

//static
double Alcohol::getPriceForOrder(Type type, double unitsServed, unsigned int quantity) {
  return quantity * unitsServed * getPricePerUnit(type);
}

#endif /* ALCOHOL_H */
