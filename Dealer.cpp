#include "Dealer.h"
#include "Person.h"
#include "card.h"

#include <string>

using namespace std;

Dealer::Dealer() : Person()
{
}

void Dealer::ShuffleCards()
{
    // shuffle card logic
}

void Dealer::PayPlayer(int amount)
{
    // playerMoney += amount
}

void Dealer::forceStand()
{
}

Card Dealer::dealCard()
{
    // will need some sort of "Deck"
}