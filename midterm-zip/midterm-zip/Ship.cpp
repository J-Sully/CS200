//
//  Ship.cpp
//  Midterm
//
//  Created by Jessie Sully on 7/14/19.
//  Copyright © 2019 Jessie Sully. All rights reserved.
//
#include <sstream>
#include <iostream>

#include "Ship.h"

void Ship::writeStatus(stringstream &output) const {
  output << "Information for the Ship " << mName << ':' << endl
         << "\t>Registry: " << mRegistry << endl
         << "\t>Homeport: " << mHomeport << endl
         << "\t>Length: " << mLength << endl
         << "\t>Displacement: " << mDisplacement << endl;
}

void Ship::print() const {
  stringstream output;
  writeStatus(output);
  cout << output.str() << endl;
}
