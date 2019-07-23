//
//  InventoryEntry.h
//  CS200_FinalExam
//
//  Created by Jessie Sully on 7/22/19.
//  Copyright © 2019 Jessie Sully. All rights reserved.
//
/*
#ifndef INVENTORYENTRY_H
#define INVENTORYENTRY_H

#include "InventoryItem.h"
class InventoryEntry {
public:
  InventoryEntry(const string &ID, double price, unsigned int threshold, const string &unit, unsigned int stockAmt), mItem(ID, price, threshold, unit), mStockAmt(stockAmt) {}
  
  void setItem (const InventoryItem &item) { mItem = item; }
  void setQuantity (unsigned int stockAmt) { mStockAmt = stockAmt; }
  
  const InventoryItem& getItem() { return mItem; }
  unsigned int getQuantity { return mStockAmt; }
  
  bool isLow() { return mStockAmt <= mItem.threshold()}
  bool validateDecrease() { if (mStockAmt > 0) return true; }
  void decrease() { mStockAmt--; }
  void increase() { }
  
private:
  InventoryItem mItem;
  unsigned int mStockAmt = 0;
};*/

#endif /* INVENTORYENTRY_H */
