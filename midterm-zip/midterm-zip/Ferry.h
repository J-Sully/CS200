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
 + setPassCap (passCap : unsigned int) : void
 + setCarCap (carCap : unsigned int) : void
 + setOrigin (origin : string) : void
 + setDestination (destination : string) : void
 + setTicketPrice (ticketPrice : double) : void
 + getPassCap() : unsigned int
 + getCarCap() : unsigned int
 + getOrigin() : string
 + getDestination() : string
 + getTicketPrice() : double
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
  
  void setPassCap (unsigned int passCap)          { mPassCap = passCap; }
  void setCarCap (unsigned int carCap)            { mCarCap = carCap; }
  void setOrigin (const string &origin)           { mOrigin = origin; }
  void setDestination (const string &destination) { mDestination = destination; }
  void setTicketPrice (double ticketPrice)        { mTickPrice = ticketPrice; }
  
  unsigned int getPassCap() const      { return mPassCap; }
  unsigned int getCarCap() const       { return mCarCap; }
  const string& getOrigin() const      { return mOrigin; }
  const string& getDestination() const { return mDestination; }
  double getTicketPrice() const        { return mTickPrice; }
  
  void writeStatus(stringstream &output) const;
  void print() const;
};

#endif /* FERRY_H */
