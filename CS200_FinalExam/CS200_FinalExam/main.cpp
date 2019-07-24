//
//  main.cpp
//  CS200_FinalExam
//
//  Created by Jessie Sully on 7/22/19.
//  Copyright © 2019 Jessie Sully. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <vector>

#include "AlcoholicItem.h"

static const string INVENTORY_CSV = "inventory.csv";
static const string ROUNDTRIP_CSV = "roundtrip.csv";

using namespace std;

void generateCSV(const string& filename) {
  stringstream csv;
  BeerItem beer("Lagunitas", 13, 4);
  beer.print();
  beer.writeCSV(csv);
  csv << endl;

  WineItem wine("Meiomi Pinot Noir", 191, 2017);
  wine.print();
  wine.writeCSV(csv);
  csv << endl;

  SpiritItem spirit("Orendain Tequila Blanco", 180, 2019);
  spirit.print();
  spirit.writeCSV(csv);
  csv << endl;

  NonAlcoholicItem pretzels("Snyder's of Hanover Snaps Pretzels", 6.59, 3, Unit::OUNCES, 50, 1.06383);
  pretzels.print();
  pretzels.writeCSV(csv);
  csv << endl;

  cout << csv.str();

  ofstream inv_csv;
  inv_csv.open(filename);
  if (inv_csv) {
    inv_csv << csv.str();
  }
  inv_csv.close();
}

class Inventory {
public:
  Inventory() {}
  Inventory(const string& filename) { readCSV(filename); }
  ~Inventory();
  
  bool readCSV(const string& filename);
  bool writeCSV(const string& filename) const;
  unsigned long getNumItems() const { return mItems.size(); }
  bool empty() const { return mItems.empty(); }
  
  void dumpContents();
  
private:
  vector<InventoryItem*> mItems;
};

Inventory::~Inventory() {
  for (InventoryItem* item : mItems) {
    delete item;
  }
}

void Inventory::dumpContents() {
  for (InventoryItem* item : mItems) {
    item->print();
  }
}

bool Inventory::writeCSV(const string& filename) const {
  ofstream csv;
  csv.open(filename);
  if (!csv) return false;
  
  for (InventoryItem* item : mItems) {
    item->writeCSV(csv);
    csv << endl;
  }
  return true;
}

bool Inventory::readCSV(const string& filename) {
  bool success = true;
  stringstream lineStream;
  string token;
  
  ifstream csv;
  csv.open(filename);
  if (csv) {
    string line;
    while (getline(csv, line)) {
      lineStream.clear();
      lineStream.str(line);
      
      InventoryItem* item = nullptr;
      if (getline(lineStream, token, ',')) {
        if (token == NonAlcoholicItem::ItemType) {
          item = new NonAlcoholicItem(lineStream);
        }
        else if (token == Alcohol::getAlcoholName(Alcohol::BEER)) {
          item = new BeerItem(lineStream);
        }
        else if (token == Alcohol::getAlcoholName(Alcohol::WINE)) {
          item = new WineItem(lineStream);
        }
        else if (token == Alcohol::getAlcoholName(Alcohol::SPIRIT)) {
          item = new SpiritItem(lineStream);
        }
        else {
          cerr << "Unknown type: " << token << endl;
          success = false;
        }
      }
      
      if (item) {
        mItems.push_back(item);
      }
    }
  }
  csv.close();
  return success;
}

int main(int argc, const char * argv[]) {
  //writeCSV(INVENTORY_CSV);
  Inventory inventory(INVENTORY_CSV);
  inventory.dumpContents();
  inventory.writeCSV(ROUNDTRIP_CSV);
  return 0;
}
