//
//  main.cpp
//  CS200_FinalProject_v2
//
//  Created by Jessie Sully on 7/23/19.
//  Copyright © 2019 Jessie Sully. All rights reserved.
//

#include <iostream>

#include "Unit.h"
#include "NonAlcoholicItem.h"
#include "AlcoholicItem.h"
#include "BeerItem.h"
#include "WineItem.h"
#include "SpiritItem.h"
#include "Inventory.h"

static const string INVENTORY_CSV = "inventory.csv";
static const string ROUNDTRIP_CSV = "roundtrip.csv";

void generateCSV(const string& filename);

int main(int argc, const char * argv[]) {

  generateCSV(INVENTORY_CSV);
  Inventory inventory(INVENTORY_CSV);
  inventory.printContents();
  inventory.writeCSV(ROUNDTRIP_CSV);
  
  return 0;
}

void generateCSV(const string& filename) {
  stringstream csv;
  BeerItem beer("Lagunitas", 13, 10.99, 4);
  beer.print();
  beer.writeCSV(csv);
  csv << endl;
  
  WineItem wine("Meiomi Pinot Noir", 191, 2017, 15.99);
  wine.print();
  wine.writeCSV(csv);
  csv << endl;
  
  SpiritItem spirit("Orendain Tequila Blanco", 180, 2019, 9.99);
  spirit.print();
  spirit.writeCSV(csv);
  csv << endl;
  
  NonAlcoholicItem pretzels("Snyder's of Hanover Snaps Pretzels", 6.59, 3, Unit::OUNCES, 2.99, 50, 1.06383);
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
