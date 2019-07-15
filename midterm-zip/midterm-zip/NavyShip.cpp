//
//  NavyShip.cpp
//  Midterm
//
//  Created by Jessie Sully on 7/14/19.
//  Copyright © 2019 Jessie Sully. All rights reserved.
//

#include <sstream>
#include <iostream>


#include "NavyShip.h"

void NavyShip::writeStatus(stringstream &output) const {
  Ship::writeStatus(output);
  output << "\t>Type: " << mShipType << endl
  << "\t>Designation: " << mDestination << endl
  << "\t>Crew: " << mNumCrew << endl
  << "\t>Nuclear: " << (mNuclearPowered ? "Yes" : "No") << endl
  << "\t>Max Speed: " << mMaxSpeed << " mph" << endl;
}

void NavyShip::print() const {
  stringstream output;
  writeStatus(output);
  cout << "Information for the Navy Ship " << getName() << ':' << endl
  << output.str() << endl;
}
