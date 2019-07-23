//
//  Date.h
//  CS200_Exercise10_2_Aggregation
//
//  Created by Jessie Sully on 7/21/19.
//  Copyright © 2019 Jessie Sully. All rights reserved.
//

#ifndef DATE_H
#define DATE_H

#include <string>
#include <iomanip>
#include <sstream>
#include <iostream>
using namespace std;

/*
 -----------------------
 Date
 -----------------------
 - mMonth : unsigned int
 - mDay : unsigned int
 - mYear : unsigned int
 -----------------------
 + Date()
 + Date(month : unsigned int, day : unsigned int, year : unsigned int)
 + setDay (day : unsigned int) : void
 + setMonth (month : unsigned int) : void
 + setYear (year : unsigned int) : void
 + getDay() : unsigned int
 + getMonth() : unsigned int
 + getYear() : unsigned int
 + wristeStatement(stringstream : output) : void
 + print() : void
 ----------------------
 */

class Date {
private:
  unsigned int mMonth = 1;
  unsigned int mDay = 1;
  unsigned int mYear = 0;
  
public:
  Date() {}
  Date(unsigned int month, unsigned int day, unsigned int year) :
       mYear(year) {setMonth(month); setDay(day);}
  
  void setMonth (unsigned int month) { if (month > 0 && month <= 12) mMonth = month; }
  void setDay (unsigned int day);
  void setYear (unsigned int year)   { mYear = year; }
  
  unsigned int getMonth() const { return mMonth; }
  unsigned int getDay() const   { return mDay; }
  unsigned int getYear() const  { return mYear; }
  
  void writeStatement(stringstream &output) const;
  void print() const;
};

void Date::setDay (unsigned int day) {
  if (day > 0 && day < 31 - (mMonth == 4 || mMonth == 6 || mMonth == 9 || mMonth == 11) - (mMonth == 2 ? (mYear % 4 == 0 ? 2 : 3) : 0)) mDay = day;
}

void Date::writeStatement(stringstream &output) const {
  output << mMonth << '/' << mDay << '/' << setw(4) << setfill('0') << mYear;
}

void Date::print() const {
  stringstream output;
  writeStatement(output);
  cout << output.str() << endl;
}

#endif /* DATE_H */
