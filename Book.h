#ifndef BOOK_H
#define BOOK_H

#include "Media.h"
#include <string>

class Book : public Media
{
private:
    std::string author;
    std::string genre;
    int pageNum;

public:
    Book();
    Book(const std::string &title, const std::string &author, const std::string &genre, int pageNum, int yearReleased);

    std::string getTitle() const;
    std::string getAuthor() const;
    std::string getGenre() const;
    int getPageNum() const;

    void setTitle(std::string &title);
    void setAuthor(std::string &author);
    void setGenre(std::string &genre);
    void setNumOfPages(int numOfPages);
};

#endif