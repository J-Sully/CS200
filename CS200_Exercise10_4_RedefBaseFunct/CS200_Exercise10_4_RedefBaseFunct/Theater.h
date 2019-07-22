//
//  Theater.h
//  CS200_Exercise10_4_RedefBaseFunct
//
//  Created by Jessie Sully on 7/22/19.
//  Copyright © 2019 Jessie Sully. All rights reserved.
//

#ifndef THEATER_H
#define THEATER_H

#include <string>
#include <iomanip>
#include <sstream>
#include <iostream>
using namespace std;

#include "Venue.h"

/*
 -----------------------
 Theater : Venue
 -----------------------
 - mName : string
 - mAddress : string // I didn't really want to split out the address to different variables
 - mAvgConcessionSales : double
 -----------------------
 + Theater()
 + Theater(type : string, year : unsigned int, capacity : unsigned int, basePrice : double, name: string, address : string, avgConcessionSales : double)
 + setName (name : string) : void
 + setAddress (address : string) : void
 + setAvgConcessionSales (avgConcessionSales : double) : void
 + getName() : string
 + getAddress() : string
 + getAvgConcessionSales() : double
 + getPotRevue() : double
 + writeStatement(output : stringstream) : void
 + print() : void
 ----------------------
 */

class Theater : public Venue {
private:
  string mName;
  string mAddress;
  double mAvgConcessionSales = 0;
  
public:
  Theater() {}
  Theater(const string &type, unsigned int year, unsigned int capacity, double basePrice,
          const string &name, const string &address, double avgConcessionSales) :
          Venue(type, year, capacity, basePrice), mName(name), mAddress(address) { setAvgConcessionSales(avgConcessionSales); }
  
  void setName (const string &name)       { mName = name; }
  void setAddress (const string &address) { mAddress = address; }
  void setAvgConcessionSales (double avgConcessionSales)
       { if (avgConcessionSales >= 0) mAvgConcessionSales = avgConcessionSales; }
  
  const string& getName() const { return mName; }
  const string& getAddress() const { return mAddress; }
  double getAvgConcessionSales() const { return mAvgConcessionSales; }
  
  double getPotRevenue() const { return Venue::getPotRevenue() + mAvgConcessionSales; }
  void writeStatement(stringstream &output) const;
  virtual void print() const;
};

void Theater::writeStatement(stringstream &output) const {
  Venue::writeStatement(output);
  output << "Name of Theater: " << mName << endl
  << "Address of Theater: " << mAddress << endl
  << "Average Concession Sales: $" << fixed << setprecision(2) << mAvgConcessionSales << endl;
}

void Theater::print() const {
  stringstream output;
  
  writeStatement(output);
  output << "Potential Revenue: $" << fixed << setprecision(2) << getPotRevenue() << endl;
  cout << output.str() << endl;
}

#endif /* THEATER_H */
