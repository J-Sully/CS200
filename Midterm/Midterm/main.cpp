//
//  main.cpp
//  Midterm
//
//  Created by Jessie Sully on 7/14/19.
//  Copyright © 2019 Jessie Sully. All rights reserved.
//

#include <vector>
#include <iostream>

#include "Ferry.h"
#include "NavyShip.h"

template<typename T>
void printData(vector<T> &ships);

int main(int argc, const char * argv[]) {
  vector<Ferry> ferries;
  vector<NavyShip> navyShips;
  
  ferries.emplace_back("US", "Seattle", "Walla Walla", 440, 4860, 2000, 188, "Edmonds", "Kingston", 35.95);
  ferries.emplace_back("US", "Seattle", "Samish", 362, 4320, 1500, 144, "Anacortes", "Friday Harbor", 45.95);
  
  navyShips.emplace_back("US", "Yokosuka", "USS John McCain", 505, 8900, "Destroyer", "DDG-56", 281, false, 35);
  navyShips.emplace_back("US", "Yokosuka", "USS Ronald Reagan", 1092, 101400, "Aircraft Carrier", "CVN-75", 3532, true, 40);
  
  printData(ferries);
  printData(navyShips);
  
  
  return 0;
}

template<typename T>
void printData(vector<T> &ships) {
  for (T s : ships) {
    s.print();
  }
}
