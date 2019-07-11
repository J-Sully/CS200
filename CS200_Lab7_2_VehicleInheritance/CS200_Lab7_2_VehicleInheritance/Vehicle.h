//
//  Vehicle.h
//  CS200_Lab7_2_VehicleInheritance
//
//  Created by Jessie Sully on 7/10/19.
//  Copyright © 2019 Jessie Sully. All rights reserved.
//

#include <sstream>
using namespace std;

#ifndef Vehicle_h
#define Vehicle_h

/*
 -----------------------
 Vehicle
 -----------------------
 - mYear : unsigned int
 - mMileage : unsigned int
 -----------------------
 + Vehicle()
 + Vehicle(year : unsigned int, mileage : unsigned int)
 + setYear(year : unsigned int) : void
 + getYear() : unsigned int
 + setMileage(mileage : unsigned int) : void
 + getMileage() : unsigned int
 + writeStatus(output : stringstream) : void
 ----------------------
 */

class Vehicle {
  
private:
  unsigned int mYear = 0;
  unsigned int mMileage = 0;
  
public:
  Vehicle(unsigned int year, unsigned int mileage);

  void setYear (unsigned int year)     { mYear = year; }
  void setMileage(unsigned int mileage)     { mMileage = mileage; }
  
  unsigned int getYear() const  { return mYear; }
  unsigned int getMileage() const { return mMileage; }
 
  void writeStatus(stringstream &output) const;  
};

#endif /* Vehicle_h */
