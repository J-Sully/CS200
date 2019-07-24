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

int main(int argc, const char * argv[]) {
  Unit::Type unit = Unit::OUNCES;
  NonAlcoholicItem pretzels("Pretzels", 10.99, 1, Unit::OUNCES, 20, 50, 5);
  pretzels.print();
  
  return 0;
}
