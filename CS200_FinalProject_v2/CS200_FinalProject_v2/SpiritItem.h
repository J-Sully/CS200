//
//  SpiritItem.h
//  CS200_FinalProject_v2
//
//  Created by Jessie Sully on 7/24/19.
//  Copyright © 2019 Jessie Sully. All rights reserved.
//

#ifndef SPIRITITEM_H
#define SPIRITITEM_H

#include "AgedAlcoholicItem.h"
#include "Unit.h"

/*
 -----------------------
 SpiritItem : AgedAlcoholicItem
 -----------------------
 + SpiritItem(ID : string, pricePerCase : double, year : unsigned int,
 servingPrice : double, unitsRemaining : double, thresholdCases : double,
 unitsPerServing : double, servingsPerBottle : double, bottlesPerCase : double)
 + SpiritItem(csvLine : istream)
 ----------------------
 */

class SpiritItem : public AgedAlcoholicItem {
public:
  SpiritItem(const string &ID, double pricePerCase, unsigned int year,
             double servingPrice, double unitsRemaining = 0,
             double thresholdCases = 2, double unitsPerServing = .0375,
             double servingsPerBottle = 20, double bottlesPerCase = 12) :
  AgedAlcoholicItem(ID, pricePerCase, year, thresholdCases, Unit::LITERS,
                    servingPrice, unitsRemaining, Alcohol::SPIRIT, unitsPerServing,
                    servingsPerBottle, bottlesPerCase) {}
  
  SpiritItem(istream &csvLine) : AgedAlcoholicItem() { readCSV(csvLine); setType(Alcohol::SPIRIT);}
};

#endif /* SPIRITITEM_H */
