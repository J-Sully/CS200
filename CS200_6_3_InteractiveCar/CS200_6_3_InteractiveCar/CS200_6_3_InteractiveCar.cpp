//
//  main.cpp
//  CS200_6_3_InteractiveCar
//
//  Created by Jessie Sully on 7/7/19.
//  Copyright © 2019 Jessie Sully. All rights reserved.
//

#include <iostream>
#include <sstream>
#include "Car.h"

void accelerate(Car &car);
void brake(Car &car);
void printStatus(Car &car);

const string MAINMENU = { R"(
Enter:
  1 | Accelerate Car
  2 | Brake Car
  3 | Quit
Choice: )"
};

int main(int argc, const char * argv[]) {
  stringstream ss;
  string make, sYear, input;
  unsigned int year, selection;
  
  cout << "Please enter the make of your car: ";
  getline(cin, make);
  cout << endl << "Please enter the year of your car: ";
  getline(cin, sYear);
  ss.str(sYear);
  ss >> year;
  ss.clear();
  ss.str("");
  Car car = {make, year};
  
  printStatus(car);
  
  do {
    cout << MAINMENU;
    getline(cin, input);
    ss.str(input);
    ss >> selection;
    ss.clear();
    ss.str("");
    
    switch (selection) {
      case 1:
        accelerate(car);
        break;
      
      case 2:
        brake(car);
        break;
      
      case 3:
        cout << "Goodbye!" << endl;
        break;
      
      default:
        cout << endl << "Error, please enter a valid selection" << endl;
    }
  } while (selection != 3);
  
  return 0;
}

// printing with the correct format
void accelerate(Car &car) {
  cout << endl << "Accelerating..." << endl;
  car.accelerate();
  printStatus(car);
}

//printing with the correct format
void brake(Car &car) {
  cout << endl << "Braking...";
  if (car.getSpeed() != 0) {
    car.brake();
  }
  else {
    cout << "Error: can't brake a car that's standing still." << endl;
  }
  cout << endl;
  printStatus(car);
}

void printStatus(Car &car) {
  stringstream output;
  
  car.writeStatus(output);
  cout << "Current Status: " << endl << output.str() << endl;
  output.clear();
  output.str("");
}

