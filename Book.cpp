#include "Book.h"
#include "Media.h"
#include "Media.cpp"
#include <string>

using namespace std;

Book::Book() : Media()
{
    string title = "";
    string author = "";
    string genre = "";
    int pageNum = 0;
}

Book::Book(const std::string &title, const std::string &author, const std::string &genre, int pageNum, int yearReleased)
    : Media(title, "available", yearReleased), author(author), genre(genre), pageNum(pageNum) {}

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

void Book::setTitle(string &title)
{
    setName(title);
}

void Book::setAuthor(string &author)
{
    this->author = author;
}

void Book::setGenre(string &genre)
{
    this->genre = genre;
}

// void setNumOfPages(int numOfPages)
// {
//     this->pageNum = numOfPages;
// }