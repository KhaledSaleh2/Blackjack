#ifndef BLACKJACK_H
#define BLACKJACK_H

#include "Deck.h"
#include <vector>

class Blackjack {
public:
    Blackjack(); // constructor
    void startGame(); // main logic flow of the game
    void playerTurn(); // handles the player's turns
    void dealerTurn(); // handles the dealer's turns
    void printWinner(); // prints the winner of the round

private:
    Deck deck; // deck of cards for the round
    std::vector<Card> playerHand; // stores player's hand (only one hand now)
    std::vector<Card> dealerHand; // dealer's hand

    // helper functions
    void dealCards(); // deals the initial cards
    void displayHand(const std::vector<Card>& hand, bool dealer = false, bool hideDealer = false); // displays hands
    int valueOfHand(const std::vector<Card>& hand); // calculates hand value
    bool isBust(const std::vector<Card>& hand); // checks if the hand is bust
    bool isBlackjack(const std::vector<Card>& hand); // checks if the hand is blackjack
    bool keepPlaying(); // asks the player if they want to keep playing
};

#endif // BLACKJACK_H
