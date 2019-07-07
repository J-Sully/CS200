//
//  main.cpp
//  CS200_6_3_InteractiveCar
//
//  Created by Jessie Sully on 7/7/19.
//  Copyright © 2019 Jessie Sully. All rights reserved.
//

#include <iostream>
#include <sstream>
#include "Car.h"

void accelerate(Car &car);
void brake(Car &car);

string menu {
    
}

int main(int argc, const char * argv[]) {
    stringstream output;
    stringstream ss;
    string make, sYear, input;
    unsigned int year;
    
    cout << "Please enter the make of your car: ";
    getline(cin, make);
    cout << endl << "Please enter the year of your car: ";
    getline(cin, sYear);
    ss.str(sYear);
    ss >> year;
    ss.clear();
    ss.str("");
    Car car = {make, year};
    
    do {
        
    } while (input != "
    
    return 0;
}

// printing with the correct format
void accelerate(Car &car) {
    stringstream output;
    cout << "Accelerating..." << endl;
    car.accelerate();
    car.writeStatus(output);
    cout << output.str() << endl << endl;
    output.clear();
    output.str("");
}

//printing with the correct format
void brake(Car &car) {
    stringstream output;
    cout << "Braking...";
    if (car.getSpeed() != 0) {
        car.brake();
        car.writeStatus(output);
        cout << endl << output.str() << endl << endl;
        output.clear();
        output.str("");
    }
    else {
        cout << "Error: can't brake a car that's standing still." << endl;
        car.writeStatus(output);
        cout << output.str() << endl << endl;
        output.clear();
        output.str("");
    }
}
