/// File: hand.h
/// This class is responsible for creating and managing hand objects and outputting them.
/// The Hand class is also responsible for determining the bid that the hand can make using the bidding logic.

#ifndef HAND_H
#define HAND_H
#include "deck.h"
#include "card.h"
#include <set>

using namespace std;

class Hand {
public:

    /// No arguments constructor, initialises all suit collections.
    Hand();

    /// Destructor – deletes each Card* in the Hand.
    ~Hand();

    /// Clears all of the suit collections, resets any instance variables to their initial values.
    void clear();

    /// Adds a Card* to the Hand placing the card with other cards of the same suit.
    void addCard(Card*);

    /// Responsible for implementing the bidding logic and for deciding on the bid to be made for this hand. That bid could be PASS. Returns the bid as a string.
    string makeBid();

    /// Puts a string representation of a Hand on the output stream.
    friend ostream& operator<<(ostream& out, Hand& hand);

protected:

private:

    /// Create a hand array holding 4 sets, each one a different suit (clubs, diamonds, hearts, and spades).
    set<Card*, Card> handArray[4];

    /// Create variables for the determination of hand balance and strength to use in the bidding process.
    int clubsLength;
    int diamondsLength;
    int heartsLength;
    int spadesLength;
    int highestSuit;
    int highestSuitValue;

    /// Populate the length variables for use by the bidding logic.
    void getSuitLengths();

    /// Check to see if the players hand is balanced or unbalanced.
    bool isBalanced();

    /// Returns the players hand strength. Composed from the sum of High card points and length points.
    int getHandStrength();

    /// Determines what the players bid will be based on the hand shape (balance) and hand strength.
    string getBid(bool&, int&);

    /// Place a bid for an Unbalanced hand.
    string placeUnbalancedBid(int& strength);

    /// Place a bid for a balanced hand.
    string placeBalancedBid(int& strength);

    /// Find the name of the suit based on a given number (0-3 inclusive, 0 being clubs, 3 being spades)
    string getSuitName(int& suit);
};

#endif // HAND_H
