//
//  Inventory.hpp
//  CS200_FinalProject_v2
//
//  Created by Jessie Sully on 7/24/19.
//  Copyright © 2019 Jessie Sully. All rights reserved.
//

#ifndef Inventory_hpp
#define Inventory_hpp

#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
using namespace std;

#include "InventoryItem.h"

class Inventory {
public:
  Inventory() {}
  Inventory(const string &filename) { readCSV(filename); }
  ~Inventory();
  
  void readCSV(const string &filename);
  void writeCSV(const string &filename) const;
  
  unsigned long getNumItems() const { return mItems.size(); }
  bool empty() const { return mItems.empty(); }
  void printContents() const;
  void printLowStock() const;
  void printOutOfStock() const;
  void printMenu() const;
  
private:
  vector<InventoryItem*> mItems;
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

void Inventory::printContents() const {
  for(InventoryItem* item : mItems) {
    item->print();
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

void Inventory::printMenu() const {
  for(InventoryItem* item : mItems) {
    if(!item->isOutOfStock()) {
      item->printDrinkListing();
    }
  }
}



#endif /* Inventory_hpp */
