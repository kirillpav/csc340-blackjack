#include "LinkedList.h"
#include "Media.h"
#include <iostream>
#include <fstream>

using namespace std;

LinkedList::LinkedList()
{
    head = nullptr;
    tail = nullptr;
    listSize = 0;
}

LinkedList::LinkedList(Media *media)
{
    head = nullptr;
    tail = nullptr;
    listSize = 0;
    push_back(media);
}

LinkedList::~LinkedList()
{
    Node *current = head;
    while (current != nullptr)
    {
        Node *next = current->getNext();
        delete current;
        current = next;
    }
}

Node *LinkedList::getHead() const
{
    return head;
}

Node *LinkedList::getTail() const
{
    return tail;
}

void LinkedList::setHead(Node *newHead)
{
    head = newHead;
}

void LinkedList::setTail(Node *newTail)
{
    tail = newTail;
}

void LinkedList::setSize(int newSize)
{
    listSize = newSize;
}

void LinkedList::push_back(Media *media)
{
    Node *newNode = new Node(media);
    if (head == nullptr)
    {
        head = newNode;
        tail = newNode;
    }
    else
    {
        tail->setNext(newNode);
        newNode->setPrev(tail);
        tail = newNode;
    }
    listSize++;
}

// Overloading push_back
void LinkedList::push_back(Node *newWordNode)
{
    if (head == nullptr)
    {
        head = newWordNode;
        tail = newWordNode;
    }
    else
    {
        tail->setNext(newWordNode);
        newWordNode->setPrev(tail);
        tail = newWordNode;
    }
    listSize++;
}

// Insert Before Method
Node *LinkedList::insert_before(Media *media, Node *knownNode)
{
    Node *newNode = new Node(media);

    if (head == nullptr)
    {
        head = newNode;
        tail = newNode;
    }
    else if (knownNode == head)
    {
        newNode->setNext(head);
        head->setPrev(newNode);
        head = newNode;
    }
    else
    {
        Node *prevNode = knownNode->getPrev();

        newNode->setNext(knownNode);
        newNode->setPrev(prevNode);

        if (prevNode != nullptr)
        {
            prevNode->setNext(newNode);
        }

        knownNode->setPrev(newNode);
    }

    listSize++;

    return newNode;
}

int LinkedList::size() const
{
    return listSize;
}

void LinkedList::printToScreen() const
{
    Node *current = head;
    while (current != nullptr)
    {
        if (current->getData() != nullptr)
        {
            cout << "Type: " << (current->getData()->getMediaType()) << endl;
            cout << "Name: " << (current->getData()->getName()) << endl;
            cout << "Status: " << (current->getData()->getStatus()) << endl;
            cout << "Year Released: " << (current->getData()->getYearReleased()) << endl;
            cout << "----------------------------------------" << endl;
        }
        current = current->getNext(); // Move to the next node
    }
}

Node *LinkedList::deleteMedia(Node *nodeToDelete)
{
    if (nodeToDelete == nullptr)
    {
        return nullptr;
    }

    Node *nextNode = nodeToDelete->getNext();

    if (nodeToDelete == head)
    {
        head = nextNode;
    }

    if (nodeToDelete == tail)
    {
        tail = nodeToDelete->getPrev();
    }

    if (nodeToDelete->getPrev() != nullptr)
    {
        nodeToDelete->getPrev()->setNext(nextNode);
    }

    if (nextNode != nullptr)
    {
        nextNode->setPrev(nodeToDelete->getPrev());
    }

    nodeToDelete->setNext(nullptr);
    nodeToDelete->setPrev(nullptr);
    delete nodeToDelete;
    listSize--;

    return nextNode;
}

// += operator overload implementation
LinkedList &LinkedList::operator+=(LinkedList &other)
{
    Node *current = other.getHead();

    while (current != nullptr)
    {
        Node *nextNode = current->getNext();
        if (current->getPrev() != nullptr)
        {
            current->getPrev()->setNext(current->getNext());
        }
        if (current->getNext() != nullptr)
        {
            current->getNext()->setPrev(current->getPrev());
        }
        if (current == other.getHead())
        {
            other.setHead(nextNode);
        }
        if (current == other.getTail())
        {
            other.setTail(current->getPrev());
        }

        current->setNext(nullptr);
        current->setPrev(nullptr);
        this->push_back(current);
        current = nextNode;
    }
    other.setSize(0);

    return *this;
}

