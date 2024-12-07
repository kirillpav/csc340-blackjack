#ifndef MOVIE_H
#define MOVIE_H

#include "Media.h"
#include <string>

class Movie : public Media
{
private:
    std::string director;
    std::string genre;
    double filmLength;

public:
    Movie();
    Movie(const std::string &name, const std::string &status, int yearReleased, const std::string &director, const std::string &genre, double length);
    //H- Only strings need to be passed by reference with const

    //H-For some reason we have getters/setters for a "title" variable 
    //H-Remember that Movie inherits the "name" attribute i.e. the Movie's title

    // Getters
    std::string getDirector() const;
    std::string getGenre() const;
    double getFilmLength() const;
    // Setters
    void setDirector(std::string &director);
    void setGenre(std::string &genre);
    void setLength(double &length);

    void print() const;
};

#endif