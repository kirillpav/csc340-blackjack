#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Node.h"
#include <string>

struct LinkedList
{
private:
    Node *head;
    Node *tail;
    int listSize;

    void setSize(int newSize);
    void setHead(Node *newHead);
    void setTail(Node *newTail);

public:
    LinkedList();
    LinkedList(const std::string &word);
    ~LinkedList();

    // Overloading +=
    LinkedList &operator+=(LinkedList &other);

    Node *getHead() const;
    Node *getTail() const;

    void push_back(const std::string &newWord);
    void push_back(Node *newWordNode);
    Node *insert_before(const std::string &newWord, Node *knownNode);

    int size() const;
    void printToScreen() const;
    void printToScreenReverse() const;
    bool readFromFile(const std::string &fileName);
    bool writeToFile(const std::string &fileName) const;
    Node *deleteWord(Node *nodeToDelete);
    void mergeDicts(LinkedList *listB);
    void mergeSort();
    void mergeSort(LinkedList *topListPtr);
};

#endif