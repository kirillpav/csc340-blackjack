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

    std::string getDirector() const;
    std::string getGenre() const;
    double getFilmLength() const;

    void add(Movie movie);
    Movie search(Movie movieName);
    void remove(Movie movieName);
};

#endif