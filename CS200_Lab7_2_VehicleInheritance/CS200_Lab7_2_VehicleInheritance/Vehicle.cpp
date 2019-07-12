//
//  Vehicle.cpp
//  CS200_Lab7_2_VehicleInheritance
//
//  Created by Jessie Sully on 7/10/19.
//  Copyright © 2019 Jessie Sully. All rights reserved.
//

#include "Vehicle.h"

#include <iostream>

void Vehicle::writeStatus (stringstream &output) const {
  output << " Year: " << getYear() << endl
         << " Mileage: " << getMileage() << endl;
}

void Vehicle::print() const {
  stringstream output;
  writeStatus(output);
  cout << output.str() << endl;
}
