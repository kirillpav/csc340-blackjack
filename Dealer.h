#ifndef DEALER_H
#define DEALER_H
#include "Person.h"
#include "card.h"

class Dealer : Person
{
public:
    Dealer();

    void ShuffleCards();
    void PayPlayer(int amount);
    void forceStand();
    Card dealCard();
};

#endif