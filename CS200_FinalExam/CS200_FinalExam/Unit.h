//
//  Unit.h
//  CS200_FinalExam
//
//  Created by Donald Kjer on 7/23/19.
//  Copyright © 2019 Jessie Sully. All rights reserved.
//

#ifndef UNIT_H
#define UNIT_H

#include <string>

using namespace std;

namespace Unit {

  enum Type { LITERS = 0, OUNCES, GALLONS, LAST_UNIT };
  static const string sTypeStrings[] = { "liters", "ounces", "gallons" };
  static const double sConversions[][3] = {
    { 1, 33.814, 0.264172, }, // liters
    { 0.0295735, 1, 0.0078125 }, // ounces
    { 3.78541, 128, 1 } // gallons
  };

  double convertUnits(double qty, Type fromUnit, Type toUnit) {
    return qty * sConversions[fromUnit][toUnit];
  }

  Type getUnit(const string& unit) {
    int i;
    for (i = 0; i < LAST_UNIT; i++) {
      // *TODO: Lowercase unit string.
      if (unit == sTypeStrings[i]) break;
    }
    return static_cast<Type>(i);
  }

  const string& getUnitName(Type unit) {
    return sTypeStrings[static_cast<int>(unit)];
  }
  
};

#endif /* UNIT_H */
