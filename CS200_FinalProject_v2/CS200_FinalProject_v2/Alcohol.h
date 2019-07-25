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
  static const string& getAlcoholSType(Type type);
  
protected:
  Alcohol (){}
  
private:
  Type mType;
  
  static const double sExciseTaxPerGallon[];
  static const string sTypeStrings[];
};

//static
const string Alcohol::sTypeStrings[] = { "beer", "wine", "spirit" };
//static
const double Alcohol::sExciseTaxPerGallon[] = { 18, 3.4, 13.5 };

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

#endif /* ALCOHOL_H */
