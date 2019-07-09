//
//  Car.cpp
//  CS200_6_3_InteractiveCar
//
//  Created by Jessie Sully on 7/7/19.
//  Copyright © 2019 Jessie Sully. All rights reserved.
//

#include "Car.h"
#include <sstream>

Car::Car(const string &make, unsigned int year){
  mMake = make;
  mYear = year;
}

void Car::writeStatus (stringstream &output) const {
  output << "Make: " << getMake()
         << " Year: " << getYear()
         << " Speed: " << getSpeed() << " mph";
}

