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
  
  1: View Drink List
  2: Enter Drink Sale
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

void printReport(Inventory &inventory, double revenue);





int main(int argc, const char * argv[]) {

  //generateCSV(INVENTORY_CSV);
  Inventory inventory(INVENTORY_CSV);
  //inventory.printContents();
  //inventory.writeCSV(ROUNDTRIP_CSV);
  
  stringstream ss;
  string input, name;
  unsigned int dummy = 0;
  int selection = 0;
  double quantity = 0, price = 0;
  double totalSales = 0;
  
  
  do {
    ss.clear();
    ss.str("");
    
    displayMainMenu();
    getline(cin, input);
    ss.str(input);
    ss >> selection;
    
    if (selection != 0) {
      switch (selection) {
        case OPT_SALE :
          do {
            selection = 0;
            displaySaleMenu();
            ss.str("");
            ss.clear();
            getline(cin, input);
            ss.str(input);
            ss >> selection;
            
            if (selection != 0) {
              switch (selection) {
                case OPT_LISTDRINKS :
                  inventory.printMenu();
                  break;
                
                case OPT_ENTERDRINK :
                  inventory.printMenu();
                  cout << endl << "Please enter drink name: ";
                  getline(cin, name);
                  if (inventory.validateName(name, dummy)) {
                    cout << endl << "Please enter quantity: ";
                    getline(cin, input);
                    ss.str("");
                    ss.clear();
                    ss.str(input);
                    ss >> quantity;
                    if (quantity >= 0 && inventory.placeOrder(name, price, quantity)) {
                      totalSales += price;
                      cout << "Total: $" << fixed << setprecision(2) << price << endl;
                    }
                    else {
                      cerr << endl << "Invalid Quantity." << endl;
                    }
                  }
                  else {
                    cerr << endl << "Invalid Drink Name." << endl;
                  }
                  break;
                
                default :
                  break;
              }
            }
            else {
              cerr << "Error, please enter a valid selection. " << endl << endl;
            }
            
          } while(selection != OPT_EXITSALE && !cin.fail());
          break;
        
        case OPT_REPORT :
          printReport(inventory, totalSales);
          break;
        
        case OPT_INVENTORY :
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

void printReport(Inventory &inventory, double revenue) {
  cout << endl << "Report: " << endl
       << endl << "  Today's total revenue is: $" << fixed << setprecision(2)
       << revenue << endl << endl;
  cout << "  Low Stock Items:" << endl;
  inventory.printLowStock();
  cout << "  Out of Stock Items:" << endl;
  inventory.printOutOfStock();
}

void printMenu(Inventory &inventory) {
  cout << endl << "Menu: " << endl;
  inventory.printMenu();
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
