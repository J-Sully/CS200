//
//  Alcohol.h
//  CS200_FinalProject_v2
//
//  Created by Jessie Sully on 7/23/19.
//  Copyright © 2019 Jessie Sully. All rights reserved.
//

#ifndef ALCOHOL_H
#define ALCOHOL_H

#include <string>
using namespace std;

class Alcohol {
public:
  Alcohol() {}
  Alcohol(const string &type, double tax) : mType(type) { setTax(tax); }
  
  void setType (const string &type) { mType = type; }
  void setTax (double tax) { if (tax >= 0) mTax = tax;}
  
  const string& getType() const { return mType; }
  double getExciseTax() const;
  
private:
  string mType;
  double mTax = 0;
};

#endif /* ALCOHOL_H */
