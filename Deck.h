#ifndef DECK_H
#define DECK_H
#include "card.h"
#include <string>
#include <vector>
#include <iterator>

class Deck
{
private:
    std::vector<Card> cards;

    const std::vector<std::string> suits = {"Hearts", "Diamonds", "Clubs", "Spades"};
    const std::vector<std::string> rank = {"Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King"};

public:
    Deck()
    {
        for (int i = 0; i < suits.size(); i++)
        {
            for (int j = 0; j < rank.size(); j++)
            {
                cards.emplace_back(suits[i], rank[i]);
            }
        }
    }

    void shuffle();
};

#endif