//CS200_Exercise_Constructors

#include <iostream>
#include <vector>

#include "Car.h"


int main() {
  vector<Car> myCars;
  Car myCar1;
  Car myCar2("Ford");
  Car myCar3(2005);
  Car myCar4("Ford", 2005);
  
  myCars.push_back(myCar1);
  myCars.push_back(myCar2);
  myCars.push_back(myCar3);
  myCars.push_back(myCar4);
  
  for (Car c: myCars) {
    cout << "Make: " << c.getMake() << endl;
    cout << "Year: " << c.getYear() << endl << endl;
  }
  
  return 0;
}

