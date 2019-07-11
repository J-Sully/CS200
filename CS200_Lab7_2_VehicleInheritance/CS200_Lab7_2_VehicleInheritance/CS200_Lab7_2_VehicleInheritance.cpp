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
  stringstream output;
  Vehicle car(1992, 40000);
  Sedan yaris(1994, 50500, 4, true);
  
  cout << "Information about Vehicle Car:" << endl;
  car.writeStatus(output);
  cout << output.str() << endl << endl;
  output.clear();
  output.str("");
  
  cout << "Information about Sedan Yaris:" << endl;
  yaris.print(output);
  cout << output.str() << endl;
  
  return 0;
}
