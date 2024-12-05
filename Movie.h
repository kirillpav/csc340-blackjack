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
    Movie(const std::string &title, const std::string &director, const std::string &genre, double length, int yearReleased);

    // Getters
    std::string getTitle() const;
    std::string getDirector() const;
    std::string getGenre() const;
    double getFilmLength() const;
    // Setters
    void setTitle(std::string &title);
    void setDirector(std::string &director);
    void setGenre(std::string &genre);
    void setLength(double length);
};

#endif