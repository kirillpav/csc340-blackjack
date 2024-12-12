#include "Book.h"
#include "Media.h"
#include <iostream>
#include <string>

using namespace std;

Book::Book() : Media("", "", -1),
               author(""), genre(""), pageNum(-1)
{
    mediaType = "Book";
}

// H- Only strings need to be passed by reference with const
Book::Book(const string &name, const string &status, int yearReleased, const string &author, const string &genre, double pageNum) : Media(name, status, yearReleased),
                                                                                                                                    author(author), genre(genre), pageNum(pageNum)
{
    mediaType = "Book";
}

string Book::getAuthor() const
{
    return this->author;
}

string Book::getGenre() const
{
    return this->genre;
}

int Book::getPageNum() const
{
    return this->pageNum;
}

void Book::setAuthor(string &author)
{
    this->author = author;
}

void Book::setGenre(string &genre)
{
    this->genre = genre;
}

void Book::setNumOfPages(int &numOfPages)
{
    this->pageNum = numOfPages;
}

void Book::print() const
{
    cout << name << " was published by " << author << " in " << yearReleased << " is a " << genre << " book with " << pageNum << " pages.\n";
    cout << "This book is currently " << status << ".";
}