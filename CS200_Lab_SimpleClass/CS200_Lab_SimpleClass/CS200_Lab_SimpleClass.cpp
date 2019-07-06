/*
*/
//  main.cpp
//  CS200_Lab_SimpleClass
//
//  Created by Jessie Sully on 7/1/19.
//  Copyright © 2019 Jessie Sully. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
 ----------------------------
 Book
 ----------------------------
 - author: string
 - yearPublished: int
 - title: string
 ----------------------------
 + getAuthor(): string
 + getYear(): int
 + getTitle(): string
 + setAuthor(a: string): void
 + setYear(y: int): void
 + setTitle(t: string): void
 ----------------------------
 */

class Book {
public:
  string getAuthor() const { return author; }
  int getYear() const      { return yearPublished; }
  string getTitle() const  { return title; }
  void setAuthor(string a) { author = a; }
  void setYear(int y)      { if (y >= 0) yearPublished = y; }
  void setTitle(string t)  { title = t; }
  
private:
  string author;
  int yearPublished = 0;
  string title;
};


int main(int argc, const char * argv[]) {
  vector<Book> favs;
  Book fav;

  fav.setAuthor("Charles Dickens");
  fav.setYear(1859);
  fav.setTitle("A Tale of Two Cities");
  favs.push_back(fav);
  
  fav.setAuthor("John Steinback");
  fav.setYear(1937);
  fav.setTitle("Of Mice and Men");
  favs.push_back(fav);
  
  fav.setAuthor("William Golding");
  fav.setYear(1954);
  fav.setTitle("Lord of the Flies");
  favs.push_back(fav);
  
  for (Book book : favs) {
    cout << "Author: " << book.getAuthor() << endl
         << " Year Published: " << book.getYear() << endl
         << " Title: " << book.getTitle() << endl << endl;
  }
  
  return 0;
}

