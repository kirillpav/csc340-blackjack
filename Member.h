#ifndef MEMBER_H
#define MEMBER_H

#include "Media.h"
#include <string>
#include <vector>

class Member
{
private:
    int memberId;
    std::string username;
    std::vector<Media *> borrowedMedia; // push_back to add, remove or pop to return an item.

public:
    Member();

    Member(const int memberId, const std::string userName);

    int getMemberId() const;
    std::string getUsername() const;

    void setMemberId(int &newMemberId);
    void setUsername(std::string &newUsername);

    void addMedia(const Media& mediaItem);
    void returnMedia(const std::string &mediaItemName);
    void printMedia() const;
};

#endif
