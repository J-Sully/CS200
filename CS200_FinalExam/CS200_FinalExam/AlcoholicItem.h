//
//  AlcoholicItem.h
//  CS200_FinalExam
//
//  Created by Jessie Sully on 7/22/19.
//  Copyright © 2019 Jessie Sully. All rights reserved.
//

#ifndef ALCOHOLICITEM_H
#define ALCOHOLICITEM_H

#include "InventoryItem"

class AlcholicItem : public InventoryItem {
public:
  AlcoholicItem() {}
  AlcoholicItem(const string &ID, double price, unsigned int threshold, const string &unit, double taxRate, unsigned int stockBottles, unsigned int ozOpenBottle) : InventoryItem(ID, quantity, price, threshold, unit, taxRate) : mStockBottles(stock), mOzOpenBottle(ozOpenBottle) { setTaxRate(taxRate); }
  
  void setTaxRate (double taxRate) { if (taxRate >= 0) mTaxRate = taxRate; }
  void setStockBottles (unsigned int stockBottles) { mStockBottles = stockBottles; }
  void setOzOpenBottle (double ozOpenBottle) { if (ozOpenBottle >= 0 && ozOpenBottle - mNumOzInLiter <= 0) mOzOpenBottle = ozOpenBottle;}
  
  double getTaxRate() { return mTaxRate; }
  unsigned int getStockBottles { return mStockBottles; }
  double getOzOpenBottle { return mOzOpenBottle }

private:
  static string mStandardVolumePurch = "liter";
  static string mStandardVolumeServe = "ounces";
  static double mNumOzInLiter = 33.8140226;
  double mTaxRate = 0;
  unsigned int mStockBottles = 0;
  double mOzOpenBottle = 0;
}

#endif /* ALCOHOLICITEM_H */
