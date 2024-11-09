#include "Card.h"

// constructor for Card
Card::Card(Suit suit, Value value) : suit(suit), value(value) {}

// prints card to console
void Card::printCard() const {
    std::string suits[] = {"Hearts", "Diamonds", "Clubs", "Spades"};
    std::string values[] = {"Ace", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King"};

    std::cout << values[value - 1] << " of " << suits[suit] << std::endl;
}

// Gets the value of the card
int Card::getValue() const {
    return value;  // Numbered cards return their rank value
}
