/// File: deck.cpp
/// This class is responsible for creating and managing the deck for the game.
///

#include "deck.h"
#include "card.h"
#include "random.h"
#include <algorithm>
#include <iostream>

using namespace std;

const int NUMBER_OF_CARDS = 52;
const int NUMBER_OF_RANKS = 13;
const int NUMBER_OF_SUITS = 4;

/// No Argument constructor – Creates a dynamically allocated array of Card* objects and initialises them. Initialises cardsDealt to 0.
Deck::Deck() {
    deckArray = new Card*[NUMBER_OF_CARDS];

    int index = 0;
    for (int rank = 0; rank < NUMBER_OF_RANKS; rank++) {
        for (int suit = 0; suit < NUMBER_OF_SUITS; suit++) {
            Card *card = new Card((Rank)rank, (Suit)suit);
            deckArray[index] = card;
            index++;
        }
    }
    cardsDealt = 0;
}

/// Returns a pointer to the next Card object from the deck, increments cardsDealt.
Card* Deck::dealNextCard() {
    Card* dealtCard = deckArray[cardsDealt];
    cardsDealt++;

    return dealtCard;
}

/// Sets cardsDealt to 0.
void Deck::reset() {
    cardsDealt = 0;
}

/// Shuffles cards in the deck.
void Deck::shuffle() {
    Random randomizer;
    random_shuffle(&deckArray[0], &deckArray[NUMBER_OF_CARDS]);
}

/// Puts a string representation of the Card objects in the deck to the screen.
ostream& operator<<(ostream& out, Deck& deck) {
    for(int card = 0; card < NUMBER_OF_CARDS; card++) {
        Card* dealtCard = deck.deckArray[card];
        out << *dealtCard << " ";
    }
    return out;
}

/// Reads  52  strings  from an input stream, where each string  represents  a  card  e.g.  2C,  AD,  JH,
/// constructing  a  Card*  and  assigning  them  into  the array of Card*.
istream& operator>>(istream& in, Deck& deck) {
    string cardString;

    for(int index = 0; index < NUMBER_OF_CARDS; index++) {
        in >> cardString;
        Card *card = new Card(cardString);
        deck.deckArray[index] = card;
    }
    return in;
}

/// Destructor – deletes  the  contents  of  the  array  of Card*.
Deck::~Deck() {
    delete[] deckArray;
}
