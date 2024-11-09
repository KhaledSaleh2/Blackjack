#ifndef DECK_H
#define DECK_H

#include <vector>
#include "Card.h"
#include <random>

class Deck {
public:
    Deck(); // constructor
    Card draw(); // draws a card from the deck
    void shuffleDeck(); // shuffles deck
    void resetDeck(); // fills and shuffles deck

private:
    std::vector<Card> cards;
    std::mt19937 gen;

    void fillDeck(); // files deck with 52 cards (helper method)
};

#endif