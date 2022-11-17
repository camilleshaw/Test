#include <iostream>
#include <sstream>
#include <string>

#include "Book.h"

using namespace std;

Book::Book()
{
    title = "default";
    author = "Me";
}

Book::Book(string t, string a)
{
    setTitle(t);
    setAuthor(a);
}

Book::~Book()
{
}

string Book::getTitle() const
{
    return this->title;
}

string Book::getAuthor() const
{
    return this->author;
}

void Book::setTitle(string _title)
{
    this->title = _title;
}

void Book::setAuthor(string author)
{
    this->author = author;
}

string Book::toString() const
{
    stringstream out;
    out << "Book: title: " << getTitle() << " author: " << getAuthor();
    return out.str();
}
