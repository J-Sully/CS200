//CS200_Exercise_InlineFunctions
#include <iostream>

#include "Car.h"

int main() {
  
  Car myCar;
  myCar.setMake("Toyota");
  myCar.setYear(1999);
  
  cout << myCar.getMake() << endl;
  cout << myCar.getYear() << endl;
  
  return 0;
}
