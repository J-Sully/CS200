//
//  Units.h
//  CS200_FinalExam
//
//  Created by Donald Kjer on 7/23/19.
//  Copyright © 2019 Jessie Sully. All rights reserved.
//

#ifndef UNITS_H
#define UNITS_H

#include <string>

using namespace std;

enum Unit { LITERS = 0, OUNCES, GALLONS, LAST_UNIT };
static const char* UnitStrings[] = { "liters", "ounces", "gallons" };
static const double Conversions[][3] = {
  { 1, 33.814, 0.264172, }, // liters
  { 0.0295735, 1, 0.0078125 }, // ounces
  { 3.78541, 128, 1 } // gallons
};

double convertUnits(double qty, Unit fromUnit, Unit toUnit) {
  return qty * Conversions[fromUnit][toUnit];
}

Unit getUnit(const string& unit) {
  int i;
  for (i = 0; i < LAST_UNIT; i++) {
    // *TODO: Lowercase unit string.
    if (unit == UnitStrings[i]) break;
  }
  return static_cast<Unit>(i);
}

const char* getUnitName(Unit unit) {
  return UnitStrings[static_cast<int>(unit)];
}

#endif /* UNITS_H */
