#ifndef MEDIA_H
#define MEDIA_H

#include <string>

class Media
{

    // H-Was private and not protected for some godless reason
protected:
    std::string name;
    std::string status;
    int yearReleased;
    std::string mediaType;

public:
    Media();
    Media(const std::string &name, const std::string &status, int yearReleased);

    std::string getName() const;
    std::string getStatus() const;
    int getYearReleased() const;
    std::string getMediaType() const;

    void setName(std::string &name);
    void setStatus(std::string &status);
    void setReleaseYear(int &releaseYear);
    void setMediaType(std::string &mediaType);

    // H-Making media an abstarct class. Review pure virtual functions in Reading 20.7 if needed
    virtual void print() const = 0;
};

#endif