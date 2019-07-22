//
//  Person.hpp
//  CS200_Exercise10_2_Aggregation
//
//  Created by Jessie Sully on 7/21/19.
//  Copyright © 2019 Jessie Sully. All rights reserved.
//

#ifndef PERSON_H
#define PERSON_H

#include <string>
#include <sstream>
using namespace std;

#include "Date.h"

/*
 -----------------------
 Person
 -----------------------
 - mSSN : unsigned int
 - mBirthday : Date
 -----------------------
 + Person()
 + Person(SSN : unsigned int, birthday : Date)
 + setSSN (SSN : unsigned int) : void
 + setBirthday (birthday : Date) : void
 + getSSN() : unsigned int
 + getBirthday() : Date
 + writeStatement(output : stringstream) : void
 + print() : void
 ----------------------
 */

class Person {
private:
  unsigned int mSSN = 1111111111;
  Date mBirthday;
  
public:
  Person() {}
  Person(unsigned int SSN, const Date &birthday) : mSSN(SSN), mBirthday(birthday) {}
  
  void setSSN (unsigned int SSN)     { mSSN = SSN; }
  void setBirthday (const Date &birthday) { mBirthday = birthday; }
  
  unsigned int getSSN() const { return mSSN; }
  const Date& getBirthday() const    { return mBirthday; }
  
  void writeStatement(stringstream &output) const;
  void print() const;
};

void Person::writeStatement(stringstream &output) const {
  output << "SSN: " << mSSN << endl
         << "Date of Birth: ";
  mBirthday.writeStatement(output);
}

void Person::print() const {
  stringstream output;
  writeStatement(output);
  cout << output.str() << endl;
}

#endif /* PERSON_H */
