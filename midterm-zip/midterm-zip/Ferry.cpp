//
//  Ferry.cpp
//  Midterm
//
//  Created by Jessie Sully on 7/14/19.
//  Copyright © 2019 Jessie Sully. All rights reserved.
//
#include <sstream>
#include <iostream>

#include "Ferry.h"

void Ferry::writeStatus(stringstream &output) const {
  Ship::writeStatus(output);
  output << "\t>Passenger Capacity: " << mPassCap << endl
  << "\t>Car Capacity: " << mCarCap << endl
  << "\t>Origin: " << mOrigin << endl
  << "\t>Destination: " << mDestination << endl
  << "\t>Ticket Price: " << mTickPrice << endl;
}

void Ferry::print() const {
  stringstream output;
  writeStatus(output);
  cout << output.str() << endl;
}
