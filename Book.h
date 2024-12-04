#ifndef BOOK_H
#define BOOK_H

#include "Media.h"
#include <string>

class Book : Media
{
private:
    std::string author;
    std::string genre;
    int pageNum;

public:
    Book();
    Book(std::string author, std::string genre, int pageNum);

    std::string getTitle() const;
    std::string getAuthor() const;
    std::string getGenre() const;
    int getPageNum() const;

    void add(Book book);
    Book search(Book bookName);
    void remove(Book bookName);
};

#endif