//
//  Car.cpp
//  CS200_6_4_IntCarCollection
//
//  Created by Jessie Sully on 7/8/19.
//  Copyright © 2019 Jessie Sully. All rights reserved.
//

#include "Car.h"
#include <sstream>

Car::Car(string m, unsigned int y){
  make = m;
  year = y;
}

void Car::writeStatus (stringstream &output) const {
  output << "Make: " << getMake()
         << " Year: " << getYear()
         << " Speed: " << getSpeed()
         << " mph";
}
