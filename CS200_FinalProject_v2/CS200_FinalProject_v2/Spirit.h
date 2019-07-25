//
//  Spirit.hpp
//  CS200_FinalProject_v2
//
//  Created by Jessie Sully on 7/24/19.
//  Copyright © 2019 Jessie Sully. All rights reserved.
//

#ifndef Spirit_hpp
#define Spirit_hpp

#include "AgedAlcoholicItem.h"
#include "Unit.h"

class SpiritItem : public AgedAlcoholicItem {
public:
  SpiritItem(const string &ID, double pricePerCase, unsigned int year, double unitsRemaining = 0, unsigned int thresholdCases = 2, double unitsPerServing = .0375, double servingsPerBottle = 20, double bottlesPerCase = 12) :
  AgedAlcoholicItem(ID, pricePerCase, year, thresholdCases, Unit::LITERS, unitsRemaining, Alcohol::WINE, unitsPerServing, servingsPerBottle, bottlesPerCase) {}
  
  SpiritItem(istream &csvLine) : AgedAlcoholicItem() { readCSV(csvLine); setType(Alcohol::SPIRIT);}
};

#endif /* Spirit_hpp */
