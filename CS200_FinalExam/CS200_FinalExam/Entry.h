//
//  Entry.h
//  CS200_FinalExam
//
//  Created by Jessie Sully on 7/22/19.
//  Copyright © 2019 Jessie Sully. All rights reserved.
//

#ifndef ENTRY_H
#define ENTRY_H

#include <string>
using namespace std;

class Entry {
public:
  Entry() {}
  Entry(const string &ID, double price) : mID(ID) {setPrice(price);};
  
  void setID(const string &ID) { mID = ID; }
  void setPrice(double price) { if(price >= 0) mPrice = price; }
  
  const string& getID() const { return mID; }
  double getPrice() { return mPrice; }

private:
  string mID;
  double mPrice = 0;
};

#endif /* ENTRY_H */
