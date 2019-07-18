//
//  PublishedWork.h
//  CS200_Lab9_5_MultipleInheritance
//
//  Created by Jessie Sully on 7/17/19.
//  Copyright © 2019 Jessie Sully. All rights reserved.
//

#ifndef PUBLISHEDWORK_H
#define PUBLISHEDWORK_H

#include <string>
using namespace std;

/*
 -----------------------
 PublishedWork
 -----------------------
 - mAuthor : string
 - mYearPublished : unsigned int
 -----------------------
 + PublishedWork()
 + PublishedWork(author : string, yearPublished : unsigned int)
 + setAuthor (author : string) : void
 + setYearPublished (year : unsigned int) : void
 + getAuthor() : string
 + getYearPublished() : unsigned int

 ----------------------
 */

class PublishedWork {
private:
  string mAuthor;
  unsigned int mYearPublished = 0;
  
public:
  PublishedWork() {}
  PublishedWork(const string &author, unsigned int yearPublished) :
                mAuthor(author), mYearPublished(yearPublished) {}
  
  void setAuthor (const string &author)     { mAuthor = author; }
  void setYearPublished (unsigned int year) { mYearPublished = year; }
  
  const string& getAuthor() const { return mAuthor; }
  unsigned int getYearPublished() const    { return mYearPublished; }
};

#endif /* PUBLISHEDWORK_H */
