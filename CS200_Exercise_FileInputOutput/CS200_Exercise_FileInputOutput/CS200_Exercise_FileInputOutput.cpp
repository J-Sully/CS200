/*
 Write a simple compilable program that outputs to a file these two
 rows: (1) a header row with headings for each column and (2) a data
 row with one set of data. You may have addition data rows if you wish
 
 Include at least 3 columns of information of any kind you like, with
 real or made-up data. For example, a student record, a stock quote,
 a weather forecast, etc.
 */
//  main.cpp
//  CS200_Exercise_FileInputOutput
//
//  Created by Jessie Sully on 6/21/19.
//  Copyright © 2019 Jessie Sully. All rights reserved.
//

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

const string FILENAME = "grades.xls";

//relevent student information
struct record {
  string name;
  double percentage;
  char letterGrade;
};

int main(int argc, const char * argv[]) {
  
  record jessicaRecord {"Jessica", 93.65, 'A'};
  ofstream fout;
  
  // output to file
  fout.open(FILENAME);
  fout << "Student Name\tPercentage\tLetter Grade" << endl;
  fout << jessicaRecord.name << '\t' << jessicaRecord.percentage
       << '\t' << jessicaRecord.letterGrade << endl;
  
  return 0;
}
