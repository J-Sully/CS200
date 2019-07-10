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
#include "Car.h"

void printCars (const vector<Car> &collection);

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

int main(int argc, const char * argv[]) {
  stringstream ss;
  string make, sYear, input;
  unsigned int year, selection;
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
        year = 0;
        cout << endl << "Please enter the make of your car: ";
        getline(cin, make);
        cout << endl << "Please enter the year of your car: ";
        getline(cin, sYear);
        ss.str(sYear);
        ss >> year;
        
        carCollection.emplace_back(make, year);
        
        printCars(carCollection);
        break;
        
      case REMOP:
        if (!carCollection.empty()) {
          do {
            selection = 0;
            printCars(carCollection);
            cout << endl << "Please enter car to remove: ";
            getline(cin, input);
            ss.str(input);
            ss >> selection;
            ss.clear();
            ss.str("");
            
            if (selection <= carCollection.size() && selection != 0) {
              carCollection.erase(carCollection.begin() + selection - 1);
              cout << endl << "Car " << selection << " has been removed" << endl;
            }
            else {
              cout << "Error in input, please try again." << endl;
              selection = 0;
            }
          } while (selection > carCollection.size() + 1 || selection == 0);
          
          if (carCollection.empty()) {
            cout << "There are no cars in Collection" << endl;
          }
          else {
            printCars(carCollection);
          }
        }
        else {
          cout << endl << "Error, there are no cars in collection" << endl;
        }
        
        break;
    
    case ACCOP:
        if (carCollection.size() >= 1) {
          do {
            selection = 0;
            printCars(carCollection);
            cout << endl << "Please enter car to accelerate: ";
            getline(cin, input);
            ss.str(input);
            ss >> selection;
            ss.clear();
            ss.str("");
            
            if (selection <= carCollection.size() && selection != 0) {
              carCollection.at(selection - 1).accelerate();
              cout << endl << "Car " << selection
                   << " has been accelerated, the new speed is "
                   << carCollection.at(selection - 1).getSpeed() << " mph" << endl;
              printCars(carCollection);
            }
            else {
              cout << "Error in input, please try again." << endl;
              selection = 0;
            }
          } while (selection > carCollection.size() || selection == 0);
        }
        else {
          cout << endl << "Error, there are no cars in collection" << endl;
        }
        
        break;
    
    case BRAKEOP :
        if (carCollection.size() >= 1) {
          do {
            selection = 0;
            printCars(carCollection);
            cout << endl << "Please enter car to brake: ";
            getline(cin, input);
            ss.str(input);
            ss >> selection;
            ss.clear();
            ss.str("");
            
            if (selection <= carCollection.size() && selection != 0) {
              if (carCollection.at(selection - 1).getSpeed() > 0) {
                carCollection.at(selection - 1).brake();
                cout << endl << "Car " << selection << " is braking, the new speed is "
                << carCollection.at(selection - 1).getSpeed() << " mph" << endl;
                printCars(carCollection);
              }
              else {
                cout << "Error, cannot brake stopped car" << endl;
              }
            }
            else {
              cout << "Error in input, please try again." << endl;
              selection = 0;
            }
          } while (selection > carCollection.size() || selection == 0);
        }
        else {
          cout << endl << "Error, there are no cars in collection" << endl;
        }
        
        break;
      
    case QUITOP :
        cout << "Goodbye!";
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
    cout << endl << i + 1 << ": " << output.str();
    output.clear();
    output.str("");
  }
}
