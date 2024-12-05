#ifndef MOVIE_H
#define MOVIE_H

#include "Media.h"
#include <string>

class Movie : Media
{
private:
    std::string director;
    std::string genre;
    double filmLength;

public:
    Movie();
    Movie(std::string director, std::string genre, double filmLength);

    // Getters
    std::string getDirector() const;
    std::string getGenre() const;
    double getFilmLength() const;
    // Setters
    void setDirector(std::string director);
    void setGenre(std::string genre);
    void setLength(double length);
};

#endif