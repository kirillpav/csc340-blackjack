#ifndef DEALER_H
#define DEALER_H
#include "Person.h"

class Dealer : Person
{
public:
    void ShuffleCards();
    void PayPlayer();
    Card dealCard();
};

#endif