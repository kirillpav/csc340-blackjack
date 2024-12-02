#ifndef PERSON_H
#define PEROSON_H

#include <string>

class Person
{
private:
    // Card[] cards; // Using Card class
    int money;

    // Methods, therefore public
public:
    Person();
    // Constructor
    Person(int money);

    int getMoney() const;

    void drawCard();

    void makeMove(std::string move);
};

#endif