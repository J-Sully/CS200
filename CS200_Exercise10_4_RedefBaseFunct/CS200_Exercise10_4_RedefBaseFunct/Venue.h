//
//  Venue.h
//  CS200_Exercise10_4_RedefBaseFunct
//
//  Created by Jessie Sully on 7/22/19.
//  Copyright © 2019 Jessie Sully. All rights reserved.
//

#ifndef VENUE_H
#define VENUE_H

/*
 -----------------------
 Venue
 -----------------------
 - mType : string
 - mYear : unsigned int
 - mCapacity : unsigned int
 - mBasePrice : double
 -----------------------
 + Venue()
 + Venue(type : string, year : unsigned int, capacity : unsigned int, basePrice : double)
 + setType (type : string) : void
 + setYear (year : unsigned int) : void
 + setCapacity (capacity : unsigned int) : void
 + setBasePrice (basePrice : double) : void
 + getType() : string
 + getYear() : unsigned int
 + getCapacity() : unsigned int
 + getBasePrice() : double
 + getPotRevenue() : double
 + writeStatement(output : stringstream) : void
 + print() : void
 ----------------------
 */

class Venue {
private:
  string mType;
  unsigned int mYear = 0;
  unsigned int mCapacity = 0;
  double mBasePrice = 0;
  
public:
  Venue() {}
  Venue(const string &type, unsigned int year, unsigned int capacity, double basePrice) :
        mType(type), mYear(year), mCapacity(capacity) {setBasePrice(basePrice);}
  
  void setType (const string &type) { mType = type; }
  void setYear (unsigned int year)   { mYear = year; }
  void setCapacity (unsigned int capacity) { mCapacity = capacity; }
  void setBasePrice (double basePrice) { if (basePrice >= 0) mBasePrice = basePrice; }
  
  const string& getType() const { return mType; }
  unsigned int getYear() const  { return mYear; }
  unsigned int getCapacity() const   { return mCapacity; }
  double getBasePrice() const { return mBasePrice; }
  
  double getPotRevenue() const { return mBasePrice * mCapacity; }
  void writeStatement(stringstream &output) const;
  virtual void print() const;
  
};

void Venue::writeStatement(stringstream &output) const {
  output << "Type of Venue: " << mType << endl
  << "Year opened: " << mYear << endl
  << "Occupant Capacity: " << mCapacity << endl
  << "Base Price per Occupant: $" << fixed << setprecision(2) << mBasePrice << endl;
}

void Venue::print() const {
  stringstream output;
  writeStatement(output);
  output << "Potential Revenue: $" << fixed << setprecision(2) << getPotRevenue() << endl;
  cout << output.str() << endl;
}

#endif /* VENUE_H */
