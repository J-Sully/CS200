//
//  Car.h
//  CS200_6_4_IntCarCollection
//
//  Created by Jessie Sully on 7/8/19.
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
 - make: string
 - year : unsigned int
 - speed : unsigned int
 -----------------------
 + Car()
 + setMake(m : string) : void
 + getMake() : string
 + setYear(y : int) : void
 + getYear() : int
 + setSpeed(s : int) : void
 + getSpeed() : int
 + accelerate() : void
 + writeStatus(ss : stringstream) : void
 ----------------------
 */

class Car {
  
private:
  string make;
  int year;
  double speed = 0;
  
public:
  Car(string make, unsigned int year);
  void setMake (const string& m){ make = m; }
  void setYear (unsigned int y) { year = y; }
  void setSpeed(unsigned int s) { speed = s; }
  const string& getMake() const { return make; }
  unsigned int getYear() const  { return year; }
  unsigned int getSpeed() const { return speed; }
  void accelerate()             { speed += 5; }
  void brake()                  { speed = speed - 5 >= 0 ? speed - 5 : 0; }
  void writeStatus(stringstream &output) const;
  
};

#endif /* Car_h */
