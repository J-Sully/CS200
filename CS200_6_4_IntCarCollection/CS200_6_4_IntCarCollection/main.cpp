//
//  main.cpp
//  CS200_6_4_IntCarCollection
//
//  Created by Jessie Sully on 7/8/19.
//  Copyright © 2019 Jessie Sully. All rights reserved.
//

#include <iostream>
#include <sstream>
#include <vector>
#include <float.h>

#include "Car.h"

void printCars (const vector<Car> &collection);
int getCarSelectionInput(const vector<Car>& carCollection, const string& operation);

const string MAINMENU = { R"(
Enter:
  1 | Print complete car collection
  2 | Add a car to the collection
  3 | Remove a car from the collection
  4 | Accelerate a car
  5 | Brake a car
  6 | Quit
Choice: )"
};

enum operation { PRINTOP = 1, ADDOP, REMOP, ACCOP, BRAKEOP, QUITOP };
const int CANCELOP = -1;
const int INVALIDOP = -2;

int main(int argc, const char * argv[]) {
  stringstream output;
  stringstream ss;
  string make, sYear, input;
  unsigned int year, selection;
  int index;
  vector<Car> carCollection;
  
  do {
    selection = 0;
    cout << MAINMENU;
    getline(cin, input);
    ss.str(input);
    ss >> selection;
    ss.clear();
    ss.str("");
    
    
    switch (selection) {
      case PRINTOP:
        if (!carCollection.empty()) {
          printCars(carCollection);
        }
        else {
          cout << endl << "Error, there are no cars in collection" << endl;
        }
        break;
        
      case ADDOP:
        cout << endl << "Please enter the make of your car: ";
        getline(cin, make);
        cout << "Please enter the year of your car: ";
        getline(cin, sYear);
        ss.str(sYear);
        year = 0;
        ss >> year;
        
        carCollection.emplace_back(make, year);
        printCars(carCollection);
        break;
        
      case REMOP:
        if (!carCollection.empty()) {
          index = getCarSelectionInput(carCollection, "remove");
          if (index != CANCELOP) {
            carCollection.erase(carCollection.begin() + index);
            cout << endl << "Car " << (index+1) << " has been removed" << endl;
            
            if (carCollection.empty()) {
              cout << "There are no cars in Collection" << endl;
            }
            else {
              printCars(carCollection);
            }
          }
        }
        else {
          cout << endl << "Error, there are no cars in collection" << endl;
        }
        break;
    
      case ACCOP:
        if (!carCollection.empty()) {
          index = getCarSelectionInput(carCollection, "accelerate");
          
          if (index != CANCELOP) {
            carCollection.at(index).accelerate();
            cout << endl << "Car " << (index+1)
                 << " has been accelerated.  New speed "
                 << carCollection.at(index).getSpeed() << " mph" << endl;
            printCars(carCollection);
          }
        }
        else {
          cout << endl << "Error, there are no cars in collection" << endl;
        }
        break;
    
      case BRAKEOP :
        if (!carCollection.empty()) {
          index = getCarSelectionInput(carCollection, "brake");
          
          if (index != CANCELOP) {
            if (carCollection.at(index).getSpeed() > DBL_EPSILON) {
              carCollection.at(index).brake();
              cout << endl << "Car " << (index+1)
              << " is braking.  New speed "
              << carCollection.at(index).getSpeed() << " mph" << endl;
              printCars(carCollection);
            }
            else {
              cout << "Error, cannot brake stopped car" << endl;
            }
          }
        }
        else {
          cout << endl << "Error, there are no cars in collection" << endl;
        }
        break;
      
      case QUITOP :
        cout << "Goodbye!" << endl;
        break;
        
      default:
        cout << endl << "Error, please enter a valid selection" << endl;
        break;
    }

    ss.clear();
    ss.str("");
    
  } while (selection != QUITOP);
  
  return 0;
}

void printCars (const vector<Car> &collection) {
  stringstream output;
  
  for (int i=0; i < collection.size(); i++) {
    collection.at(i).writeStatus(output);
    cout << i + 1 << ": " << output.str() << endl;
    output.clear();
    output.str("");
  }
}

int getCarSelectionInput(const vector<Car>& carCollection, const string& operation) {
  int selection;
  string input;
  stringstream ss;
  do {
    selection = INVALIDOP;
    printCars(carCollection);
    // add an option to cancel operation
    cout << carCollection.size()+1 << ": Cancel operation" << endl;
    cout << endl << "Please enter car to " << operation << ": ";
    getline(cin, input);
    ss.str(input);
    ss >> selection;
    ss.clear();
    ss.str("");
    selection--;
    
    if (selection == carCollection.size()) {
      selection = CANCELOP;
    }
    else if (selection < 0 || selection >= carCollection.size() ) {
      cout << "Error in input, please try again." << endl;
      selection = INVALIDOP;
    }
  } while (selection == INVALIDOP);
  return selection;
}
