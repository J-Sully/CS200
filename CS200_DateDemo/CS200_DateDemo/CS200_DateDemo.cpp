//
//  main.cpp
//  CS200_DateDemo
//
//  Created by Jessie Sully on 7/5/19.
//  Copyright © 2019 Jessie Sully. All rights reserved.
//

#include <iostream>

#include "Date.h"

int main(int argc, const char * argv[]) {
  stringstream output;
  Date today(25, 12, 2014);
  
  today.getMilitaryDate(output);
  cout << output.str() << endl;
  output.clear();
  output.str("");
  
  today.getRegularDate(output);
  cout << output.str() << endl << endl;
  
  return 0;
}

