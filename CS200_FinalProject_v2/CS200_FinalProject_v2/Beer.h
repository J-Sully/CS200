//
//  Beer.hpp
//  CS200_FinalProject_v2
//
//  Created by Jessie Sully on 7/23/19.
//  Copyright © 2019 Jessie Sully. All rights reserved.
//

#ifndef Beer_hpp
#define Beer_hpp

#include "AlcoholicItem.h"
#include "Unit.h"

class BeerItem : public AlcoholicItem {
public:
  BeerItem(const string &ID, double pricePerCase, double thresholdCases = 2,
           double unitsPerServing = 12, double bottlesPerCase = 24,
           double unitsRemaining = 0) :
  AlcoholicItem(ID, pricePerCase, thresholdCases, Unit::OUNCES, unitsRemaining, Alcohol::BEER, unitsPerServing, 1, bottlesPerCase) {}
  
  BeerItem(istream &csvLine) : AlcoholicItem() { readCSV(csvLine); setType(Alcohol::BEER);}  
};

#endif /* Beer_hpp */