//
//  ReaderApp.h
//  CS200_Lab9_5_MultipleInheritance
//
//  Created by Jessie Sully on 7/17/19.
//  Copyright © 2019 Jessie Sully. All rights reserved.
//

#ifndef READERAPP_H
#define READERAPP_H

#include "PublishedWork.h"
#include "ElectronicDevice.h"

/*
 -----------------------
 ReaderApp : PublishedWork, ElectronicDevice
 -----------------------
 - mName : string
 - mCost : double
 -----------------------
 + ReaderApp()
 + ReaderApp(sentence : string, number : int, author : string, yearPublished : unsigned int, type : string, OS : string, memoryGB : unsigned int)
 + setName (name : string) : void
 + setCost (cost : double) : void
 + getName() : string
 + getCost() : double
 ----------------------
 */

class ReaderApp : public PublishedWork, public ElectronicDevice {
private:
  string mName;
  double mCost = 0;
  
  
public:
  ReaderApp(){};
  ReaderApp(const string &name, double cost, const string &author,
            unsigned int yearPublished, const string &type, const string &OS,
            unsigned int memoryGB) : PublishedWork(author, yearPublished), ElectronicDevice(type, OS, memoryGB), mName(name), mCost(cost) {}
  
  void setName (const string &name) { mName = name; }
  void setCost (double cost)        { if (cost >= 0) mCost = cost; }
  
  const string& getName () const { return mName; }
  double getCost () const        { return mCost; }
  
};

#endif /* READERAPP_H */
