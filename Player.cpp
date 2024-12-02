#include "Player.h"
#include "Person.h"
#include <string>

using namespace std;

Player::Player() : Person()
{
}

Player::Player(string name) : Person()
{
    name = name;
}

void Player::placeBet(int bet)
{
}

int Player::payDealer(int amount)
{
    // dealerMoney += amount;
}

void Player::updateMoney(int money)
{
    // playerMoney = money;
}

void Player::hit()
{
}

void Player::stand()
{
}