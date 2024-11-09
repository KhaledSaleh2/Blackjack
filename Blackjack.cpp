#include "Blackjack.h"
#include <iostream>
#include <thread>
#include <chrono>
#include <string>
#include <algorithm>

// constructor
Blackjack::Blackjack() {}

// main logic flow of game
void Blackjack::startGame() {
    int playerWins = 0;
    int dealerWins = 0;
    int ties = 0;
    bool playing = true;
    while (playing){
        dealCards();
        displayHand(playerHand);
        displayHand(dealerHand, true, true);

        // Pause execution for 1 second
        std::this_thread::sleep_for(std::chrono::seconds(1));

        playerTurn();

        if (!isBust(playerHand)) {
            // Pause execution for 1 second
            std::this_thread::sleep_for(std::chrono::seconds(1));
            dealerTurn();
            // dealer doesn't bust
            if (!isBust(dealerHand)) {
                int playerVal = valueOfHand(playerHand);
                int dealerVal = valueOfHand(dealerHand);

                std::cout << "\nYou have: " << playerVal;
                std::cout << "\nThe dealer has: " << dealerVal << "\n";

                // Pause execution for 1 second
                std::this_thread::sleep_for(std::chrono::seconds(1));

                // player wins
                if (playerVal > dealerVal) {
                    std::cout << "\nYou win!\n";
                    playerWins++;
                }
                // dealer wins
                else if (dealerVal > playerVal) {
                    std::cout <<"\nThe dealer wins.\n";
                    dealerWins++;
                }
                // player and dealer tie
                else {
                    ties++;
                    std::cout <<"\nYou tied.\n";
                }
            }
            // dealer busted
            else {
                playerWins++;
            }
        }
        else {
            dealerWins++;
            // Pause execution for 1 second
            std::this_thread::sleep_for(std::chrono::seconds(1));
        }
        std::cout << "\nPlayer wins: " << playerWins;
        std::cout << "\nDealer wins: " << dealerWins;
        std::cout <<"\nTies: " << ties;

        // Pause execution for 1 second
        std::this_thread::sleep_for(std::chrono::seconds(1));

        playing = keepPlaying();
    }
}

// deals one card to player, one card to dealer
void Blackjack::dealCards() {
    // clear cards from previous hand
    playerHand.clear();
    dealerHand.clear();

    // reset deck for next round
    deck.resetDeck();

    std::cout << "\n\nDealing Cards...\n\n";
    // Pause execution for 1 seconds
    std::this_thread::sleep_for(std::chrono::seconds(1));
    playerHand.push_back(deck.draw());
    dealerHand.push_back(deck.draw());
    playerHand.push_back(deck.draw());
}

// handles the players turn
void Blackjack::playerTurn() {
    std::string input; // tracks the users action
    int currHand = 1; // keeps track of which hand is currently being played
    int result = 1; // keeps track of players best hand
    while (true) {
        // gives user his options
        std::cout << "\nType (h)it if you want to hit\n";
        std::cout << "Type (s)tand if you want to stand\n";
        std::cout << "Type (d)isplay if you want to display the hands\n\n";
        // gets input from user
        std::getline(std::cin, input);

        std::string h = "h";
        std::string s = "s";
        std::string d = "d";
        std::string hit = "hit";
        std::string stand = "stand";
        std::string display = "display";

        // Case 1: user says hit
        if (input == h || input == hit) {
            Card newCard = deck.draw();
            playerHand.push_back(newCard);
            std::cout << "\n\nHit!\n\n";

            // Pause execution for 0.5 seconds
            std::this_thread::sleep_for(std::chrono::milliseconds(500));
            std::cout << "\nYou've been dealt a: ";

            // Pause execution for 1 seconds
            std::this_thread::sleep_for(std::chrono::seconds(1));
            newCard.printCard();

            // Pause execution for 1 seconds
            std::this_thread::sleep_for(std::chrono::seconds(1));

            int score = valueOfHand(playerHand);
            std::cout << "\nYour hand has a value of: " << score;
            if (isBust(playerHand)) {
                // Pause execution for 1 seconds
                std::this_thread::sleep_for(std::chrono::seconds(1));
                std::cout << "\nYou busted. The dealer wins >:(\n";
                break;
            }
            else if (isBlackjack(playerHand)) {
                // Pause execution for 0.1 seconds
                std::this_thread::sleep_for(std::chrono::milliseconds(100));
                std::cout << "\nBlackjack!\n";
                break;
            }
            // Pause execution for 4 seconds
            std::this_thread::sleep_for(std::chrono::milliseconds(4000));
        }
        // Case 2: user stands
        else if (input == s || input == stand) {
            std::cout << "\n\nStand!\n\n";
            break;
        }
        // Case 3: the user wants to display the hands again
        else if (input == d || input == display) {
            displayHand(playerHand);
            displayHand(dealerHand, true, true);
        }
        // Case 4: None of the above
        else {
            std::cout << "\nPlease use one of the mentioned actions\n";
        }
    }
}

