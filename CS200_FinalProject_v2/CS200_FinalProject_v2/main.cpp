//
//  main.cpp
//  CS200_FinalProject_v2
//
//  Created by Jessie Sully on 7/23/19.
//  Copyright © 2019 Jessie Sully. All rights reserved.
//
#include <iostream>

#include "NonAlcoholicItem.h"
#include "BeerItem.h"
#include "WineItem.h"
#include "SpiritItem.h"
#include "Inventory.h"

using namespace std;

static const string INVENTORY_CSV = "inventory.csv";

const string MAINMENU = { R"(
Welcome to the Main Menu:
  
  1: Enter a sale
  2: View Report
  3: Manage Inventory
  4: Exit
  
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
  
  1: View Inventory Details
  2: Add Stock Items to Inventory
  3: Remove Stock from Inventory
  4: Exit to Main Menu
  
Please enter your selection: )"
};

enum OptInventoryMenu {OPT_VIEWINVENTORY = 1, OPT_ADDINVENTORY,
                       OPT_REMINVENTORY, OPT_EXITINVENTORY};

void displayMainMenu() { cout << MAINMENU; }
void displaySaleMenu() { cout << SALEMENU; }
void displayInventorymenu() { cout << INVENTORYMENU; }

void printReport(Inventory &inventory, double totalSales, double totalCosts,
                 double totalPurchases);
void saleMenu(Inventory &inventory, double &totalSales, double & totalCosts);
void inventoryMenu(Inventory &inventory, double &totalPurchases, double &totalCosts);

template <typename T>
void getValue(const string &input, T &value);
void printInventory(const Inventory &inventory);
void printMenu(const vector<InventoryItem*> &menuItems);

void generateInventory(Inventory &inventory);

int main(int argc, const char * argv[]) {
  Inventory inventory;
  string input;
  int selection = 0;
  double totalSales = 0, totalCosts = 0, totalPurchases = 0;
  
  if(!inventory.readCSV(INVENTORY_CSV)) {
    generateInventory(inventory);
  }
  
  do {
    displayMainMenu();
    getline(cin, input);
    getValue(input, selection);
    
    if (selection >= OPT_SALE && selection <= OPT_EXIT) {
      switch (selection) {
        case OPT_SALE :
          saleMenu(inventory, totalSales, totalCosts);
          break;
        
        case OPT_REPORT :
          printReport(inventory, totalSales, totalCosts, totalPurchases);
          break;
        
        case OPT_INVENTORY :
          inventoryMenu(inventory, totalPurchases, totalCosts);
          break;
        
        default :
          break;
      }
    }
    else {
      cerr << "Error, please enter a number between " << OPT_SALE << " and "
           << OPT_EXIT << '.' << endl;
    }
  } while (selection != OPT_EXIT && !cin.fail());
  
  inventory.writeCSV(INVENTORY_CSV);
  cout << endl << "Have a Great Day!" << endl;
  return 0;
}

void generateInventory(Inventory &inventory) {
  inventory.addItem(new BeerItem("Lagunitas", 21.99, 10.99, 864));
  inventory.addItem(new WineItem("Meiomi Pinot Noir", 191, 2017, 15.99, 13.5));
  inventory.addItem(new SpiritItem("Orendain Tequila Blanco", 180, 2019, 9.99));
  inventory.addItem(new NonAlcoholicItem("Snyder's of Hanover Snaps Pretzels",
                                         6.59, 3, Unit::OUNCES, 2.99, 50, 1.06383));
}

void printReport(Inventory &inventory, double sales, double costs, double purchases) {
  cout << endl << "Report: " << endl
       << endl << "  Total sales: $" << fixed << setprecision(2) << sales
  << endl << "  Total costs: $" << costs
  << endl << "  Total revenue: $" << (sales - costs) << endl
  << endl << "  Total purchases: $" << purchases << endl << endl;
  cout << "  Low Stock Items:" << endl;
  inventory.printLowStock();
  cout << "  Out of Stock Items:" << endl;
  inventory.printOutOfStock();
}

void printMenu(const vector<InventoryItem*> &menuItems) {
  cout << endl << "Menu: " << endl;
  for (int i = 0; i < menuItems.size(); i++) {
    cout << '\t' << i + 1 << " - ";
    menuItems.at(i)->printDrinkListing();
  }
}

void printInventory(const Inventory &inventory) {
  cout << endl << "Inventory List: " << endl;
  inventory.printInventoryList();
}

template <typename T>
void getValue(const string &input, T &value) {
  stringstream ss;
  value = 0;
  ss.str(input);
  ss >> value;
}

