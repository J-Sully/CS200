
/*
 
 */
//  main.cpp
//  CS200_Shapes.1
//
//  Created by Jessie Sully on 6/22/19.
//  Copyright © 2019 Jessie Sully. All rights reserved.
//

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <iomanip>
using namespace std;

#include <cmath>
#include <vector>

class Shape {
public:
  string mName, mNameDimMin1, mNameDim;
  vector<double> mDimensions;
  double mCalcDimMin1, mCalcDim;
  char mDimension;
  
  Shape(string &input);
  void clear();
  bool calculate (const string &, double &, double &, const double,
                  const double, const double);
  
};

Shape::Shape(string &input){
  stringstream ss;
  double dim1 = -1, dim2 = -1, dim3 = -1;
  ss.str(input);
  ss >> mName >> dim1 >> dim2 >> dim3;
  
}

void Shape::clear() {
  mName.clear();
  mNameDimMin1.clear();
  mNameDim.clear();
  mDimensions.clear();
  mCalcDimMin1 = 0;
  mCalcDim = 0;
}

/*calculatedDimMin1 is to indicat perimeter in 2D objects and surface
 area of 3D objects, calculatedDim for area in 2D objects and volume
 for 3D objects. The boolean is used to flag any errors found to be
 handled.
 */
bool Shape::calculate (const string &name, double &calculatedDimMin1,
                double &calculatedDim, const double dim1,
                const double dim2, const double dim3) {
  bool errorFound = false;
  
  switch (name.at(0)) {
      
      //for Square - 2D, 1 variable
    case 'S' :
      if (name == "SQUARE" && (dim1 + 1) > 0 && (dim2 + 1) == 0
          && (dim3 + 1) == 0) {
        calculatedDimMin1 = 4 * dim1;
        calculatedDim = dim1 * dim1;
      }
      else {
        errorFound = true;
      }
      break;
      
      //for Rectangle - 2D, 2 variables
    case 'R' :
      if (name == "RECTANGLE" && (dim1 + 1) > 0 && (dim2 + 1) > 0
          && (dim3 + 1) == 0) {
        calculatedDimMin1 = 2 * dim1 + 2 * dim2;
        calculatedDim = dim1 * dim2;
      }
      else {
        errorFound = true;
      }
      break;
      
      //for Circle - 2D, 1 variable, Cube - 3D, 1 variable,
      //and Cylinder - 3D, 2 variables
    case 'C' :
      if (name == "CIRCLE" && (dim1 + 1) > 0 && (dim2 + 1) == 0
          && (dim3 + 1) == 0) {
        
        calculatedDimMin1 = 2 * dim1 * M_PI;
        calculatedDim = dim1 * dim1 * M_PI;
      }
      else if (name == "CUBE" && (dim1 + 1) > 0 && (dim2 + 1) == 0
               && (dim3 + 1) == 0) {
        
        calculatedDimMin1 = 6 * dim1 * dim1;
        calculatedDim = pow(dim1, 3);
      }
      else if (name == "CYLINDER" && (dim1 + 1) > 0 && (dim2 + 1) > 0
               && (dim3 + 1) == 0) {
        
        calculatedDimMin1 = 2 * M_PI * dim1 * dim1 + 2 * M_PI * dim1 * dim2;
        calculatedDim = M_PI * dim1 * dim1 * dim2;
      }
      else {
        errorFound = true;
      }
      break;
      
      // for Equilateral Triangle - 2D, 1 variable
    case 'T' :
      if (name == "TRIANGLE" && (dim1 + 1) > 0 && (dim2 + 1) == 0
          && (dim3 + 1) == 0) {
        
        calculatedDimMin1 = 3 * dim1;
        calculatedDim = sqrt(3.0) / 4 * dim1 * dim1;
      }
      else {
        errorFound = true;
      }
      break;
      
      //for Box - 3D, 3 variables
    case 'B' :
      if (name == "BOX" && (dim1 + 1) > 0 && (dim2 + 1) > 0
          && (dim3 + 1) > 0) {
        
        calculatedDimMin1 = 2 * dim1 * dim2 + 2 * dim2 * dim3 + 2 * dim1 * dim3;
        calculatedDim = dim1 * dim2 * dim3;
      }
      else {
        errorFound = true;
      }
      break;
      
      //for Equilateral Triangle Prism - 3D, 2 variables
    case 'P' :
      if (name == "PRISM" && (dim1 + 1) > 0 && (dim2 + 1) > 0
          && (dim3 + 1) == 0) {
        
        calculatedDimMin1 = sqrt(3.0) / 2 * dim1 * dim1 + 3 * dim1
        * dim2;
        calculatedDim = sqrt(3.0) / 4 * dim1 * dim1 * dim2;
      }
      else {
        errorFound = true;
      }
      break;
      
      //flags an error in the name or in parameters
    default:
      errorFound = true;
      break;
  }
  
  return errorFound;
}



const string INFILENAME = "Shapes.input.txt";
const string OUTFILENAME = "Shapes.output.txt";

//void makeInputFile();
void saveData(vector<string> &);
void loadData(vector<string> &);
bool calculate (const string &, double &, double &, const double,
                const double, const double);
void doubleToString (double, string&);
string& writeStatement (bool, const string &, double &, double &,
                        const double, const double, const double);
void parseNumber (const string &, long &, double &);
void parseData (const string &, string &, double &, double &,
                double &);



