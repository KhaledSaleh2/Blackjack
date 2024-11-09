#ifndef CARD_H
#define CARD_H

#include <iostream>
#include <string>

class Card {
// constructor for Card
public:
    enum Suit { Hearts, Diamonds, Clubs, Spades };
    enum Value { Ace = 1, Two, Three, Four, Five, Six, Seven, Eight, Nine, Ten, Jack, Queen, King };

    Card(Suit suit, Value value);
    void printCard() const;
    int getValue() const; // gets value of card

private:
    Suit suit; // suit of card (Hearts, Diamonds, etc.)
    Value value; // value of card (Ace - King)
};

#endif