/* Write a simple program that pushes 25 random integers (you select
 the range) into a vector. Write a function that receives the vector
 as a parameter. Make that function add up all of the odd numbers in
 the vector and return the sum. */
//  main.cpp
//  CS200_Exercise_STLvectors
//
//  Created by Jessie Sully on 6/27/19.
//  Copyright © 2019 Jessie Sully. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

#include <random>

const int NUMVALUES = 25;

int sumOdd(vector<int> &);

int main(int argc, const char * argv[]) {
  //ensures new set of numbers every time
  random_device rd;
  default_random_engine generator (rd());
  // generates number in the range 1 - 10
  uniform_int_distribution<> distribution(1,10);
  
  vector<int> values;
  
  //fill vector
  for (int i = 0; i < NUMVALUES; i++) {
    
    values.push_back(distribution(generator));
  }
  
  cout << sumOdd(values) << endl;
  
  return 0;
}


//sum values
int sumOdd(vector<int> &values) {
  int sum = 0;
  
  for (int i : values) {
    sum += i % 2 == 0 ? 0 : i;
  }
  return sum;
}