int main(int argc, const char * argv[]) {
  vector<string> data;
  bool errorFound = false;
  string name, output;
  double calculatedDimMin1 = 0, calculatedDim = 0, dim1 = -1, dim2 = -1, dim3 = -1;
  
 // makeInputFile();
  loadData(data);
  
  for(int i = 0; i < data.size(); i++) {
    parseData(data.at(i), name, dim1, dim2, dim3);
    errorFound = calculate (name, calculatedDimMin1, calculatedDim, dim1, dim2, dim3);
    
    output = writeStatement(errorFound, name, calculatedDimMin1, calculatedDim, dim1, dim2, dim3);
    data.at(i) = output;
    cout << output << endl;
    dim1 = -1;
    dim2 = -1;
    dim3 = -1;
    errorFound = false;
  }
  
  saveData(data);
  
  return 0;
}

/*
void makeInputFile() {
  ofstream fout;
  
  fout.open(INFILENAME);
  if (fout.good()) {
    fout << "SQUARE 14.5" << endl;
    fout << "SQUARE 0" << endl;
    fout << "RECTANGLE 14.5 4.65" << endl;
    fout << "CIRCLE 14.5" << endl;
    fout << "CUBE 13" << endl;
    fout << "BOX 1 2 3" << endl;
    fout << "SPHERE" << endl;
    fout << "CYLINDER 1.23 0" << endl;
    fout << "CYLINDER 50 1.23" << endl;
    fout << "TRIANGLE 1.2" << endl;
    fout << "PRISM 14.5 5" << endl;
    fout << "SQUARE 14.5" << endl;
    fout << "SQUARE 14.5" << endl;
    fout << "SQUARE 14.5" << endl;
    fout << "SQUARE 14.5" << endl;
    
    fout.close();
  }
}
 */

//saves our output to a file
void saveData(vector<string> &data) {
  ofstream fout;
  
  fout.open(OUTFILENAME);
  if (fout.good()) {
    for(string s: data) {
      fout << s << endl;
    }
  }
}

//loads our input from a file
void loadData(vector<string> &data) {
  ifstream fin;
  string input;
  
  fin.open(INFILENAME);
  if (fin.good()) {
    while (getline(fin, input)) {
      data.push_back(input);
    }
    fin.close();
  }
}



/*
void doubleToString (double value, string &output) {
  stringstream ss;
  
  ss << fixed << setprecision(2) << value;
  ss >> output;
  ss.clear();
}
 */

/*Makes a readable statement to output from calculated data, switch
 is necessary since there are different names for variables and
 calculated values.
 */
string& writeStatement (bool error, const string &name,
                        double &calculatedDimMin1,
                        double &calculatedDim, const double dim1,
                        const double dim2, const double dim3) {
  string output, sdim;
  stringstream ss;
  
  if (!error) {
    switch (name.at(0)) {
        
        //for Square
      case 'S' :
        
        //for Triangle
      case 'T':
        ss << name << " side=" << fixed << setprecision(2) << dim1 << " perimeter=" << setprecision(2) << calculatedDimMin1 << " area=" << setprecision(2) << calculatedDim << endl;
        ss >> output;
        ss.clear();
        break;
        
     /*
        //for Rectangle
      case 'R' :
        output = name + " length=" + doubleToString(dim1) + " width="
        + doubleToString(dim2) + " perimeter="
        + doubleToString(calculatedDimMin1) + " area="
        + doubleToString(calculatedDim);
        break;
        
        //for Circle, Cube, and Cylinder
      case 'C' :
        switch (name.at(1)) {
            
            //for circle
          case 'I':
            output = name + " radius=" + doubleToString(dim1)
            + " circumference="
            + doubleToString(calculatedDimMin1) + " area="
            + doubleToString(calculatedDim);
            break;
            
            //for cylinder
          case 'Y' :
            output = name + " radius=" + doubleToString(dim1)
            + " height=" + doubleToString(dim2)
            + " surface area="
            + doubleToString(calculatedDimMin1) + " volume="
            + doubleToString(calculatedDim);
            break;
            
            //for cube
          case 'U':
            output = name + " side=" + doubleToString(dim1)
            + " surface area="
            + doubleToString(calculatedDimMin1) + " volume="
            + doubleToString(calculatedDim);
            break;
            
            //shouldn't get here unless name is wrong
          default:
            output = "Invalid Object for: " + name;
            break;
        }
        break;
        
        //for Box
      case 'B':
        output = name + " length=" + doubleToString(dim1) + " width="
        + doubleToString(dim2) + " height="
        + doubleToString(dim3) + " surface area="
        + doubleToString(calculatedDimMin1) + " volume="
        + doubleToString(calculatedDim);
        break;
        
        //for Prism
      case 'P' :
        output = name + " side=" + doubleToString(dim1) + " height="
        + doubleToString(dim2) + " surface area="
        + doubleToString(calculatedDimMin1) + " volume="
        + doubleToString(calculatedDim);
        break;
      */
        
        // shouldn't get here unless name is wrong
      default:
        output = "Invalid Object for: " + name;
        break;
    }
  }
  // carry over error from Calculating, could be either error
  else {
    output = "Invalid Object or Parameters for: " + name;
  }
  
  return output;
}

/*Helper function to determine how many variables needed for object
 and handles extracting them using helper function parseNumber
 */
void parseData (const string &input, string &name, double &dim1,
                double &dim2, double &dim3) {
  stringstream ss;
  ss.str(input);
  ss >> name >> dim1 >> dim2 >> dim3;
  ss.clear();
}
