//
//  Inventory.h
//  CS200_FinalProject_v2
//
//  Created by Jessie Sully on 7/24/19.
//  Copyright © 2019 Jessie Sully. All rights reserved.
//

#ifndef INVENTORY_H
#define INVENTORY_H

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

#include "InventoryItem.h"

/*
 -----------------------
 Inventory
 -----------------------
 - mItems : vector<InventoryItem*>
 -----------------------
 + Inventory()
 + Inventory(filename : string)
 + ~Inventory()
 - readCSV (filename : string) : void
 + writeCSV (filename : string) : void
 + getItem(index : int) : InventoryItem*
 + getNumItems() : unsigned long
 + empty() : bool
 + getInStockItems(itemsInStock : vector<InventoryItem*>) : void
 + printContents() : void
 + printLowStock() : void
 + printOutOfStock() : void
 + printMenu() : void
 + printInventoryList() : void
 ----------------------
 */

class Inventory {
public:
  Inventory() {}
  Inventory(const string &filename) { readCSV(filename); }
  ~Inventory();
  
  void writeCSV(const string &filename) const;
  
  InventoryItem* getItem(int index) const;
  unsigned long getNumItems() const { return mItems.size(); }
  void getInStockItems(vector<InventoryItem*> &itemsInStock) const;
  
  bool empty() const { return mItems.empty(); }
  
  void printContents() const;
  void printLowStock() const;
  void printOutOfStock() const;
  void printMenu() const;
  void printInventoryList() const;
  
private:
  vector<InventoryItem*> mItems;
  void readCSV(const string &filename);
};

Inventory::~Inventory() {
  for (InventoryItem* &item : mItems) {
    delete item;
  }
}

void Inventory::readCSV(const string &filename) {
  ifstream is;
  stringstream lineStream;
  string csvLine, type;
  InventoryItem* item = nullptr;
  
  is.open(filename);
  if(is) {
    while(getline(is, csvLine)) {
      item = nullptr;
      lineStream.clear();
      lineStream.str(csvLine);
      if(getline(lineStream, type, ',')) {
        if (type == NonAlcoholicItem::ItemType) {
          item = new NonAlcoholicItem(lineStream);
        }
        else if (type == Alcohol::getAlcoholSType(Alcohol::BEER)) {
          item = new BeerItem(lineStream);
        }
        else if (type == Alcohol::getAlcoholSType(Alcohol::SPIRIT)) {
          item = new SpiritItem(lineStream);
        }
        else if (type == Alcohol::getAlcoholSType(Alcohol::WINE)) {
          item = new WineItem(lineStream);
        }
        else {
          cerr << "Unknown Type: " << type << endl;
        }
      }
      
     if (item) {
       mItems.push_back(item);
       item = nullptr;
      }
    }
  }
  is.close();
}

void Inventory::writeCSV(const string &filename) const {
  ofstream output;
  output.open(filename);
  if(output) {
    for(InventoryItem* item : mItems) {
      item->writeCSV(output);
      output << endl;
    }
  }
}

InventoryItem* Inventory::getItem(int index) const {
  return mItems.at(index);
}

void Inventory::getInStockItems(vector<InventoryItem*> &itemsInStock) const {
  itemsInStock.clear();
  for(InventoryItem* item : mItems) {
    if(!item->isOutOfStock()) {
      itemsInStock.push_back(item);
    }
  }
}

void Inventory::printContents() const {
  for(InventoryItem* item : mItems) {
    item->print();
  }
}

void Inventory::printMenu() const {
  for(InventoryItem* item : mItems) {
    if(!item->isOutOfStock()) {
      item->printDrinkListing();
    }
  }
}

void Inventory::printInventoryList() const {
  for(int i = 0; i < getNumItems(); i++) {
    cout << '\t' << i + 1 << " - ";
    mItems.at(i)->printInventoryListing();
  }
}

void Inventory::printLowStock() const {
  for(InventoryItem* item : mItems) {
    if(item->isLowStock()) {
      item->printLowStockMessaage();
    }
  }
}

void Inventory::printOutOfStock() const {
  for(InventoryItem* item : mItems) {
    if(item->isOutOfStock()) {
      item->printOutOfStockMessage();
    }
  }
}

#endif /* INVENTORY_H */
