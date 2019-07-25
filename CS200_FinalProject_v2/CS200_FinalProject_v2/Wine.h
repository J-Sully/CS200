//
//  Wine.hpp
//  CS200_FinalProject_v2
//
//  Created by Jessie Sully on 7/24/19.
//  Copyright © 2019 Jessie Sully. All rights reserved.
//

#ifndef Wine_hpp
#define Wine_hpp

#include "AgedAlcoholicItem.h"
#include "Unit.h"

class WineItem : public AgedAlcoholicItem {
public:
  WineItem(const string &ID, double pricePerCase, unsigned int year, double unitsRemaining = 0, unsigned int thresholdCases = 2, double unitsPerServing = .15, double servingsPerBottle = 5, double bottlesPerCase = 12) :
  AgedAlcoholicItem(ID, pricePerCase, year, thresholdCases, Unit::LITERS, unitsRemaining, Alcohol::WINE, unitsPerServing, servingsPerBottle, bottlesPerCase) {}
  
  WineItem(istream &csvLine) : AgedAlcoholicItem() { readCSV(csvLine); setType(Alcohol::WINE);}
};

#endif /* Wine_hpp */