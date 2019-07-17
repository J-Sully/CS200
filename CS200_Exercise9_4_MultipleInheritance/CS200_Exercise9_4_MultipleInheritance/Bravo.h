//
//  Bravo.hpp
//  CS200_Exercise9_4_MultipleInheritance
//
//  Created by Jessie Sully on 7/17/19.
//  Copyright © 2019 Jessie Sully. All rights reserved.
//

#ifndef BRAVO_H
#define BRAVO_H

#include "Alpha.h"

/*
 -----------------------
 Bravo
 -----------------------
 - mStatus : bool
 - mTotal : float
 -----------------------
 + Bravo()
 + Bravo(status : bool, total : float)
 + setStatus (status : bool) : void
 + setTotal (total : float) : void
 + getStatus() : bool
 + getTotal() : float
 ----------------------
 */

class Bravo {
private:
  bool mStatus = false;
  float mTotal = 0;
  
public:
  Bravo() : Alpha() {};
  Bravo (bool status, float total) : mStatus(status), mTotal(total) {}
  
  void setStatus(bool status) { mStatus = status; }
  void setTotal(float total)  { mTotal = total; }
  
  bool getStatus() const { return mStatus; }
  float getTotal() const { return mTotal; }
};

#endif /* BRAVO_H */
