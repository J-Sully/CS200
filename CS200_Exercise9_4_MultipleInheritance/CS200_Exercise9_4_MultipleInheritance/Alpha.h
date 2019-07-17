//
//  Alpha.hpp
//  CS200_Exercise9_4_MultipleInheritance
//
//  Created by Jessie Sully on 7/17/19.
//  Copyright © 2019 Jessie Sully. All rights reserved.
//

#ifndef ALPHA_H
#define ALPHA_H

#include <string>
using namespace std;

/*
 -----------------------
 Alpha
 -----------------------
 - mNumber : int
 - mSentence : string
 -----------------------
 + Alpha()
 + Alpha(sentence : string, number : int)
 + setNumber (number : int) : void
 + setSentence (sentence : string) : void
 + getNumber() : int
 + getSentence() : string
 ----------------------
 */

class Alpha {
private:
  int mNumber = 0;
  string mSentence;
  
public:
  Alpha(){};
  Alpha(int number, const string &sentence) : mNumber(number), mSentence(sentence) {}
  
  void setNumber(int number)               { mNumber = number; }
  void setSentence(const string &sentence) { mSentence = sentence; }
  
  int getNumber() const             { return mNumber; }
  const string& getSentence() const { return mSentence; }
};

#endif /* ALPHA_H */
