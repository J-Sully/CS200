//
//  InventoryList.hpp
//  CS200_FinalExam
//
//  Created by Jessie Sully on 7/22/19.
//  Copyright © 2019 Jessie Sully. All rights reserved.
//

#ifndef INVENTORYLIST_H
#define INVENTORYLIST_H

#include <vector>
using namespace std;

#include "InventoryEntry.h"

class InventoryList {
public:
  InventoryList() {}
  InventoryList(vector<InventoryEntry> &entries) { if (!entries.empty()) mInventory.assign(entries.first(), entries.end())}
  
  void addItem(InventoryEntry &entry) { mInventory.push_back(entry); }
private:
  vector<InventoryEntry> mInventory;
};

#endif /* INVENTORYLIST_H */
