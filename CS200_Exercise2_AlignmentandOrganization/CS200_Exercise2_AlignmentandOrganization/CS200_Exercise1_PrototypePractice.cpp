
//  main.cpp
//  CS200_Assignment1_v2
//
//  Created by Jessie Sully on 6/21/19.
//  Copyright © 2019 Jessie Sully. All rights reserved.
//

// CS200_Exercise1_PrototypePractice

#include <iostream>
#include <string>
using namespace std;

//function to print out intro based on info received
void fullIntro (string&, string&);

int main(int argc, const char * argv[]) {
  string fName, lName, intro;
    
  //get first name
  cout << "Please enter a first name: ";
  getline(cin, fName);
    
  //get last name
  cout << "Please enter a last name: ";
  getline(cin, lName);
    
  //print intro based on data given
  fullIntro(fName, lName);
    
  return 0;
}

void fullIntro (const string &firstName, const string &lastName) {
  cout << "My name is " << firstName << ' ' << lastName
       << ", at your service!";
}


