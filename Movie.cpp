#include "Movie.h"
#include "Media.h"
#include <string>

using namespace std;

Movie::Movie() : Media()
{
    string director = "";
    string genre = "";
    double filmLength = 0;
}

Movie::Movie(string director, string genre, double filmLength) : Media()
{
    string director = director;
    string genre = genre;
    double filmLength = filmLength;
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

void Movie::setDirector(string director)
{
    this->director = director;
}

void Movie::setGenre(string genre)
{
    this->genre = genre;
}

void Movie::setLength(double length)
{
    this->filmLength = length;
}
