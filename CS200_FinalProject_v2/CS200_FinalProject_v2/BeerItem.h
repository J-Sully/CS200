//
//  BeerItem.h
//  CS200_FinalProject_v2
//
//  Created by Jessie Sully on 7/23/19.
//  Copyright © 2019 Jessie Sully. All rights reserved.
//

#ifndef BEERITEM_H
#define BEERITEM_H

#include "AlcoholicItem.h"
#include "Unit.h"

/*
 -----------------------
 BeerItem : AlcoholicItem
 -----------------------
 + BeerItem(ID : string, pricePerCase : double, servingPrice : double,
 unitsRemaining : double, thresholdCases : double, unitsPerServing : double,
 bottlesPerCase : double)
 + BeerItem(csvLine : istream)
 ----------------------
 */

class BeerItem : public AlcoholicItem {
public:
  BeerItem(const string &ID, double pricePerCase, double servingPrice,
           double unitsRemaining = 0, double thresholdCases = 2,
           double unitsPerServing = 12, double bottlesPerCase = 24) :
  AlcoholicItem(ID, pricePerCase, thresholdCases, servingPrice, unitsRemaining,
                Unit::OUNCES, Alcohol::BEER, unitsPerServing, 1, bottlesPerCase) {}
  
  BeerItem(istream &csvLine) : AlcoholicItem()
    { readCSV(csvLine); setType(Alcohol::BEER);}  
};

#endif /* BEERITEM_H */
