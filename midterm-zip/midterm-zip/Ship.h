//
//  Ship.h
//  Midterm
//
//  Created by Jessie Sully on 7/14/19.
//  Copyright © 2019 Jessie Sully. All rights reserved.
//

#ifndef SHIP_H
#define SHIP_H

#include <string>
using namespace std;

/*
 -----------------------
 Ship
 -----------------------
 - mRegistry : string
 - mHomeport : string
 - mName : string
 - mLength : unsigned int
 - mDisplacement : unsigned int
 -----------------------
 + Ship()
 + Ship(registry : string, homeport : string, name : string, length : unsigned int, displacement : unsigned int)
 + setRegistry (registry : string) : void
 + setHomeport (homeport : string) : void
 + setName (name : string) : void
 + setLength (length : unsigned int) : void
 + setDisplacement (displacement : unsigned int) : void
 + getRegistry() : string
 + getRegistry() : string
 + getRegistry() : string
 + getRegistry() : unsigned int
 + getRegistry() : unsigned int
 ----------------------
 */

class Ship {
  
private:
  string mRegistry;
  string mHomeport;
  string mName;
  unsigned int mLength = 0;
  unsigned int mDisplacement = 0;
  
public:
  Ship(){}
  Ship(const string &registry, const string &homeport, const string &name, unsigned int length, unsigned int displacement) : mRegistry(registry), mHomeport(homeport), mName(name), mLength(length), mDisplacement(displacement) {}
  
  void setRegistry (string &registry)              { mRegistry = registry; }
  void setHomeport (string &homeport)              { mHomeport = homeport; }
  void setName (string &name)                      { mName = name; }
  void setLength (unsigned int length)             { mLength = length; }
  void setDisplacement (unsigned int displacement) { mDisplacement = displacement; }
  
  const string& getRegistry() const    { return mRegistry; }
  const string& getHomeport() const    { return mHomeport; }
  const string& getName() const        { return mName; }
  unsigned int getLength() const       { return mLength; }
  unsigned int getDisplacement() const { return mDisplacement; }
  
  void writeStatus(stringstream &output) const;
  void print() const;
};

#endif /* SHIP_H */
