//
//  main.cpp
//  CS200_FinalExam
//
//  Created by Jessie Sully on 7/22/19.
//  Copyright © 2019 Jessie Sully. All rights reserved.
//

#include <iostream>

#include "AlcoholicItem.h"

using namespace std;

int main(int argc, const char * argv[]) {
  BeerItem beer("Lagunitas", 13, 4);
  beer.print();
  
  WineItem wine("Meiomi Pinot Noir", 191, 2017);
  wine.print();
  
  SpiritItem spirit("Orendain Tequila Blanco", 180, 2019);
  spirit.print();
  
  NonAlcoholicItem pretzels("Snyder's of Hanover Snaps Pretzels", 6.59, 3, OUNCES, 50, 1.06383);
  pretzels.print();
  
  return 0;
}
