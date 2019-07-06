//
//  Date.cpp
//  CS200_DateDemo
//
//  Created by Jessie Sully on 7/5/19.
//  Copyright © 2019 Jessie Sully. All rights reserved.
//

#include <iomanip>
#include <iostream>

#include "Date.h"

Date::Date(unsigned int d, unsigned int m, unsigned int y) {
  day = d;
  month = m;
  year = y;
}

string Date::getMonthS(bool military) const{
  
  switch (month) {
    case 1:
      return military ? "JAN" : "January";
      break;
    
    case 2:
      return military ? "FEB" : "February";
      break;
    
    case 3:
      return military ? "MAR" : "March";
      break;
    
    case 4:
      return military ? "APR" : "April";
      break;
      
    case 5:
      return military ? "MAY" : "May";
      break;
      
    case 6:
      return military ? "JUN" : "June";
      break;
      
    case 7:
      return military ? "JUL" : "July";
      break;
      
    case 8:
      return military ? "AUG" : "August";
      break;
    
    case 9:
      return military ? "SEP" : "September";
      break;
      
    case 10:
      return military ? "OCT" : "October";
      break;
      
    case 11:
      return military ? "NOV" : "November";
      break;
      
    case 12:
      return military ? "DEC" : "December";
      break;
    
    default:
      return "ERR";
  }
}


void Date::getMilitaryDate(stringstream &output) const {
  output << setw(2) << setfill('0') << day << getMonthS(true) << setw(4) << setfill('0') << year << endl;
}

void Date::getRegularDate(stringstream &output) const {
  output << getMonthS(false) << ' ' << day << ", " << year << endl;
}
