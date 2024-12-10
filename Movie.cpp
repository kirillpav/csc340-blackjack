#include "Movie.h"
#include "Media.h"
#include <iostream>
#include <string>

using namespace std;

Movie::Movie() : Media("", "", -1),
                 director(""), genre(""), filmLength(-1)
{
}

// H- Only strings need to be passed by reference with const
Movie::Movie(const std::string &name, const std::string &status, int yearReleased, const std::string &director, const std::string &genre, double length) : Media(name, status, yearReleased),
                                                                                                                                                           director(director), genre(genre), filmLength(length)
{
}

string Movie::getDirector() const
{
    return this->director;
}

string Movie::getGenre() const
{
    return this->genre;
}

double Movie::getFilmLength() const
{
    return this->filmLength;
}

void Movie::setDirector(string &director)
{
    this->director = director;
}

void Movie::setGenre(string &genre)
{
    this->genre = genre;
}

void Movie::setLength(double &length)
{
    this->filmLength = length;
}

void Movie::print() const
{
    cout << name << " was directed by " << director << " in " << yearReleased << ", a " << genre << " movie that is " << filmLength << " minutes long.\n";
    cout << "This movie is currently " << status << ".";
}