void saleMenu(Inventory &inventory, double &totalSales, double & totalCosts) {
  int selection = 0, index = 0;
  string input, name;
  double quantity = 0, price = 0, cost = 0;
  InventoryItem* item = nullptr;
  vector<InventoryItem*> menuItems;

  do {
    displaySaleMenu();
    getline(cin, input);
    getValue(input, selection);
    
    if (selection >= OPT_LISTDRINKS && selection <= OPT_EXITSALE) {
      inventory.getInStockItems(menuItems);
      switch (selection) {
        case OPT_LISTDRINKS :
          printMenu(menuItems);
          break;
          
        case OPT_ENTERDRINK :
          printMenu(menuItems);
          cout << endl << "Please enter item number: ";
          getline(cin, input);
          getValue(input, index);
          index--;
          if (index >= 0 && index < menuItems.size()) {
            item = menuItems.at(index);
            cout << endl << "Please enter quantity: ";
            getline(cin, input);
            getValue(input, quantity);
            if (quantity >= 0 && item->isValidOrder(quantity)) {
              price = item->placeOrder(cost, quantity);
              totalSales += price;
              totalCosts += cost;
              cout << endl << "Sale: $" << fixed << setprecision(2) << price
                   << endl << "Cost: $" << cost << endl << endl;;
            }
            else {
              cerr << endl << "Invalid Quantity. Max servings: "
                   << item->getServingsRemaining() << endl;
            }
          }
          else {
            cerr << endl << "Invalid Item Number: Please enter number between 1 and "
                 << menuItems.size() << endl;
          }
          break;
          
        default :
          break;
      }
    }
    else {
      cerr << "Error, please enter a number between " << OPT_LISTDRINKS
           << " and " << OPT_EXITSALE << '.' << endl;
    }
    item = nullptr;
  } while(selection != OPT_EXITSALE && !cin.fail());
}

void inventoryMenu(Inventory &inventory, double &totalPurchases, double &totalCosts) {
  int selection = 0, index = 0;
  string input, name;
  double quantity = 0, cost = 0, purchase = 0;
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
          inventory.printLowStock();
          inventory.printOutOfStock();
          printInventory(inventory);
          cout << endl << "Please enter item number: ";
          getline(cin, input);
          getValue(input, index);
          index--;
          if (index >= 0 && index < inventory.getNumItems()) {
            item = inventory.getItem(index);
            cout << endl << "Please enter amount of stock to purchase: ";
            getline(cin, input);
            getValue(input, quantity);
            if (quantity >= 0) {
              purchase = item->addStock(quantity);
              totalPurchases += purchase;
              cout << endl << "Purchase: $" << fixed << setprecision(2)
                   << purchase << endl
              << endl << "Updated Item Listing: " << endl;
              item->printInventoryListing();
            }
            else {
              cerr << endl << "Invalid Quantity: Amount must be a positive value. "
                   << endl;
            }
          }
          else {
            cerr << endl << "Invalid Item Number: Must be a number between 1 and "
                 << inventory.getNumItems() << endl;
          }
          break;
          
        case OPT_REMINVENTORY :
          printInventory(inventory);
          cout << endl << "Please enter item number: ";
          getline(cin, input);
          getValue(input, index);
          index--;
          if (index >= 0 && index < inventory.getNumItems()) {
            item = inventory.getItem(index);
            if (!item->isOutOfStock()) {
              cout << endl << "Please enter amount of stock lost (maximum: " << item->getStockRemaining() << "): ";
              getline(cin, input);
              getValue(input, quantity);
              if (quantity >= 0 && item->isValidStockLoss(quantity)) {
                cost = item->loseStock(quantity);
                totalCosts += cost;
                cout << endl << "Loss cost: " << cost << endl
                     << "Updated Item Listing:" << endl;
                item->print();
              }
              else {
                cerr << endl << "Invalid Quantity: Maximum amount: "
                     << item->getStockRemaining() << endl;
              }
            }
            else {
              cerr << "Error, this item is not in stock. " << endl;
            }
          }
          else {
            cerr << endl << "Invalid Item Number: Must be a number between 1 and "
                 << inventory.getNumItems() << endl;
          }
          break;
        
        default:
          break;
      }
    }
    else {
      cerr << "Error, please enter a number between " << OPT_VIEWINVENTORY
           << " and " << OPT_EXITINVENTORY << '.' << endl;
    }
    item = nullptr;
  } while (selection != OPT_EXITINVENTORY);
}


