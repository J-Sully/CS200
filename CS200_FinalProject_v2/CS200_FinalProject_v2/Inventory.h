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
  
  InventoryItem* getItem(int index) const;
  void getInStockItems(vector<InventoryItem*> &itemsInStock) const;
  
  void printContents() const;
  void printLowStock() const;
  void printOutOfStock() const;
  void printMenu() const;
  void printInventoryList() const;
  
  /*
   bool validateName(const string &name, unsigned int &index) const;
   bool validateName(const string &name) const;
   bool placeOrder(const string &name, double &totalPrice, double quantity = 1) const;
   double addInventory(string &name, double quantity) const;
   bool loseInventory(string &name, double quantity, const bool isStockUnit) const;
   bool hasInventory(string &name) const;
   
   */
  
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

unsigned int Inventory::getNumInStockItems() const {
  int i = 0, num = 0;
  for (; i < mItems.size(); i++) {
    if (!mItems.at(i)->isOutOfStock()) num++;
  }
  return num;
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

void Inventory::printInventoryList() const {
  for(int i = 0; i < getNumItems(); i++) {
    cout << '\t' << i + 1 << " - ";
    mItems.at(i)->printInventoryListing();
  }
}

InventoryItem* Inventory::getItem(int index) const {
  return mItems.at(index);
}

/*
bool Inventory::placeOrder(const string &name, double &price, double quantity) const {
  bool validOrder;
  unsigned int i = 0;
  
  validOrder = validateName(name, i);
  
  if (validOrder) {
    validOrder &= mItems.at(i)->isValidOrder(quantity);
    if(validOrder) {
      price = quantity * mItems.at(i)->getServingPrice();
      mItems.at(i)->placeOrder(quantity);
      if (mItems.at(i)->hasTax()) {
        price += mItems.at(i)->getTax(quantity);
      }
    }
  }
  return validOrder;
}


double Inventory::addInventory(string &name, double quantity) const {
  bool valid;
  unsigned int i = 0;
  double price = 0;
  
  valid = validateName(name, i);
  if (valid) {
    price = mItems.at(i)->addStock(quantity);
  }
  return price;
}

bool Inventory::loseInventory(string &name, double quantity, const bool isStockUnit) const {
  bool valid;
  unsigned int i = 0;
  
  valid = validateName(name, i);
  
  if (valid && isStockUnit) { // quantity is stock unit
    valid &= mItems.at(i)->loseStock(quantity);
  }
  else if (valid && !isStockUnit) { //quantity is not stock unit
    valid &= mItems.at(i)->loseUnits(quantity);
  }
  return valid;
}

bool Inventory::hasInventory(string &name) const {
  bool valid;
  unsigned int i = 0;
  
  valid = validateName(name, i);
  if (valid) {
    valid &= mItems.at(i)->getUnitsRemaining() >= 0;
  }
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

bool Inventory::validateName(const string &name) const {
  bool valid = false;
  for(int i = 0; !valid && i < mItems.size(); i++) {
    if (name == mItems.at(i)->getID()) {
      valid = true;
    }
  }
  return valid;
}

*/

#endif /* INVENTORY_H */
