//
//  Vehicle.cpp
//  CS200_Lab7_2_VehicleInheritance
//
//  Created by Jessie Sully on 7/10/19.
//  Copyright © 2019 Jessie Sully. All rights reserved.
//

#include "Vehicle.h"

#include <sstream>

Vehicle::Vehicle(unsigned int year, unsigned int mileage){
  mYear = year;
  mMileage = mileage;
}

void Vehicle::writeStatus (stringstream &output) const {
  output << " Year: " << getYear()
         << " Mileage: " << getMileage() << " mph";
}
