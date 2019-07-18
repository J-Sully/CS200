//
//  main.cpp
//  CS200_Lab9_5_MultipleInheritance
//
//  Created by Jessie Sully on 7/17/19.
//  Copyright © 2019 Jessie Sully. All rights reserved.
//

#include <iostream>
#include <vector>

#include "ReaderApp.h"

int main(int argc, const char * argv[]) {
  vector<ReaderApp> apps;
  
  apps.emplace_back("Kindle", 0, "William Golding", 1954, "iPhone", "iPhone OS 1.1.5", 128);
  apps.emplace_back("iBooks", 0, "Charles Dickens", 1859, "iPad", "iOS 8", 16);
  apps.emplace_back("PDF Reader", 0, "John Steinback", 1937, "Android", "Android.os", 32);
  
  for (ReaderApp app : apps) {
    cout << "Name of App: " << app.getName() << endl
         << "Cost of App: " << app.getCost() << endl
         << "Name of Author: " << app.getAuthor() << endl
         << "Date Published: " << app.getYearPublished() << endl
         << "Type of Device: " << app.getType() << endl
         << "OS of Device: " << app.getOS() << endl
         << "Size of Harddrive: " << app.getMemoryGB() << endl << endl;
  }
}
