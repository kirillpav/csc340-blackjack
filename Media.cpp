#include "Media.h"
#include <string>

using namespace std;

Media::Media()
    : name(""), status(""), yearReleased(0), mediaType("") {}

Media::Media(const std::string &name, const std::string &status, int yearReleased)
    : name(name), status(status), yearReleased(yearReleased), mediaType("") {}

string Media::getName() const
{
    return this->name;
}

string Media::getStatus() const
{
    return this->status;
}

string Media::getMediaType() const
{
    return this->mediaType;
}

int Media::getYearReleased() const
{
    return this->yearReleased;
}

void Media::setName(string &name)
{
    this->name = name;
}

void Media::setStatus(string &status)
{
    this->status = status;
}

void Media::setReleaseYear(int &releaseYear)
{
    this->yearReleased = releaseYear;
}
