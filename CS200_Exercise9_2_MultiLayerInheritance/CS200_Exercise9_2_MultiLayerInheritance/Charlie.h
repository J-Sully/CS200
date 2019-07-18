//
//  Charlie.h
//  CS200_Exercise9_2_MultiLayerInheritance
//
//  Created by Jessie Sully on 7/17/19.
//  Copyright © 2019 Jessie Sully. All rights reserved.
//

#ifndef CHARLIE_H
#define CHARLIE_H

#include "Bravo.h"

/*
 -----------------------
 Charlie : Bravo
 -----------------------
 - mSituation : string
 - mBalance : float
 -----------------------
 + Charlie()
 + Charlie(number : int, sentence : string, status : bool, total : float, situation : string, balance : float)
 + setSituation (situation : string) : void
 + setBalance (balance : float) : void
 + getSituation() : string
 + getBalance() : float
 ----------------------
 */

class Charlie : public Bravo {
private:
  string mSituation;
  float mBalance = 0;
  
public:
  Charlie() : Bravo() {}
  Charlie (int number, const string &sentence, bool status, float total, const string &situation, float balance,) :
  Bravo(number, sentence, status, total), mSituation(situation), mBalance(balance) {}
  
  void setSituation(const string &situation) { mSituation = situation; }
  void setBalance(float balance)             { mBalance = balance; }
  
  const string& getSituation() const { return mSituation; }
  float getBalance() const           { return mBalance; }
};

#endif /* CHARLIE_H */
