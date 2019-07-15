//
//  NavyShip.h
//  Midterm
//
//  Created by Jessie Sully on 7/14/19.
//  Copyright © 2019 Jessie Sully. All rights reserved.
//

#ifndef NAVYSHIP_H
#define NAVYSHIP_H

#include "Ship.h"

/*
 -----------------------
 NavyShip :: Ship
 -----------------------
 - mShipType : string
 - mDestination : string
 - mNumCrew : unsigned int
 - mNuclearPowered : bool
 - mMaxSpeed : unsigned int

 -----------------------
 + NavyShip()
 + NavyShip(registry : string, homeport : string, name : string, length : unsigned int, displacement : unsigned int, shipType : string, destination : string, numCrew : unsigned int, nuclearPowered : bool, maxSpeed: unsigned int)
 ----------------------
 */

class NavyShip : public Ship {
private:
  string mShipType;
  string mDestination;
  unsigned int mNumCrew = 0;
  bool mNuclearPowered = false;
  unsigned int mMaxSpeed = 0;
  
public:
  NavyShip(){};
  NavyShip (const string &registry, const string &homeport, const string &name, unsigned int length, unsigned int displacement, const string &shipType, const string &destination, unsigned int numCrew, bool nuclearPowered, unsigned int maxSpeed) :
      Ship(registry, homeport, name, length, displacement), mShipType(shipType),
      mDestination(destination), mNumCrew(numCrew), mNuclearPowered(nuclearPowered),
      mMaxSpeed(maxSpeed) {}
  
  void writeStatus(stringstream &output) const;
  void print() const;
};

#endif /* NAVYSHIP_H */
