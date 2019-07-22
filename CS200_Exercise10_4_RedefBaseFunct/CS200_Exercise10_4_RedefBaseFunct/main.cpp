//
//  main.cpp
//  CS200_Exercise10_4_RedefBaseFunct
//
//  Created by Jessie Sully on 7/22/19.
//  Copyright © 2019 Jessie Sully. All rights reserved.
//

#include "Theater.h"

int main(int argc, const char * argv[]) {
  /*  Theater(const string &type, unsigned int year, unsigned int capacity, double basePrice,
   string &name, string &address, double avgConcessionSales)
   */
  
  Venue house("private", 1965, 35, 75);
  Theater theatre("private", 1930, 200, 20, "Theatre de Musique", "5000 MacArthur Blvd, Oakland CA 94511", 2352);
  house.print();
  theatre.print();
  
  return 0;
}
