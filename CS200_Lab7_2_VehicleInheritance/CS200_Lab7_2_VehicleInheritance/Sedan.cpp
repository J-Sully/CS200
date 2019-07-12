//
//  Sedan.cpp
//  CS200_Lab7_2_VehicleInheritance
//
//  Created by Jessie Sully on 7/10/19.
//  Copyright © 2019 Jessie Sully. All rights reserved.
//

#include <iostream>

#include "Sedan.h"

Sedan::Sedan (unsigned int year, unsigned int mileage, unsigned int doors,
              bool hatchback) : Vehicle(year, mileage) {
  
  mDoors = doors;
  mHatchback = hatchback;
};

void Sedan::writeStatus(stringstream &output) const {
  Vehicle::writeStatus(output);
  output << " Doors: " << getDoors() << endl
         << " Hatchback: ";
  getHatchback() ? output << "yes" : output << "no";
  output << endl;
}

void Sedan::print() const {
  stringstream output;
  writeStatus(output);
  cout << output.str() << endl;
}

