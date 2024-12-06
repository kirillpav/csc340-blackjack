#include "Node.h"

Node::Node()
{
    data = nullptr;
    next = nullptr;
    prev = nullptr;
}

Node::Node(Media *media)
{
    data = media;
    next = nullptr;
    prev = nullptr;
}

Media *Node::getData() const
{
    return data;
}

Node *Node::getNext() const
{
    return next;
}

Node *Node::getPrev() const
{
    return prev;
}

void Node::setData(Media *newData)
{
    this->data = newData;
}

void Node::setNext(Node *newNext)
{
    next = newNext;
}

void Node::setPrev(Node *newPrev)
{
    prev = newPrev;
}

// Operator overloads for Node vs Node
bool operator==(const Node &left, const Node &right)
{
    return left.getData() == right.getData();
}

bool operator!=(const Node &left, const Node &right)
{
    return !(left == right);
}

bool operator<(const Node &left, const Node &right)
{
    return left.getData() < right.getData();
}

bool operator>(const Node &left, const Node &right)
{
    return right < left;
}

bool operator<=(const Node &left, const Node &right)
{
    return !(right < left);
}

bool operator>=(const Node &left, const Node &right)
{
    return !(left < right);
}

// Operator overloads for Node vs string
bool operator==(const Node &left, const std::string &right)
{
    return left.getData() == right;
}

bool operator==(const std::string &left, const Node &right)
{
    return right.getData() == left;
}

bool operator!=(const Node &left, const std::string &right)
{
    return !(left == right);
}

bool operator!=(const std::string &left, const Node &right)
{
    return !(right == left);
}

bool operator<(const Node &left, const std::string &right)
{
    return left.getData() < right;
}

bool operator<(const std::string &left, const Node &right)
{
    return left < right.getData();
}

bool operator>(const Node &left, const std::string &right)
{
    return right < left.getData();
}

bool operator>(const std::string &left, const Node &right)
{
    return right.getData() < left;
}

bool operator<=(const Node &left, const std::string &right)
{
    return !(right < left.getData());
}

bool operator<=(const std::string &left, const Node &right)
{
    return !(right.getData() < left);
}

bool operator>=(const Node &left, const std::string &right)
{
    return !(left.getData() < right);
}

bool operator>=(const std::string &left, const Node &right)
{
    return !(left < right.getData());
}