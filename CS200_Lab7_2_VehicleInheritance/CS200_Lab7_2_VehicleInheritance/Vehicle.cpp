//
//  Vehicle.cpp
//  CS200_Lab7_2_VehicleInheritance
//
//  Created by Jessie Sully on 7/10/19.
//  Copyright © 2019 Jessie Sully. All rights reserved.
//

#include "Vehicle.h"

#include <sstream>

Vehicle::Vehicle(const string &make, unsigned int year){
  mMake = make;
  mYear = year;
}

void Vehicle::writeStatus (stringstream &output) const {
  output << "Make: " << getMake()
  << " Year: " << getYear()
  << " Speed: " << getSpeed() << " mph";
}
