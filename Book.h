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
    Book(const std::string &name, const std::string &status, int yearReleased, const std::string &author, const std::string &genre, double pageNum);
    //H- Only strings need to be passed by reference with const

    //For some reason we have getters/setters for a "title" variable 
    //Remember that Book inherits the "name" attribute i.e. the Book's title

    std::string getAuthor() const;
    std::string getGenre() const;
    int getPageNum() const;

    void setAuthor(std::string &author);
    void setGenre(std::string &genre);
    void setNumOfPages(int &numOfPages);

    void print() const;
};

#endif