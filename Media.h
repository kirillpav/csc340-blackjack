#ifndef MEDIA_H
#define MEDIA_H

#include <string>

class Media
{
private:
    std::string name;
    std::string status;
    int yearReleased;

    // Methods, therefore public
public:
    // Constructors
    Media();
    Media(std::string name);
    Media(std::string name, std::string status);

    std::string getName() const;
    std::string getStatus() const;
    int getYearReleased() const;
};

#endif