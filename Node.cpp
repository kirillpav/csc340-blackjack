#include "Node.h"

Node::Node()
{
    this->data = nullptr;
    this->next = nullptr;
    this->prev = nullptr;
}

Node::Node(Media *media)
{
    this->data = media;
    this->next = nullptr;
    this->prev = nullptr;
}

Media *Node::getData() const
{
    return this->data;
}

Node *Node::getNext() const
{
    return this->next;
}

Node *Node::getPrev() const
{
    return this->prev;
}

void Node::setData(Media *newData)
{
    this->data = newData;
}

void Node::setNext(Node *newNext)
{
    this->next = newNext;
}

void Node::setPrev(Node *newPrev)
{
    this->prev = newPrev;
}

// Operator overloads for ==: Node v. Node, Node v. String, String v. Node
bool operator==(const Node &left, const Node &right)
{
    return left.getData() == right.getData();
}
bool operator==(const Node &left, const std::string &right)
{
    return left.getData() == right;
}
bool operator==(const std::string &left, const Node &right)
{
    return right.getData() == left;
}

// Operator overloads for !=: Node v. Node, Node v. String, String v. Node
bool operator!=(const Node &left, const Node &right)
{
    return !(left == right);
}
bool operator!=(const Node &left, const std::string &right)
{
    return !(left == right);
}
bool operator!=(const std::string &left, const Node &right)
{
    return !(right == left);
}

// Operator overloads for <: Node v. Node, Node v. String, String v. Node
bool operator<(const Node &left, const Node &right)
{
    return left.getData() < right.getData();
}
bool operator<(const Node &left, const std::string &right)
{
    return left.getData() < right;
}
bool operator<(const std::string &left, const Node &right)
{
    return left < right.getData();
}

// Operator overloads for >: Node v. Node, Node v. String, String v. Node
bool operator>(const Node &left, const Node &right)
{
    return right < left;
}
bool operator>(const Node &left, const std::string &right)
{
    return right < left.getData();
}
bool operator>(const std::string &left, const Node &right)
{
    return right.getData() < left;
}

// Operator overloads for <=: Node v. Node, Node v. String, String v. Node
bool operator<=(const Node &left, const Node &right)
{
    return !(right < left);
}
bool operator<=(const Node &left, const std::string &right)
{
    return !(right < left.getData());
}
bool operator<=(const std::string &left, const Node &right)
{
    return !(right.getData() < left);
}

// Operator overloads for >=: Node v. Node, Node v. String, String v. Node
bool operator>=(const Node &left, const Node &right)
{
    return !(left < right);
}
bool operator>=(const Node &left, const std::string &right)
{
    return !(left.getData() < right);
}
bool operator>=(const std::string &left, const Node &right)
{
    return !(left < right.getData());
}