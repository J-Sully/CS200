//
//  Car.h
//  CS200_6_3_InteractiveCar
//
//  Created by Jessie Sully on 7/7/19.
//  Copyright © 2019 Jessie Sully. All rights reserved.
//

#ifndef Car_h
#define Car_h

#include <string>
using namespace std;

/*
 -----------------------
 Car
 -----------------------
 - mMake: string
 - mYear : unsigned int
 - mSpeed : unsigned int
 -----------------------
 + Car(make : string, year : unsigned int)
 + setMake(make : string) : void
 + getMake() : string
 + setYear(year : unsigned int) : void
 + getYear() : unsigned int
 + setSpeed(speed : unsigned int) : void
 + getSpeed() : unsigned int
 + accelerate() : void
 + brake() : void
 + writeStatus(output : stringstream) : void
 ----------------------
 */

class Car {
  
private:
  string mMake;
  unsigned int mYear = 0;
  unsigned int mSpeed = 0;
  
public:
  Car(const string &make, unsigned int year);
  
  void setMake (const string &make) { mMake = make; }
  void setYear (unsigned int year)  { mYear = year; }
  void setSpeed(unsigned int speed) { mSpeed = speed; }
  
  const string& getMake() const { return mMake; }
  unsigned int getYear() const  { return mYear; }
  unsigned int getSpeed() const { return mSpeed; }
  
  void accelerate() { mSpeed += 5; }
  void brake()      { mSpeed = mSpeed >= 5 ? mSpeed - 5 : 0; }
  
  void writeStatus(stringstream &output) const;
  
};

#endif /* Car_h */

