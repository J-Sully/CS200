//
//  Charlie.hpp
//  CS200_Exercise9_4_MultipleInheritance
//
//  Created by Jessie Sully on 7/17/19.
//  Copyright © 2019 Jessie Sully. All rights reserved.
//

#ifndef CHARLIE_H
#define CHARLIE_H

#include "Alpha.h"
#include "Bravo.h"


/*
 -----------------------
 Charlie : Alpha, Bravo
 -----------------------
 - mSituation : string
 - mBalance : float
 -----------------------
 + Charlie()
 + Charlie(situation : string, balance : float, status : bool, total : float, sentence : string, number : int)
 + setSituation (situation : string) : void
 + setBalance (balance : float) : void
 + getSituation() : string
 + getBalance() : float
 ----------------------
 */

class Charlie : public Alpha, public Bravo {
private:
  string mSituation;
  float mBalance = 0;
  
public:
  Charlie() : Alpha(), Bravo() {}
  Charlie (const string &situation, float balance, bool status,
           float total, int number, const string &sentence) :
           Alpha(number, sentence), Bravo(status, total),
           mSituation(situation),   mBalance(balance) {}
  
  void setSituation(const string &situation) { mSituation = situation; }
  void setBalance(float balance)             { mBalance = balance; }
  
  const string& getSituation() const { return mSituation; }
  float getBalance() const           { return mBalance; }
};

#endif /* CHARLIE_H */
