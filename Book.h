#ifndef BOOK_H
#define BOOK_H

#include <iostream>
#include <string>

using namespace std;

class Book
{
private:
    string title;
    string author;

public:
    Book();
    Book(string t, string a);
    ~Book();

    // getter
    string getTitle() const;
    string getAuthor() const;

    // setter
    void setTitle(string title);
    void setAuthor(string author);

    string toString() const;
};

#endif