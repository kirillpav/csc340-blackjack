#ifndef NODE_H
#define NODE_H

#include "Media.h"
#include <string>

struct Node
{
private:
    Media *data;
    Node *next;
    Node *prev;

public:
    Node();
    Node(Media *media);

    Media *getData() const;
    Node *getNext() const;
    Node *getPrev() const;
    void setData(Media *media);
    void setNext(Node *newNext);
    void setPrev(Node *newPrev);
};

bool operator==(const Node &left, const Node &right);
bool operator==(const Node &left, const std::string &right);
bool operator==(const std::string &left, const Node &right);

bool operator!=(const Node &left, const Node &right);
bool operator!=(const Node &left, const std::string &right);
bool operator!=(const std::string &left, const Node &right);

bool operator<(const Node &left, const Node &right);
bool operator<(const Node &left, const std::string &right);
bool operator<(const std::string &left, const Node &right);

bool operator>(const Node &left, const Node &right);
bool operator>(const Node &left, const std::string &right);
bool operator>(const std::string &left, const Node &right);

bool operator<=(const Node &left, const Node &right);
bool operator<=(const Node &left, const std::string &right);
bool operator<=(const std::string &left, const Node &right);

bool operator>=(const Node &left, const Node &right);
bool operator>=(const Node &left, const std::string &right);
bool operator>=(const std::string &left, const Node &right);

#endif