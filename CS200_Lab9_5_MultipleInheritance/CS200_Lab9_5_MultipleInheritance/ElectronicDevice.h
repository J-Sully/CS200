//
//  ElectronicDevice.h
//  CS200_Lab9_5_MultipleInheritance
//
//  Created by Jessie Sully on 7/17/19.
//  Copyright © 2019 Jessie Sully. All rights reserved.
//

#ifndef ELECTRONICDEVICE_H
#define ELECTRONICDEVICE_H

#include <string>
using namespace std;

/*
 -----------------------
 ElectronicDevice
 -----------------------
 - mType : string
 - mOS : string
 - mMemoryGB : unsigned int
 -----------------------
 + ElectronicDevice()
 + ElectronicDevice(type : string, OS : string, memoryGB : unsigned int)
 + setType (type : string) : void
 + setOS (OS : string) : void
 + setMemoryGB (memoryGB : unsigned int) : void
 + getType() : string
 + getOS() : string
 + getMemoryGB() : unsigned int

 ----------------------
 */

class ElectronicDevice {
private:
  string mType;
  string mOS;
  unsigned int mMemoryGB = 0;
  
public:
  ElectronicDevice() {}
  ElectronicDevice(const string &type, const string &OS, unsigned int memoryGB) :
                   mType(type), mOS(OS), mMemoryGB(memoryGB) {}
  
  void setType(const string &type)         { mType = type; }
  void setOS(const string &OS)             { mOS = OS; }
  void setMemoryGB (unsigned int memoryGB) { mMemoryGB = memoryGB; }
  
  const string& getType() const    { return mType; }
  const string& getOS () const     { return mOS; }
  unsigned int getMemoryGB() const { return mMemoryGB; }
  
};

#endif /* ELECTRONICDEVICE_H */
