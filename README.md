# Blackjack

This repository contains a simple implementation of the classic card game **Blackjack**, created to help me familiarize myself with the C++ programming language.  

## How to Play

- The objective of Blackjack is to get as close as possible to a total card value of 21 without exceeding it.  
- The game includes a dealer and a player. The dealer follows a fixed set of rules to play their hand.  
- Cards have the following values:
  - Number cards (2–10) are worth their face value.
  - Face cards (Jack, Queen, King) are worth 10 points.
  - Aces are worth either 1 or 11 points, depending on the hand.

## Features

- **Card Deck Management**: A full deck of 52 cards is implemented, shuffled before each game.  
- **Player Options**: Players can `hit` (draw another card) or `stand` (keep their current hand).  
- **Dealer Logic**: The dealer automatically plays after the player, following traditional Blackjack rules.  
- **Winner Determination**: The game compares the player’s and dealer’s hands to decide the winner.  

## How to Run

1. **Clone the Repository**:
   ```bash
   git clone https://github.com/KhaledSaleh2/Blackjack.git
   cd Blackjack

2. **Compile the Code: Use a c++ compiler such as ```g++``` to compile the game**
   ```bash
   g++ -o blackjack Blackjack.cpp

3. **Run the Game: Execute the compiled program:**
   ```bash
   ./blackjack


# Learning Objectives

This project was designed to strengthen my understanding of:
- C++ syntax and basic programming concepts.
- Object-oriented programming principles such as classes and inheritance.
- Handling game logic and user input.


# Possible Future Enhancements
- Implement a graphical interface for the game using a library like SFML.
- Add support for multiple players.
- Incorporate betting mechanics with virtual currency.
