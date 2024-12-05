#include "Book.h"
#include "Media.h"
#include <string>

using namespace std;

Book::Book() : Media()
{
    string title = "";
    string author = "";
    string genre = "";
    int pageNum = 0;
}

Book::Book(string author, string genre, int pageNum) : Media("title", "available")
{
    string author = author;
    string genre = genre;
    int pageNum = pageNum;
}

string Book::getTitle() const
{
    return getName();
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

void Book::setTitle(string title)
{
    this->title = title;
}