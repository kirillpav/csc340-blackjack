#ifndef NODE_H
#define NODE_H

#include <string>

struct Node
{
private:
    std::string word;
    Node *next;
    Node *prev;

public:
    Node();
    Node(const std::string &newWord);

    std::string getWord() const;
    Node *getNext() const;
    Node *getPrev() const;
    void setWord(const std::string &newWord);
    void setNext(Node *newNext);
    void setPrev(Node *newPrev);
};

bool operator==(const Node &left, const Node &right);
bool operator!=(const Node &left, const Node &right);
bool operator<(const Node &left, const Node &right);
bool operator>(const Node &left, const Node &right);
bool operator<=(const Node &left, const Node &right);
bool operator>=(const Node &left, const Node &right);

bool operator==(const Node &left, const std::string &right);
bool operator==(const std::string &left, const Node &right);
bool operator!=(const Node &left, const std::string &right);
bool operator!=(const std::string &left, const Node &right);
bool operator<(const Node &left, const std::string &right);
bool operator<(const std::string &left, const Node &right);
bool operator>(const Node &left, const std::string &right);
bool operator>(const std::string &left, const Node &right);
bool operator<=(const Node &left, const std::string &right);
bool operator<=(const std::string &left, const Node &right);
bool operator>=(const Node &left, const std::string &right);
bool operator>=(const std::string &left, const Node &right);

#endif