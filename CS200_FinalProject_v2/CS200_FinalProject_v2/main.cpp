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


const string MAINMENU = { R"(
Welcome to the Main Menu:
  
  1: Enter a sale
  2: View Report
  3: Manage Inventory
  4: End Day
  
Please enter your selection: )"
};

enum OptMainMenu {OPT_SALE = 1, OPT_REPORT, OPT_INVENTORY, OPT_EXIT};

const string SALEMENU = { R"(
Welcome to the Sale Menu:
  
  1: View Item List
  2: Enter Item Sale
  3: Exit to Main Menu
  
Please enter your selection: )"
};

enum eOptSaleMenu {OPT_LISTDRINKS = 1, OPT_ENTERDRINK, OPT_EXITSALE};

const string INVENTORYMENU = { R"(
Welcome to the Inventory Menu:
  
  1: View Inventory
  2: Add Stock Items to Inventory
  3: Remove Stock from Inventory
  4: Exit to Main Menu
  
Please enter your selection: )"
};

enum OptInventoryMenu {OPT_VIEWINVENTORY = 1, OPT_ADDINVENTORY, OPT_REMINVENTORY, OPT_EXITINVENTORY};

void displayMainMenu() { cout << MAINMENU; }
void displaySaleMenu() { cout << SALEMENU; }
void displayInventorymenu() { cout << INVENTORYMENU; }

void printReport(Inventory &inventory, double sales, double costs);
void saleMenu(Inventory &inventory, double &totalSales);
void inventoryMenu(Inventory &inventory, double &totalCost);

template <typename T>
void getValue(const string &input, T &value);

int main(int argc, const char * argv[]) {

  //generateCSV(INVENTORY_CSV);
  Inventory inventory(INVENTORY_CSV);
  //inventory.printContents();
  //inventory.writeCSV(ROUNDTRIP_CSV);
  
  string input;
  int selection = 0;
  double totalSales = 0, totalCost = 0;
  
  do {
    displayMainMenu();
    getline(cin, input);
    getValue(input, selection);
    
    if (selection >= OPT_SALE && selection <= OPT_EXIT) {
      switch (selection) {
        case OPT_SALE :
          saleMenu(inventory, totalSales);
          break;
        
        case OPT_REPORT :
          printReport(inventory, totalSales, totalCost);
          break;
        
        case OPT_INVENTORY :
          inventoryMenu(inventory, totalCost);
          break;
        
        default :
          break;
      }
    }
    else {
      cerr << "Error, please enter a valid selection." << endl << endl;
    }
  } while (selection != OPT_EXIT && !cin.fail());
  
  return 0;
}

void printReport(Inventory &inventory, double sales, double costs) {
  cout << endl << "Report: " << endl
       << endl << "  Total sales: $" << fixed << setprecision(2) << sales
  << endl << "  Total costs: $" << costs
  << endl << "  Total revenue: $" << (sales - costs) << endl << endl;
  cout << "  Low Stock Items:" << endl;
  inventory.printLowStock();
  cout << "  Out of Stock Items:" << endl;
  inventory.printOutOfStock();
}

void printMenu(Inventory &inventory) {
  cout << endl << "Menu: " << endl;
  inventory.printMenu();
}

template <typename T>
void getValue(const string &input, T &value) {
  stringstream ss;
  value = 0;
  ss.str(input);
  ss >> value;
}

void saleMenu(Inventory &inventory, double &totalSales) {
  int selection = 0;
  string input, name;
  double quantity = 0, price = 0;
  InventoryItem* item = nullptr;

  do {
    displaySaleMenu();
    getline(cin, input);
    getValue(input, selection);
    
    if (selection >= OPT_ENTERDRINK && selection <= OPT_EXITSALE) {
      switch (selection) {
        case OPT_LISTDRINKS :
          inventory.printMenu();
          break;
          
        case OPT_ENTERDRINK :
          inventory.printMenu();
          cout << endl << "Please enter item name: ";
          getline(cin, name);
          item = inventory.getItem(name);
          if (item) {
            cout << endl << "Please enter quantity: ";
            getline(cin, input);
            getValue(input, quantity);
            if (quantity >= 0 && item->isValidOrder(quantity)) {
              price = item->placeOrder(quantity);
              totalSales += price;
              cout << "Sale: $" << fixed << setprecision(2) << price << endl;
            }
            else {
              cerr << endl << "Invalid Quantity." << endl;
            }
          }
          else {
            cerr << endl << "Invalid Item Name." << endl;
          }
          break;
          
        default :
          break;
      }
    }
    else {
      cerr << "Error, please enter a valid selection. " << endl << endl;
    }
    item = nullptr;
  } while(selection != OPT_EXITSALE && !cin.fail());
}

void inventoryMenu(Inventory &inventory, double &totalCost) {
  int selection = 0;
  string input, name;
  double quantity = 0, cost = 0;
  InventoryItem* item = nullptr;

  do {
    displayInventorymenu();
    getline(cin, input);
    getValue(input, selection);
    
    if (selection >= OPT_VIEWINVENTORY && selection <= OPT_EXITINVENTORY) {
      switch(selection) {
        case OPT_VIEWINVENTORY :
          inventory.printContents();
          break;
          
        case OPT_ADDINVENTORY :
          cout << endl << "Please enter item name: ";
          getline(cin, name);
          item = inventory.getItem(name);
          if (item) {
            cout << endl << "Please enter amount to increase stock: ";
            getline(cin, input);
            getValue(input, quantity);
            if (quantity >= 0) {
              cost = item->addStock(quantity); 
              totalCost += cost;
              cout << "Cost: $" << fixed << setprecision(2) << cost << endl;
            }
            else {
              cerr << endl << "Invalid Quantity." << endl;
            }
          }
          else {
            cerr << endl << "Invalid Item Name." << endl;
          }
          break;
          
        case OPT_REMINVENTORY :
          cout << endl << "Please enter item name: ";
          getline(cin, name);
          item = inventory.getItem(name);
          if (item) {
            if (!item->isOutOfStock()) {
              cout << endl << "Please enter stock amount lost: ";
              getline(cin, input);
              getValue(input, quantity);
              if (quantity >= 0 && item->isValidStockLoss(quantity)) {
                item->loseStock(quantity);
                cout << "Item Stock has been updated: " << endl;
                item->print();
              }
              else {
                cerr << endl << "Invalid Quantity." << endl;
              }
            }
            else {
              cerr << "Error, this item is not in stock. " << endl;
            }
          }
          else {
            cerr << endl << "Invalid Item Name." << endl;
          }
          break;
      }
    }
    else {
      cerr << "Error, please enter a valid selection. " << endl << endl;
    }
    item = nullptr;
  } while (selection != OPT_EXITINVENTORY);
}





















void generateCSV(const string& filename) {
  stringstream csv;
  BeerItem beer("Lagunitas", 13, 10.99, 864);
  beer.print();
  beer.writeCSV(csv);
  csv << endl;
  
  WineItem wine("Meiomi Pinot Noir", 191, 2017, 15.99, 13.5);
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
