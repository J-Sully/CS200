//
//  Sedan.cpp
//  CS200_Lab7_2_VehicleInheritance
//
//  Created by Jessie Sully on 7/10/19.
//  Copyright © 2019 Jessie Sully. All rights reserved.
//

#include "Sedan.h"

Sedan::Sedan (unsigned int year, unsigned int mileage, unsigned int doors,
              bool hatchback) : Vehicle(year, mileage) {
  
  mDoors = doors;
  mHatchback = hatchback;
};

void Sedan::print(stringstream &output) {
  writeStatus(output);
  output << "Number of doors: " << getDoors() << endl
         << "This car is";
  getHatchback() ? output << " not " : output << ' ';
  output << "a hatchback sedan" << endl;
}
