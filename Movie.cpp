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

Movie::Movie(const string &title, const std::string &director, const string &genre, double length, int yearReleased) : Media(title, "available", yearReleased)
{
    string title = title;
    string director = director;
    string genre = genre;
    double filmLength = length;
    int yearReleased = yearReleased;
}

string Movie::getTitle() const
{
    return getName();
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

void Movie::setTitle(string &title)
{
    setName(title);
}

void Movie::setDirector(string &director)
{
    this->director = director;
}

void Movie::setGenre(string &genre)
{
    this->genre = genre;
}

void Movie::setLength(double length)
{
    this->filmLength = length;
}
