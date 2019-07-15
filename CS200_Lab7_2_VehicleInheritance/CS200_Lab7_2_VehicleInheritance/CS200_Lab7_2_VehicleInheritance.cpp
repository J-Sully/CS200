//
//  main.cpp
//  CS200_Lab7_2_VehicleInheritance
//
//  Created by Jessie Sully on 7/10/19.
//  Copyright © 2019 Jessie Sully. All rights reserved.
//
#include <iostream>

#include "Sedan.h"

int main(int argc, const char * argv[]) {
  Vehicle car(1992, 40000);
  Sedan yaris(1994, 50500, 4, true);
  
  cout << "Information about Vehicle Car:" << endl;
  car.print();
  
  cout << "Information about Sedan Yaris:" << endl;
  yaris.print();
  
  return 0;
}
