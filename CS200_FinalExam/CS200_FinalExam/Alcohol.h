//
//  Alcohol.h
//  CS200_FinalExam
//
//  Created by Donald Kjer on 7/23/19.
//  Copyright © 2019 Jessie Sully. All rights reserved.
//

#ifndef ALCOHOL_H
#define ALCOHOL_H

#include <string>

#include "Units.h"

class Alcohol {
public:
  enum Type { BEER = 0, WINE, SPIRIT, LAST_TYPE };
  static const char* sTypeStrings[];
  static Type getAlcoholType(const string& type);
  static const char* getAlcoholName(Type type);
  
  Alcohol(Type type) : mType(type) {}
  
  Type getType() const { return mType; }
  double getExciseTax(double qty, Unit unit) const;
  
private:
  Type mType = SPIRIT;
  
  static const double sExciseTaxPerGallon[];
};

/* static */ const char* Alcohol::sTypeStrings[] = { "beer", "wine", "spirit" };
/* static */ const double Alcohol::sExciseTaxPerGallon[] = { 18, 3.4, 13.5 };

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

/* static */
const char* Alcohol::getAlcoholName(Alcohol::Type type) {
  return sTypeStrings[static_cast<int>(type)];
}

#endif /* ALCOHOL_H */
