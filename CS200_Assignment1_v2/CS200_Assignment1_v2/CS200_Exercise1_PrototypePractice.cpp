//
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

string fullIntro (string&, string&);

int main(int argc, const char * argv[]) {
    string fName, lName, intro;
    
    //get first name
    cout << "Please enter a first name: ";
    getline(cin, fName);
    
    //get last name
    cout << "Please enter a last name: ";
    getline(cin, lName);
    
    //print intro based on data given
    intro = fullIntro(fName, lName);
    cout << intro;
    
    return 0;
}

string fullIntro (const string &firstName, const string &lastName) {
    string intro = "My name is " + firstName + ' ' + lastName
    + ", at your service!";
    return intro;
}


