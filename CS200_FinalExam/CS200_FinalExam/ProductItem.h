//
//  ProductItem.hpp
//  CS200_FinalExam
//
//  Created by Jessie Sully on 7/22/19.
//  Copyright © 2019 Jessie Sully. All rights reserved.
//

#ifndef PRODUCTITEM_H
#define PRODUCTITEM_H

#include <vector>

#include "AlcoholicItem.h"

class ProductItem : public Entry {
  ProductItem() {}
  ProductItem(const string &ID, double price, const vector<AlcoholicItem> &ingredientList) : Entry(ID, price) { setIngredientList(ingredientList); }
  
  void setIngredientList(const vector<AlcoholicItem> &ingredientList) { if (!ingredientList.empty()) mIngredientList.assign(ingredientList.first(), ingredientList.end())}
  
  const vector<AlcoholicItem>& getIngredientList() { return mIngredientList; }
private:
  vector<AlcoholicItem> mIngredientList;
}

#endif /* PRODUCTITEM_H */
