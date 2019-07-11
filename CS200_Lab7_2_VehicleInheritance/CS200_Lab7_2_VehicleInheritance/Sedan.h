//
//  Sedan.h
//  CS200_Lab7_2_VehicleInheritance
//
//  Created by Jessie Sully on 7/10/19.
//  Copyright © 2019 Jessie Sully. All rights reserved.
//

#ifndef Sedan_h
#define Sedan_h

#include <sstream>
using namespace std;

#include "Vehicle.h"

/*
 -----------------------
 Sedan :: Vehicle
 -----------------------
 - mDoors : unsigned int
 - mHatchback : bool
 -----------------------
 + Sedan()
 + Seday(year : unsigned int, mileage : unsigned int, doors : unsigned int, hatchback : bool)
 + setDoors(doors : unsigned int) : void
 + getDoors() : unsigned int
 + setHatchback(hatchback : bool) : void
 + getHatchback() : bool
 + print(output : stringstream) : void
 ----------------------
 */

class Sedan : Vehicle {
private:
  unsigned int mDoors = 4;
  bool mHatchback = false;

public:
  Sedan();
  Sedan (unsigned int year, unsigned int mileage, unsigned int doors, bool hatchback);
  
  void setDoors (unsigned int doors) { mDoors = doors; }
  void setHatchback (bool hatchback) { mHatchback = hatchback; }
  
  unsigned int getDoors() { return mDoors; }
  bool getHatchback() {return mHatchback; }
  
  void print(stringstream &output);
};

#endif /* Sedan_h */