// handles dealers turn
void Blackjack::dealerTurn() {
    // dealer keeps hitting while hand is under 17
    while (valueOfHand(dealerHand) < 17) {
        Card card = deck.draw();
        dealerHand.push_back(card);
        std::cout << "\nThe dealer was dealt a: ";
        // Pause execution for 1 second
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        card.printCard();
        // Pause execution for 4 seconds
        std::this_thread::sleep_for(std::chrono::milliseconds(4000));
        displayHand(dealerHand, true, false);
        if (isBust(dealerHand)) {
            std::cout << "\nThe dealer busted!\n";
        }
        else if (isBlackjack(dealerHand)) {
            std::cout <<"\nThe dealer has blackjack.\n";
        }
    }
}

// prints both player and dealers hand
void Blackjack::displayHand(const std::vector<Card>& hand, bool dealer, bool hideDealer) {
    if (!dealer) {
        std::cout << "\nPlayer's Hand:\n";
        // Pause execution for 1 seconds
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        for (const auto& card : hand) {
            card.printCard();
        }
        int playerScore = valueOfHand(hand);
        std::cout << "\nPlayer score: " << playerScore << "\n";
    }
    else {
        std::cout << "\nDealer's Hand:\n";
        // Pause execution for 1 second
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        if (hideDealer) {
            dealerHand[0].printCard();
            std::cout << "Hidden Card\n";
        }
        else {
            for (const auto& card : hand) {
                card.printCard();
            }
        }
        int dealerScore = valueOfHand(hand);
        std::cout << "\nDealer score: " << dealerScore << "\n";
    }
    // Pause execution for 1.5 seconds
    std::this_thread::sleep_for(std::chrono::milliseconds(1500));

}

// gets value of a hand
int Blackjack::valueOfHand(const std::vector<Card>& hand) {
    int total = 0;
    int aces = 0;

    for (const auto& card : hand) {
        int value = card.getValue();
        if (value > 10) {
            value = 10;  // Face cards are worth 10
        }
        if (value == 1) {
            aces++;    // Track aces separately to handle 11 or 1 case
        }
        total += value;
    }

    // Convert ace from 1 to 11 if it helps without busting
    while (aces > 0 && total <= 11) {
        total += 10;
        aces--;
    }

    return total;
}

// Checks if hand is a bust or not
bool Blackjack::isBust(const std::vector<Card>& hand){
    if (valueOfHand(hand) > 21) {
        return true;
    }
    return false;
}

// Checks if hand is a blackjack or not
bool Blackjack::isBlackjack(const std::vector<Card>& hand){
    if (valueOfHand(hand) == 21) {
        return true;
    }
    return false;
}

// Asks player if he/she wants to keep playing
bool Blackjack::keepPlaying(){
    std::cout << "\n\nWould you like to keep playing? (Type y/n)\n";
    std::string input;
    std::getline(std::cin, input);

    std::string y = "y";
    std::string n = "n";
    std::string yes = "yes";
    std::string no = "no";

    while (true){
        if (input == y || input == yes){
            return true;
        }
        else if (input == n || input == no) {
            return false;
        }
        else {
            std::cout << "Please type either (y)es or (n)o\n";
            std::getline(std::cin, input);
        }
    }
}