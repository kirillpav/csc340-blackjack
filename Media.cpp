#include "Media.h"
#include <string>

using namespace std;

Media::Media()
{
    string name = "";
    string status = "";
    int yearReleased = 0;
}

Media::Media(string name, string status, int yearReleased)
{
    string name = name;
    string status = status;
    int yearReleased = yearReleased;
}

string Media::getName() const
{
    return this->name;
}

string Media::getStatus() const
{
    return this->status;
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
