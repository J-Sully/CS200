/*
 Assignment: Lab 1, Shapes Part 1
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

/*Input file must be in format <object> <dimension1> <dimension2>
 <dimension3> - no filler values for unused dimensions */
const string INFILENAME = "Shapes.input.txt";
const string OUTFILENAME = "Shapes.output.txt";

bool calculate (const string &, double &, double &, const double,
                const double, const double);
void writeStatement (bool &, stringstream &ss, const string &,
                     double &, double &, const double, const double,
                     const double);
void parseData (const string &, string &, double &, double &,
                double &);

int main(int argc, const char * argv[]) {
  ifstream fin;
  ofstream fout;
  bool errorFound;
  string name, input;
  stringstream output;
  double calculatedDimMin1, calculatedDim, dim1, dim2, dim3;
  
  fin.open(INFILENAME); //input file
  fout.open(OUTFILENAME); //ouput file
  
  if (fin.good() && fout.good()) {
    
    while (getline(fin,input)) {
      // reset values
      calculatedDimMin1 = calculatedDim = 0;
      dim1 = dim2 = dim3 = -1;
      errorFound = false;
      output.str("");
      output.clear();
      
      //extract useful values from string
      parseData(input, name, dim1, dim2, dim3);
      
      //calculate needed values, catch error if found
      errorFound = calculate (name, calculatedDimMin1, calculatedDim,
                              dim1, dim2, dim3);
      
      //write statements, even if error in calculation
      writeStatement(errorFound, output, name, calculatedDimMin1,
                     calculatedDim, dim1, dim2, dim3);
      
      //write to console, even if error in calculation
      cout << output.str() << endl;
      
      //only write valid objects to file
      if (!errorFound) {
        
        fout << output.str() << endl;
      }
    }
  }
  return 0;
}

/*calculatedDimMin1 is to indicat perimeter in 2D objects and surface
 area of 3D objects, calculatedDim for area in 2D objects and volume
 for 3D objects. The boolean is used to flag any errors found to be
 handled.
 */
bool calculate (const string &name, double &calculatedDimMin1,
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
      
      /* for Circle - 2D, 1 variable, Cube - 3D, 1 variable, and
       Cylinder - 3D, 2 variables */
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
        
        calculatedDimMin1 = 2 * M_PI * dim1 * dim1 + 2 * M_PI * dim1
        * dim2;
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
        
        calculatedDimMin1 = 2 * dim1 * dim2 + 2 * dim2 * dim3 + 2
        * dim1 * dim3;
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

/* Makes a readable statement to output from calculated data, switch
 is necessary since there are different names for variables and
 calculated values. */

void writeStatement (bool &error, stringstream &output, const string
                     &name, double &calculatedDimMin1,
                     double &calculatedDim, const double dim1,
                     const double dim2, const double dim3) {
  
  /*only make tailored statements for object that didn't fail
   calculate */
  
  if (!error) {
    switch (name.at(0)) {
        
        //for Square - keywords: side, perimeter, area
      case 'S' :
        
        //for Triangle - keywords: side, perimeter, area
      case 'T':
        output << name << " side=" << fixed << setprecision(2) << dim1
        << " perimeter=" << calculatedDimMin1 << " area="
        << calculatedDim;
        break;
        
        
        //for Rectangle - keywords: length, width, perimeter, area
      case 'R' :
        output << name << " length=" << fixed << setprecision(2)
        << dim1 << " width=" << dim2 << " perimeter="
        << calculatedDimMin1 << " area=" << calculatedDim;
        break;
        
        //for Circle, Cube, and Cylinder
      case 'C' :
        switch (name.at(1)) {
            
            //for Circle - keywords: radius, circumference, area
          case 'I':
            output << name << " radius=" << fixed << setprecision(2)
            << dim1 << " circumference=" << calculatedDimMin1
            << " area=" << calculatedDim;
            break;
            
            /*for Cylinder - keywords: radius, height, surface area,
             volume */
          case 'Y' :
            output << name << " radius=" << fixed << setprecision(2)
            << dim1 << " height=" << dim2 << " surface area="
            << calculatedDimMin1 << " volume="
            << calculatedDim;
            break;
            
            //for Cube - keywords: side, surface area, volume
          case 'U':
            output << name << " side=" << fixed << setprecision(2)
            << dim1 << " surface area=" << calculatedDimMin1
            << " volume=" << calculatedDim;
            break;
            
            //shouldn't get here unless name is wrong
          default:
            output << "Invalid Object for: " << name;
            error = true;
            break;
        }
        break;
        
        //for Box - keywords: length, width, height surface area, volume
      case 'B':
        output << name << " length=" << fixed << setprecision(2)
        << dim1 << " width=" << dim2 << " height=" << dim3
        << " surface area=" << calculatedDimMin1 << " volume="
        << calculatedDim;
        break;
        
        //for Prism - keywords: side, height, surface area, volume
      case 'P' :
        output << name << " side=" << fixed << setprecision(2) << dim1
        << " height=" << dim2 << " surface area="
        << calculatedDimMin1 << " volume=" << calculatedDim;
        break;
        
        // shouldn't get here unless name is wrong
      default:
        output << "Invalid Object for: " << name;
        error = true;
        break;
    }
  }
  // for objects that failed in calculate
  else {
    output << "Invalid Object or Parameters for: " << name;
  }
}

/*Helper function to determine how many variables needed for object
 and extracts values */

void parseData (const string &input, string &name, double &dim1,
                double &dim2, double &dim3) {
  
  stringstream ss;
  ss.str(input);
  ss >> name >> dim1 >> dim2 >> dim3;
}
