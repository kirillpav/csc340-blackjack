#ifndef MEDIA_H
#define MEDIA_H

#include <string>

class Media
{
private:
    std::string name;
    int yearReleased;
    int yearAdded;
    int rating;
    // Methods, therefore public
public:
    Media();
    // Constructor
    Media(std::string name, int yearReleased, int yearAdded);

    std::string getName() const;
    int getYearReleased() const;
    int getYearAdded() const;
    int getRating() const;
};

#endif