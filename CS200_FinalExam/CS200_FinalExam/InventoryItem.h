//
//  InventoryItem.h
//  CS200_FinalExam
//
//  Created by Jessie Sully on 7/22/19.
//  Copyright © 2019 Jessie Sully. All rights reserved.
//

#ifndef INVENTORYITEM_H
#define INVENTORYITEM_H

#include "Entry.h"

class InventoryItem : public Entry {
public:
  InventoryItem() {}
  InventoryItem(const string &ID, double price, unsigned int threshold, const string &unit) : Entry(ID, price), mUnit(unit) { setThreshold(threshold); };
  
  void setThreshold(unsigned int threshold) { mThreshold = threshold; }
  void setUnit(const string &unit) { mUnit = unit; }
  
  
  unsigned int getThreshold() const { return mThreshold; }
  const string& getUnit() const { return mUnit; }
  
  
private:
  unsigned int mThreshold = 1;
  string mUnit; // liter, galon, box...
};

#endif /* INVENTORYITEM_H */
