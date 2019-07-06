/* Write a short program that initializes a 10-element integer array
 to random values in the range of 0-99. Write a function that receives
 an integer array as a parameter and returns the highest value found
 in the array. Send your array to this function and output the highest
 value found in the array. */
//  main.cpp
//  CS200_Exercise_STLvectors
//
//  Created by Jessie Sully on 6/27/19.
//  Copyright © 2019 Jessie Sully. All rights reserved.
//

#include <iostream>
using namespace std;

#include <random>

const int NUMVALUES = 10;

int findMax(int [], int size);

int main(int argc, const char * argv[]) {
  //ensures new set of numbers every time
  random_device rd;
  default_random_engine generator (rd());
  // generates number in the range 1 - 99
  uniform_int_distribution<> distribution(1,99);
  
  int values[NUMVALUES];
  
  //fill array
  for (int i = 0; i < NUMVALUES; i++) {
    
    values[i] = distribution(generator);
  }
  
  cout << findMax(values, NUMVALUES) << endl;

  return 0;
}


//find maximum values from an array of ints
int findMax(int values[], int size) {
  int max = INT_MIN;
  for (int i = 0; i < size; i++) {
    
    if (values[i] > max) {
      max = values[i];
    }
  }
  return max;
}
