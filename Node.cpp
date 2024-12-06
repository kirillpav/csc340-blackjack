#include "Node.h"

Node::Node()
{
    word = "";
    next = nullptr;
    prev = nullptr;
}

Node::Node(const std::string &newWord)
{
    word = newWord;
    next = nullptr;
    prev = nullptr;
}

std::string Node::getWord() const
{
    return word;
}

Node *Node::getNext() const
{
    return next;
}

Node *Node::getPrev() const
{
    return prev;
}

void Node::setWord(const std::string &newWord)
{
    word = newWord;
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
    return left.getWord() == right.getWord();
}

bool operator!=(const Node &left, const Node &right)
{
    return !(left == right);
}

bool operator<(const Node &left, const Node &right)
{
    return left.getWord() < right.getWord();
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
    return left.getWord() == right;
}

bool operator==(const std::string &left, const Node &right)
{
    return right.getWord() == left;
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
    return left.getWord() < right;
}

bool operator<(const std::string &left, const Node &right)
{
    return left < right.getWord();
}

bool operator>(const Node &left, const std::string &right)
{
    return right < left.getWord();
}

bool operator>(const std::string &left, const Node &right)
{
    return right.getWord() < left;
}

bool operator<=(const Node &left, const std::string &right)
{
    return !(right < left.getWord());
}

bool operator<=(const std::string &left, const Node &right)
{
    return !(right.getWord() < left);
}

bool operator>=(const Node &left, const std::string &right)
{
    return !(left.getWord() < right);
}

bool operator>=(const std::string &left, const Node &right)
{
    return !(left < right.getWord());
}