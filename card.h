/// File: card.h
/// This class is responsible for creating and managing Cards and outputting them.
///

#ifndef CARD_H
#define CARD_H
#include <iostream>

using namespace std;

/// Enumerated type of Suit for the Card object.
enum Suit {CLUBS, DIAMONDS, HEARTS, SPADES};

/// Enumerated type of Rank for the Card object.
enum Rank {TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING, ACE};

class Card {
public:

    /// No argument constructor.
    Card();

    /// Constructor that sets the rank and suit for a Card object.
    Card(Rank rank, Suit suit);

    /// Constructor that sets the rank and suit for a Card object from an input string.
    Card(string input);

    /// Destructor – does nothing as no objects are created dynamically by the constructor of this class.
    ~Card();

    /// Accessor for the Rank instance variable.
    Rank getRank() const;

    /// Accessor for the Suit instance variable.
    Suit getSuit() const;

    /// Overloads  the  function  operator  to  provide  a comparison  which  sets  an  ordering  between two Card objects.
    bool operator()(Card* card1, Card* card2);

    /// Puts  a  string  representation  of  this  Card  on the output stream.
    friend ostream& operator<<(ostream& out, const Card& card);

private:
    /// Suit variable for the Card object.
    Suit suit;

    /// Rank variable for the Card object.
    Rank rank;
};

#endif // CARD_H
