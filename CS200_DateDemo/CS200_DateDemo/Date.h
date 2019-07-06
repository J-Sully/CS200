//
//  Date.h
//  CS200_DateDemo
//
//  Created by Jessie Sully on 7/5/19.
//  Copyright © 2019 Jessie Sully. All rights reserved.
//

#ifndef DATE_H
#define DATE_H

#include <string>
#include <sstream>
using namespace std;

/*
 -----------------------
 Date
 -----------------------
 - day: unsigned int
 - month: unsigned int
 - year: unsigned int
 -----------------------
 + Date(day : unsigned int, month : unsigned int, year : unsigned int)
 + getMilitaryDate() : void
 + getRegularDate() : void
 - getMonthS() : string
 ----------------------
 */

class Date {
  
private:
  unsigned int day;
  unsigned int month;
  unsigned int year;
  string getMonthS(bool military) const;
  
public:
  Date(unsigned int day, unsigned int month, unsigned int year);
  void getMilitaryDate(stringstream &output) const;
  void getRegularDate(stringstream &output) const;
};

#endif /* DATE_H */

