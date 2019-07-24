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

#include "Unit.h"

class Alcohol {
public:
  enum Type { BEER = 0, WINE, SPIRIT, LAST_TYPE };
  
  Alcohol() {}
  Alcohol(Type type) : mType(type) {}
  
  Type getType() const { return mType; }
  void setType(Type type) { mType = type; }
  double getExciseTax(double qty, Unit::Type unit) const;
  
  static Type getAlcoholType(const string& type);
  static const string& getAlcoholName(Type type);

private:
  Type mType = SPIRIT;
  
  static const string sTypeStrings[];
  static const double sExciseTaxPerGallon[];
};

/* static */ const string Alcohol::sTypeStrings[] = { "beer", "wine", "spirit" };
/* static */ const double Alcohol::sExciseTaxPerGallon[] = { 18, 3.4, 13.5 };

double Alcohol::getExciseTax(double qty, Unit::Type unit) const {
  double gallons = convertUnits(qty, unit, Unit::GALLONS);
  double taxPerGallon = sExciseTaxPerGallon[static_cast<int>(mType)];
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
const string& Alcohol::getAlcoholName(Alcohol::Type type) {
  return sTypeStrings[static_cast<int>(type)];
}

#endif /* ALCOHOL_H */
