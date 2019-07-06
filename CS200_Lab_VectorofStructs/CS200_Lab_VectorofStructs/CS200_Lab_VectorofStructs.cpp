/* */
//  main.cpp
//  CS200_Exercise_STLvectors
//
//  Created by Jessie Sully on 6/27/19.
//  Copyright © 2019 Jessie Sully. All rights reserved.
//

#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

#include <random>

struct Color {
  unsigned char red;
  unsigned char green;
  unsigned char blue;
};

#define RANDOM_COLOR() static_cast<unsigned char>(colorValue(generator))

int main(int argc, const char * argv[]) {
  //ensures new set of numbers every time
  random_device rd;
  default_random_engine generator (rd());
  
  // generates number in the range 5 - 50
  uniform_int_distribution<> numColors(5,50);
  
  // generates number in the range 0 - 255
  uniform_int_distribution<> colorValue(0,255);
  
  vector<Color> colors;
  
  //fill vector
  for (int i = 0; i < numColors(generator); i++) {
    colors.push_back({RANDOM_COLOR(), RANDOM_COLOR(), RANDOM_COLOR()});
  }
  
  //set up column labels
  cout << left << setw(8) << "Color#"
       << setw(8) << "R value"
       << setw(8) << "G value"
       << setw(8) << "B value" << endl;
  
  cout << setw(8) << string(6, '-')
       << setw(8) << string(7, '-')
       << setw(8) << string(7, '-')
       <<  setw(8) << string(7, '-')
       << endl;
  
  // print out values
  for (int i = 0; i < colors.size(); i ++) {
    Color &color = colors.at(i);
    cout << setw(8) << i + 1
         << setw(8) << static_cast<int>(color.red)
         << setw(8) << static_cast<int>(color.green)
         << setw(8) << static_cast<int>(color.blue) << endl;
  }
  
  
  return 0;
}


