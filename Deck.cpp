#include "Deck.h"
#include <random>
#include <chrono>

// Constructor that initializes the deck
Deck::Deck() {
    resetDeck();
}

// Method to fill deck with 52 cards
void Deck::fillDeck() {
    cards.clear();
    for (int suit = Card::Hearts; suit <= Card::Spades; ++suit){
        for (int value = Card::Ace; value <= Card::King; ++value) {
            cards.emplace_back(static_cast<Card::Suit>(suit), static_cast<Card::Value>(value));
        }
    }
}
// Method to shuffle the deck
void Deck::shuffleDeck() {
    // randomizes deck
    gen.seed(std::chrono::system_clock::now().time_since_epoch().count());
    std::shuffle(cards.begin(), cards.end(), gen);
}

// Draws card from deck and removes it
Card Deck::draw() {
    Card drawnCard = cards.back();
    cards.pop_back();
    return drawnCard;
}

// Fills and shuffles deck
void Deck::resetDeck() {
    fillDeck();
    shuffleDeck();
}
