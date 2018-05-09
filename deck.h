/// File: deck.h
/// This class is responsible for creating and managing the deck for the game.
///

#ifndef DECK_H
#define DECK_H
#include "card.h"

using namespace std;

class Deck {
public:

    /// No Argument constructor – Creates a dynamically allocated array of Card* objects and initialises them. Initialises cardsDealt to 0.
    Deck();

    /// Destructor – deletes the contents of the array of Card*.
    ~Deck();

    /// Sets cardsDealt to 0.
    void reset();

    /// Returns a pointer to the next Card object from the deck, increments cardsDealt.
    Card* dealNextCard();

    /// Shuffles cards in the deck.
    void shuffle();

    /// Puts a string representation of the Card objects in the deck to the screen.
    friend ostream& operator<<(ostream& out, Deck& deck);

    /// Reads 52 strings from an input stream, where each string represents a card e.g. 2C, AD, JH, constructing a Card* and assigning them into the array of Card*.
    friend istream& operator>>(istream& in, Deck& deck);

protected:

private:

    /// Counter for how many cards have been dealt out of the deck.
    int cardsDealt;

    /// Deck array for containing pointers to the card objects.
    Card** deckArray;
};

#endif // DECK_H
