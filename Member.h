#include "Media.h"
#include <vector>
#ifndef MEMBER_H
#define MEMBER_H
class Member
{
private:
    std::string userName;
    int memberId;
    std::vector<Media> borrowedMedia; // push_back to add, remove or pop to return an item.

public:
    Member(const std::string& userName, int memberId) : userName(userName), memberId(memberId) {}
    Member();

    Member(std::string userName, int memberId);

    std::string getUserName() const;
    void setUserName(const std::string& newName);

    int getMemberId() const;
    void setMemberId(int newMemberId);

    void addMedia(const Media &mediaItem);
    void returnMedia(const std::string &mediaItemName);
    void printMedia() const;
};
#endif