//
//  Ferry.h
//  Midterm
//
//  Created by Jessie Sully on 7/14/19.
//  Copyright © 2019 Jessie Sully. All rights reserved.
//

#ifndef FERRY_H
#define FERRY_H

#include "Ship.h"

/*
 -----------------------
 Ferry :: Ship
 -----------------------
 - mPassCap : unsigned int
 - mCarCap : unsigned int
 - mOrigin : string
 - mDestination : string
 - mTickPrice : double
 -----------------------
 + Ferry()
 + Ferry(registry : string, homeport : string, name : string, length : unsigned int, displacement : unsigned int, passCap : unsigned int, carCap : unsigned int, origin : string, destination : string, ticketPrice: double)
 ----------------------
 */

class Ferry : public Ship {
private:
  unsigned int mPassCap = 0;
  unsigned int mCarCap = 0;
  string mOrigin;
  string mDestination;
  double mTickPrice = 0;
  
public:
  Ferry(){};
  Ferry (const string &registry, const string &homeport, const string &name, unsigned int length, unsigned int displacement, unsigned int passCap, unsigned int carCap, const string &origin, const string &destination, double ticketPrice) :
  
      Ship(registry, homeport, name, length, displacement), mPassCap(passCap), mCarCap(carCap), mOrigin(origin), mDestination(destination), mTickPrice(ticketPrice) {}
  
  void writeStatus(stringstream &output) const;
  void print() const;
};

#endif /* FERRY_H */
