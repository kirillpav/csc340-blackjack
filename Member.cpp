#include "Member.h"
#include <iostream>
#include <algorithm>

Member::Member() : memberId(0) {}

Member::Member(const std::string& userName, int memberId) : userName(userName), memberId(memberId) {}

std::string Member::getUserName() const {
    return userName;
}

void Member::setUserName(const std::string& newName) {
    userName = newName;
}

int Member::getMemberId() const {
    return memberId;
}

void Member::setMemberId(int newMemberId) {
    memberId = newMemberId;
}

void Member::addMedia(const Media& mediaItem) {
    borrowedMedia.push_back(mediaItem);
}

void Member::returnMedia(const std::string& mediaItemName) {
    auto it = std::remove_if(borrowedMedia.begin(), borrowedMedia.end(),
                             [&mediaItemName](const Media& item) {
                                 return item.mediaName == mediaItemName;
                             });
    if (it != borrowedMedia.end()) {
        borrowedMedia.erase(it, borrowedMedia.end());
        std::cout << "Item '" << mediaItemName << "' returned by " << userName << ".\n";
    } else {
        std::cout << "Item '" << mediaItemName << "' not found for " << userName << ".\n";
    }
}

void Member::printMedia() const {
    std::cout << "Items borrowed by " << userName << ":\n";
    for (const auto& item : borrowedMedia) {
        std::cout << "Media Name: " << item.mediaName << "\n";
        std::cout << "Date Borrowed: " << item.dateBorrowed << "\n";
        std::cout << "Due Date: " << item.dueDate << "\n\n";
    }
}
