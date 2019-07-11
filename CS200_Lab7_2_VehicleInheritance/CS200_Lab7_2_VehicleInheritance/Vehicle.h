//
//  Vehicle.h
//  CS200_Lab7_2_VehicleInheritance
//
//  Created by Jessie Sully on 7/10/19.
//  Copyright © 2019 Jessie Sully. All rights reserved.
//

#ifndef Vehicle_h
#define Vehicle_h

#include <string>
using namespace std;

//increment of acceleration
const unsigned int INCACC = 5;
//increment of braking
const unsigned int INCBRAKE = 5;

/*
 -----------------------
 Vehicle
 -----------------------
 - mMake: string
 - mYear : unsigned int
 - mSpeed : unsigned int
 -----------------------
 + Vehicle(make : string, year : unsigned int)
 + setMake(make : string) : void
 + getMake() : string
 + setYear(year : unsigned int) : void
 + getYear() : unsigned int
 + setSpeed(s : unsigned int) : void
 + getSpeed() : unsigned int
 + accelerate() : void
 + brake() : void
 + writeStatus(output : stringstream) : void
 ----------------------
 */

class Vehicle {
  
private:
  string mMake;
  unsigned int mYear = 0;
  unsigned int mSpeed = 0;
  
public:
  Vehicle(const string &make, unsigned int year);
  
  void setMake (const string &make) { mMake = make; }
  void setYear (unsigned int year)     { mYear = year; }
  void setSpeed(unsigned int speed)     { mSpeed = speed; }
  
  const string& getMake() const { return mMake; }
  unsigned int getYear() const  { return mYear; }
  unsigned int getSpeed() const { return mSpeed; }
  
  void accelerate() { mSpeed += INCACC; }
  void brake()      { mSpeed = mSpeed >= INCBRAKE ? mSpeed - INCBRAKE : 0; }
  
  void writeStatus(stringstream &output) const;
  
};

#endif /* Vehicle_h */
