//
//  Sedan.cpp
//  CS200_Lab7_2_VehicleInheritance
//
//  Created by Jessie Sully on 7/10/19.
//  Copyright © 2019 Jessie Sully. All rights reserved.
//

#include <iostream>

#include "Sedan.h"

void Sedan::writeStatus(stringstream &output) const {
  Vehicle::writeStatus(output);
  output << " Doors: " << getDoors() << endl
         << " Hatchback: " << (getHatchback() ? "yes" : "no") << endl;
}

void Sedan::print() const {
  stringstream output;
  writeStatus(output);
  cout << output.str() << endl;
}

