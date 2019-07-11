/*
 Accelerating...
 Toyota | 1998 | 5
 Accelerating...
 Toyota | 1998 | 10
 Accelerating...
 Toyota | 1998 | 15
 Braking...
 Toyota | 1998 | 10
 Braking...
 Toyota | 1998 | 5
 Braking...
 Toyota | 1998 | 0
 Braking... Error: can't brake a car that's standing still.
 Toyota | 1998 | 0
 */
//  main.cpp
//  CS200_Lab6_2_AccBrake
//
//  Created by Jessie Sully on 7/6/19.
//  Copyright © 2019 Jessie Sully. All rights reserved.
//

#include <iostream>
#include <sstream>
#include "Car.h"

void accelerate(Car &car);
void brake(Car &car);


int main(int argc, const char * argv[]) {
  Car car("Toyota", 1998);
  
  accelerate(car);
  accelerate(car);
  accelerate(car);
  
  brake(car);
  brake(car);
  brake(car);
  brake(car);
  
  return 0;
}

// printing with the correct format
void accelerate(Car &car) {
  stringstream output;
  cout << "Accelerating..." << endl;
  car.accelerate();
  car.writeStatus(output);
  cout << output.str() << endl << endl;
}

//printing with the correct format
void brake(Car &car) {
  stringstream output;
  cout << "Braking...";
  if (car.getSpeed() != 0) {
    car.brake();
  }
  else {
    cout << "Error: can't brake a car that's standing still." << endl;
  }
  car.writeStatus(output);
  cout << endl << output.str() << endl << endl;
}




