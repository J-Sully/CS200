//
//  InventoryEntry.h
//  CS200_FinalExam
//
//  Created by Jessie Sully on 7/22/19.
//  Copyright © 2019 Jessie Sully. All rights reserved.
//

#ifndef INVENTORYENTRY_H
#define INVENTORYENTRY_H

#include "InventoryItem.h"
class InventoryEntry {
public:
  InventoryEntry(const string &ID, double price, unsigned int threshold, const string &unit, unsigned int quantity), mItem(ID, price, threshold, unit), mQuantity(quantity) {}
  
  void setItem (const InventoryItem &item) { mItem = item; }
  void setQuantity (unsigned int quantity) { mQuantity = quantity; }
  
  const InventoryItem& getItem() { return mItem; }
  unsigned int getQuantity { return mQuantity; }
  
private:
  InventoryItem mItem;
  unsigned int mQuantity = 0;
};

#endif /* INVENTORYENTRY_H */
