#ifndef PLAYER_H
#define PLAYER_H

#include "Person.h"
#include <string>

class Player : Person
{
private:
    std::string name;

public:
    // constructors
    Player();
    Player(std::string name);

    void placeBet(int bet);
    int payDealer(int amount);
    void updateMoney(int money);
};

#endif