// Merge dict implementation
void LinkedList::mergeDicts(LinkedList *listB)
{
    // Checking if second dict exists
    if (listB == nullptr || listB->head == nullptr)
    {
        return;
    }

    Node *currA = head;
    Node *currB = listB->head;

    // If current dict doesnt exists, set current dict to second dict
    if (head == nullptr)
    {
        head = listB->head;
        tail = listB->tail;
        listSize = listB->listSize;
        listB->listSize = 0;
        listB->head = nullptr;
        listB->tail = nullptr;
        return;
    }
}

Media* LinkedList::linearSearch(const string& title) const
{
    Node *current = head;
    
    // Traverse the list and search for the title
    while (current != nullptr)
    {
        if (current->getData() != nullptr && current->getData()->getName() == title)
        {
            return current->getData();  // Return the Media pointer if a match is found
        }
        current = current->getNext();
    }

    return nullptr;  // Return nullptr if not found
}


// Create a temp node to make insertion easier
//     Node temp;
//     Node *merged = &temp;
//     merged->setNext(nullptr);

//     while (currA != nullptr && currB != nullptr)
//     {
//         Node *nextB = currB->getNext();

//         if (currA->getWord() < currB->getWord())
//         {
//             merged->setNext(currA);
//             currA->setPrev(merged);
//             currA = currA->getNext();
//         }
//         else if (currA->getWord() > currB->getWord())
//         {
//             merged->setNext(currB);
//             currB->setPrev(merged);
//             currB->setNext(currA);
//             if (currA != nullptr)
//             {
//                 currA->setPrev(currB);
//             }
//             listB->listSize--;
//             listSize++;
//             currB = nextB;
//         }
//         else
//         {
//             Node *toDelete = currB;
//             currB = nextB;
//             listB->listSize--;
//             delete toDelete;

//             merged->setNext(currA);
//             currA->setPrev(merged);
//             currA = currA->getNext();
//         }
//         merged = merged->getNext();
//     }

//     if (currB != nullptr)
//     {
//         merged->setNext(currB);
//         currB->setPrev(merged);
//         tail = listB->tail;
//         listSize += listB->listSize;
//     }

//     head = temp.getNext();
//     if (head != nullptr)
//     {
//         head->setPrev(nullptr);
//     }
//     listB->head = nullptr;
//     listB->tail = nullptr;
//     listB->listSize = 0;
// }

// void LinkedList::mergeSort()
// {
//     // Base case
//     if (head == nullptr || head->getNext() == nullptr)
//     {
//         return;
//     }

//     LinkedList *secondHalf = new LinkedList();

//     int midPoint = listSize / 2;
//     Node *current = head;

//     for (int i = 0; i < midPoint - 1; i++)
//     {
//         current = current->getNext();
//     }

//     secondHalf->setHead(current->getNext());
//     if (secondHalf->getHead() != nullptr)
//     {
//         secondHalf->getHead()->setPrev(nullptr);
//     }
//     current->setNext(nullptr);

//     secondHalf->setSize(listSize - midPoint);
//     setSize(midPoint);

//     current = head;
//     while (current->getNext() != nullptr)
//     {
//         current = current->getNext();
//     }
//     tail = current;

//     current = secondHalf->getHead();
//     while (current->getNext() != nullptr)
//     {
//         current = current->getNext();
//     }
//     secondHalf->setTail(current);

//     this->mergeSort(this);
//     this->mergeSort(secondHalf);

//     this->mergeDicts(secondHalf);

//     delete secondHalf;
// }

// void LinkedList::mergeSort(LinkedList *topListPtr)
// {
//     // Base case
//     if (topListPtr == nullptr || topListPtr->getHead() == nullptr ||
//         topListPtr->getHead()->getNext() == nullptr)
//     {
//         return;
//     }

//     LinkedList *secondHalf = new LinkedList();

//     int midPoint = topListPtr->size() / 2;
//     Node *current = topListPtr->getHead();

//     for (int i = 0; i < midPoint - 1; i++)
//     {
//         current = current->getNext();
//     }

//     secondHalf->setHead(current->getNext());
//     if (secondHalf->getHead() != nullptr)
//     {
//         secondHalf->getHead()->setPrev(nullptr);
//     }
//     current->setNext(nullptr);

//     secondHalf->setSize(topListPtr->size() - midPoint);
//     topListPtr->setSize(midPoint);

//     current = topListPtr->getHead();
//     while (current->getNext() != nullptr)
//     {
//         current = current->getNext();
//     }
//     topListPtr->setTail(current);

//     current = secondHalf->getHead();
//     while (current->getNext() != nullptr)
//     {
//         current = current->getNext();
//     }
//     secondHalf->setTail(current);

//     mergeSort(topListPtr);
//     mergeSort(secondHalf);

//     topListPtr->mergeDicts(secondHalf);

//     delete secondHalf;
// }