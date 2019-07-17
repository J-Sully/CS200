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
 + Charlie(situation : string, balance : float, status : bool, total : float, sentence : string, number : int)
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
  Charlie() : Bravo() {};
  Charlie (const string &situation, float balance, bool status, float total, int number, const string &sentence) :
  Bravo(status, total, number, sentence), mSituation(situation), mBalance(balance) {}
  
  void setSituation(const string &situation) { mSituation = situation; }
  void setBalance(float balance)             { mBalance = balance; }
  
  const string& getSituation() const { return mSituation; }
  float getBalance() const           { return mBalance; }
};

#endif /* CHARLIE_H */
