//
//  Car.cpp
//  CS200_Exercise_Constructors
//
//  Created by Jessie Sully on 7/5/19.
//  Copyright © 2019 Jessie Sully. All rights reserved.
//

#include "Car.h"

Car::Car(){
  make = "";
  year = 0;
}

Car::Car(string m){
  make = m;
  year = 0;
}

Car::Car(unsigned int y){
  make = "";
  year = y;
}

Car::Car(string m, unsigned int y = 0){
  make = m;
  year = y;
}


