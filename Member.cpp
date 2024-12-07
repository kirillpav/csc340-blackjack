#include "Member.h"
#include <iostream>
#include <algorithm>  //  <-----  H- who invited this guy??
#include <vector>

using namespace std;

Member::Member()
{
    memberId = 0;
    username = "";
}
Member::Member(int memberId, string userName)
{
    memberId = memberId;
    username = userName;
}


int Member::getMemberId() const 
{
    return this->memberId;
}
string Member::getUsername() const 
{
    return this->username;
}


void Member::setUsername(string &newName) 
{
    this->username = newName;
}
void Member::setMemberId(int &newMemberId) 
{
    this->memberId = newMemberId;
}


void Member::addMedia(const Media& mediaItem) 
{
    this->borrowedMedia.push_back(mediaItem);
}

//H-Maybe we need a function to use an interator through borrowedMedia to avoid redundant code

//H-Review vectors
void Member::returnMedia( const string& mediaItemName) 
{
    vector<Media>:: iterator bookmark = borrowedMedia.begin();
    while (bookmark != borrowedMedia.end()) {
        //H-No need to dereference with * operator as bookmark already points to the media we want to print
        if (bookmark->getName() == mediaItemName)
        {
            break;
        }
        bookmark++;
    }

    if(bookmark == borrowedMedia.end())
    {
        cout << "Member has not borrowed an item named: " << mediaItemName << ".\n";
    }
    else
    {
        borrowedMedia.erase(bookmark);
        cout << "The item " << mediaItemName << " has been returned.\n";
    }
}

//H- Review vectors
void Member::printMedia() const 
{
    cout << "Items borrowed by " << username << ":\n";

    vector<Media>:: const_iterator bookmark = borrowedMedia.begin();
    while (bookmark != borrowedMedia.end()) {
        //H-No need to dereference with * operator as bookmark already points to the media we want to print
        bookmark->print();
        bookmark++;
        cout << endl;
    }
}
