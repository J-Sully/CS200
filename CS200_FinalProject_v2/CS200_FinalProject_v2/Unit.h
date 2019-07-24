//
//  Units.h
//  CS200_FinalProject_v2
//
//  Created by Jessie Sully on 7/23/19.
//  Copyright © 2019 Jessie Sully. All rights reserved.
//

#ifndef Units_hpp
#define Units_hpp

#include <string>
using namespace std;

namespace Unit {
  enum Type {LITERS = 0, OUNCES, GALLONS, LAST_UNIT};
  
  static const string sTypeString[] = {"liters", "ounces", "gallons"};
  
  static const double sConversions[][3] = {
    {1, 33.814, 0.264172}, // liters
    {0.0295735, 1, 0.0078125}, // ounces
    {3.78541, 128, 1} // gallons
  };
  
  double convertUnits(unsigned int quantity, Type fromType, Type toType) {
    return quantity * sConversions[fromType][toType];
  }
  
  Type getUnit(const string &unit) {
    int i = 0;
    for(; i < LAST_UNIT; i++ ) {
      if (unit == sTypeString[i]) break;
    }
    return static_cast<Type>(i);
  }
  
  const string& getUnitName(Type type) {
    return sTypeString[static_cast<int>(type)];
  }
}


#endif /* Units_hpp */
