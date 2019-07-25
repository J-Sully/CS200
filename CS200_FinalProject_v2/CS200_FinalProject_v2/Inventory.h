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
  unsigned int getNumInStockItems() const;
  bool empty() const { return mItems.empty(); }
  bool validateName(const string &name, unsigned int &index) const;
  bool placeOrder(const string &name, double &totalPrice, double quantity = 1) const;
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

unsigned int Inventory::getNumInStockItems() const {
  int i = 0, num = 0;
  for (; i < mItems.size(); i++) {
    if (!mItems.at(i)->isOutOfStock()) num++;
  }
  return num;
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

bool Inventory::placeOrder(const string &name, double &price, double quantity) const {
  bool validOrder;
  unsigned int i = 0;
  
  validOrder = validateName(name, i);
  
  if (validOrder) {
    validOrder &= mItems.at(i)->isValidOrder(quantity);
    if(validOrder) {
      price = quantity * mItems.at(i)->getServingPrice();
      if (mItems.at(i)->hasTax()) {
        price += mItems.at(i)->getTax(quantity);
      }
    }
  }
  return validOrder;
}

bool Inventory::validateName(const string &name, unsigned int &index) const {
  bool valid = false;
  for(int i = 0; !valid && i < mItems.size(); i++) {
    if (name == mItems.at(i)->getID()) {
      valid = true;
      index = i;
    }
  }
  return valid;
}



#endif /* Inventory_hpp */
