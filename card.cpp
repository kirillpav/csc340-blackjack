#include "card.h"
using namespace std;
#include <string>

// Constructor
Card::Card(int cardNumber, const string& cardSuit)
    : number(cardNumber), suit(cardSuit) {
    // Determine the rank based on the card number
    if (cardNumber >= 2 && cardNumber <= 10) {
        rank = to_string(cardNumber);
    } else if (cardNumber == 11) {
        rank = "Jack";
        number = 10; // Face cards have a value of 10
    } else if (cardNumber == 12) {
        rank = "Queen";
        number = 10; // Face cards have a value of 10
    } else if (cardNumber == 13) {
        rank = "King";
        number = 10; // Face cards have a value of 10
    } else if (cardNumber == 1) {
        rank = "Ace";
        number = 11; // Default value for Ace is 11; adjust as needed in gameplay logic
    } else {
        rank = "Invalid";
    }
}

// Getters
int Card::getValue() const {
    return number;
}

string Card::getSuit() const {
    return suit;
}

string Card::getRank() const {
    return rank;
}

// String representation of the card
string Card::toString() const {
    return rank + " of " + suit;
}

