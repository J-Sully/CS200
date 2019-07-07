//
//  Car.h
//  CS200_Exercise_Constructors
//
//  Created by Jessie Sully on 7/5/19.
//  Copyright © 2019 Jessie Sully. All rights reserved.
//

#ifndef CAR_H
#define CAR_H

#include <string>
using namespace std;

/*
 -----------------------
 Car
 -----------------------
 - make: string
 - year : unsigned int
 -----------------------
 + Car()
 + Car(m : string)
 + Car(y : unsigned int)
 + Car(m : string, y : unsigned int)
 + setMake(m: string) : void
 + getMake() : string
 + setYear(y: unsigned int) : void
 + getYear() : unsigned int
 ----------------------
 */

class Car {
  
private:
  string make;
  unsigned int year;
  
public:
  Car();
  Car(string);
  Car(unsigned int);
  Car(string, unsigned int);
  void setMake (string m)       { make = m; }
  void setYear (unsigned int y) { year = y; }
  string getMake()              { return make; }
  unsigned int getYear()        { return year; }
};

#endif /* CAR_H */


