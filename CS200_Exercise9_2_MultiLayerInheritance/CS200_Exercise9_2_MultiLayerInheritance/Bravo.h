//
//  Bravo.h
//  CS200_Exercise9_2_MultiLayerInheritance
//
//  Created by Jessie Sully on 7/17/19.
//  Copyright © 2019 Jessie Sully. All rights reserved.
//

#ifndef BRAVO_H
#define BRAVO_H

#include "Alpha.h"

/*
 -----------------------
 Bravo : Charlie
 -----------------------
 - mStatus : bool
 - mTotal : float
 -----------------------
 + Bravo()
 + Bravo(status : bool, total : float, sentence : string, number : int)
 + setStatus (status : bool) : void
 + setTotal (total : float) : void
 + getStatus() : bool
 + getTotal() : float
 ----------------------
 */

class Bravo : public Alpha {
private:
  bool mStatus = false;
  float mTotal = 0;
  
public:
  Bravo() : Alpha() {};
  Bravo (bool status, float total, int number, const string &sentence) :
         Alpha(number, sentence), mStatus(status), mTotal(total) {}
  
  void setStatus(bool status) { mStatus = status; }
  void setTotal(float total)  { mTotal = total; }
  
  bool getStatus() const { return mStatus; }
  float getTotal() const { return mTotal; }
};

#endif /* BRAVO_H */
