//
//  main.cpp
//  CS200_FinalExam
//
//  Created by Jessie Sully on 7/22/19.
//  Copyright © 2019 Jessie Sully. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

const string MAINMENU = { R"(
  Welcome to the Theater Menu:
  
  1: Enter a sale
  2: View Report
  3: Manage Inventory
  4: End Day
  
  Please enter your selection: )"
};
const int OPT_SALE = 1;
const int OPT_REPORT = 2;
const int OPT_INVENTORY = 3;
const int OPT_EXIT = 4;

const string SALEMENU = { R"(
  Welcome to the Sale Menu:
  
  1: View Drink List
  2: Enter Drink Sale
  3: Exit to Main Menu
  
  Please enter your selection: )"
};

const int OPT_LISTDRINKS = 1;
const int OPT_ENTERDRINK = 2;
const int OPT_EXITSALE = 3;

const string INVENTORYMENU = { R"(
  Welcome to the Inventory Menu:
  
  1: View Inventory
  2: Add Stock Items to Inventory
  3: Remove Stock from Inventory
  4: Exit to Main Menu
  
  Please enter your selection: )"
};

const int OPT_VIEWINVENTORY = 1;
const int OPT_ADDINVENTORY = 2;
const int OPT_REMINVENTORY = 3;
const int OPT_EXITINVENTORY = 4;

void displayMainMenu() { cout << MAINMENU; }
void displaySaleMenu() { cout << SALEMENU; }
void displayInventorymenu() { cout << INVENTORYMENU; }

int main(int argc, const char * argv[]) {
  // insert code here...
  std::cout << "Hello, World!\n";
  return 0;
}
