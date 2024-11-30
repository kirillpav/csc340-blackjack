#ifndef CARD_H
#define CARD_H

#include <string>

class Card {
private:
    int number;       // Numerical value (2-10 for number cards, 11 for face cards, 1 or 11 for Ace)
    std::string suit; // e.g., "Hearts", "Diamonds", "Clubs", "Spades"
    std::string rank; // e.g., "2", "King", "Ace"

public:
    // Constructor
    Card(int cardNumber, const std::string& cardSuit);

    // Getters
    int getValue() const;
    std::string getSuit() const;
    std::string getRank() const;

    
    std::string toString() const; // Returns a string representation of the card
};

#endif // CARD_H

