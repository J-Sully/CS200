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
 Bravo : Alpha
 -----------------------
 - mStatus : bool
 - mTotal : float
 -----------------------
 + Bravo()
 + Bravo(sentence : string, number : int, status : bool, total : float)
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
  Bravo() : Alpha() {}
  Bravo (int number, const string &sentence, bool status, float total) :
         Alpha(number, sentence), mStatus(status), mTotal(total) {}
  
  void setStatus(bool status) { mStatus = status; }
  void setTotal(float total)  { mTotal = total; }
  
  bool getStatus() const { return mStatus; }
  float getTotal() const { return mTotal; }
};

#endif /* BRAVO_H */
