/// File: hand.cpp
/// This class is responsible for creating and managing hand objects and outputting them.
/// The Hand class is also responsible for determining the bid that the hand can make using the bidding logic.

#include "hand.h"
#include "deck.h"
#include "card.h"
#include <iostream>
#include <set>

using namespace std;

const int NUMBER_OF_SUITS = 4;

const int JACK_POINTS = 1;
const int QUEEN_POINTS = 2;
const int KING_POINTS = 3;
const int ACE_POINTS = 4;

/// No arguments constructor, initialises all suit collections.
Hand::Hand() {

}

/// Clears all of the suit collections, resets any instance variables to their initial values.
void Hand::clear() {
    for(int hand = 0; hand < NUMBER_OF_SUITS; hand++){
        handArray[hand].clear();
    }
}

/// Adds a Card* to the Hand placing the card with other cards of the same suit.
void Hand::addCard(Card* card) {
    handArray[card->getSuit()].insert(card);
}

/// Responsible for implementing the bidding logic and for  deciding on the bid to be made for this hand. Returns the bid as a string.
string Hand::makeBid() {
    bool balanced = isBalanced();
    int strength = getHandStrength();
    getSuitLengths();
    string bid = getBid(balanced, strength);

    return bid;
}

/// Puts a string representation of a Hand  on the output stream.
ostream& operator<<(ostream& out, Hand& hand) {
    for(int cardSuit = SPADES; cardSuit >= CLUBS; cardSuit--){

        string suitString;
        switch(cardSuit) {
        case SPADES:
            suitString = "Spades   : ";
            break;
        case HEARTS:
            suitString = "Hearts   : ";
            break;
        case DIAMONDS:
            suitString = "Diamonds : ";
            break;
        case CLUBS:
            suitString = "Clubs    : ";
            break;
        default:
            break;
        }

    out << suitString;

    for (set<Card*>::iterator handCard = hand.handArray[cardSuit].begin(); handCard != hand.handArray[cardSuit].end(); handCard++) {
        Card* card = *handCard;
        out << *card << " ";
    }
    out << endl;
    }
    return out;
}

/// Destructor – deletes each Card* in the Hand.
Hand::~Hand() {
    delete[] handArray;
}


/// Populate the length variables for use by the bidding logic.
void Hand::getSuitLengths() {
    highestSuit = 0;
    highestSuitValue = 0;

    for(int handSuit = CLUBS; handSuit < NUMBER_OF_SUITS; handSuit++){
        int suitLength = handArray[handSuit].size();

        switch(handSuit) {
            case CLUBS:
                clubsLength = suitLength;
                break;
            case DIAMONDS:
                diamondsLength = suitLength;
                break;
            case HEARTS:
                heartsLength = suitLength;
                break;
            case SPADES:
                spadesLength = suitLength;
                break;
        }

        if (suitLength >= highestSuitValue) {
            highestSuit = handSuit;
            highestSuitValue = suitLength;
        }
    }
}

/// Check to see if the players hand is balanced or unbalanced.
bool Hand::isBalanced() {

    bool balanced = true;
    int suitHasOnlyTwoCardsCount = 0;

    for(int handSuit = CLUBS; handSuit < NUMBER_OF_SUITS; handSuit++) {
        int suitLength = handArray[handSuit].size();
        if (suitLength == 2) {
            suitHasOnlyTwoCardsCount++;
        }
        else if ((suitLength < 2) | (suitLength > 4)) {
            balanced = false;
        }
        if (suitHasOnlyTwoCardsCount >= 2) {
            balanced = false;
        }
    }
    return balanced;
}

/// Returns the players hand strength. Composed from the sum of High card points and length points.
int Hand::getHandStrength() {
    int highCardPoints = 0;
    int lengthPoints = 0;
    int strength = 0;

    for(int handSuit = CLUBS; handSuit < NUMBER_OF_SUITS; handSuit++) {
        int suitLength = handArray[handSuit].size();

        /// Add Length Points for length over 4.
        if (suitLength > 4) {
            lengthPoints += suitLength -4;
        }

        /// Find high cards and add high card points
        for (set<Card*>::iterator handCard = handArray[handSuit].begin(); handCard != handArray[handSuit].end(); handCard++) {
            Card* card = *handCard;
            switch(card->getRank()) {
                case JACK:
                highCardPoints += JACK_POINTS;
                break;
            case QUEEN:
                highCardPoints += QUEEN_POINTS;
                break;
            case KING:
                highCardPoints += KING_POINTS;
                break;
            case ACE:
                highCardPoints += ACE_POINTS;
                break;
            default:
                break;
            }
        }
        strength = highCardPoints + lengthPoints;
    }
    return strength;
}

/// Determines what the players bid will be based on the hand shape (balance) and hand strength.
string Hand::getBid(bool& balanced, int& strength) {
    if (!balanced) {
        return placeUnbalancedBid(strength);
    }
    else if (balanced) {
        return placeBalancedBid(strength);
    }
    return "failure";
}

/// Place a bid for an Unbalanced hand.
string Hand::placeUnbalancedBid(int& handStrength) {
    if ((handStrength >= 0) & (handStrength <= 12)) {
        if (highestSuitValue == 6) {
                if (highestSuit == 0) {
                    return "PASS";
                }
                else {
                    return "2" + getSuitName(highestSuit);
                }
            }
            else if (highestSuitValue == 7) {
                return "3" + getSuitName(highestSuit);
            }
            else if (highestSuitValue == 8) {
                return "4" + getSuitName(highestSuit);
            }
            return "PASS";
    }
    else if ((handStrength >= 13) & (handStrength <= 21)) {
        if (highestSuitValue == 4) {
            if (clubsLength == 4) {
                return "1C";
            }
            else if (diamondsLength == 4) {
                return "1D";
            }
            else if (heartsLength == 4) {
                return "1H";
            }
            else if (spadesLength == 4) {
                return "1S";
            }
        }
        else {
            return "1" + getSuitName(highestSuit);
        }
    }
    else if (handStrength >= 22) {
        return "2C";
    }
    return "failure";
}


/// Place a bid for a balanced hand.
string Hand::placeBalancedBid(int& handStrength) {
    if ((handStrength >= 0) & (handStrength <= 12)) {
        return "PASS";
    }
    else if (((handStrength >= 13) & (handStrength <= 14)) | ((handStrength >= 18) & (handStrength <= 19))) {
        if (clubsLength == diamondsLength) {
            if (clubsLength == 4) {
                return "1D";
            }
            else if (clubsLength == 3) {
                return "1C";
            }
        }
        if (clubsLength > diamondsLength) {
            return "1C";
        }
        else if (diamondsLength > clubsLength) {
            return "1D";
        }
    }
    else if ((handStrength >= 15) & (handStrength <= 17)) {
        return "1NT";
    }
    else if ((handStrength >= 20) & (handStrength <= 21)) {
        return "2NT";
    }
    else if (handStrength >= 22) {
        return "2C";
    }
    return "failure";
}

/// Find the name of the suit based on a given number (0-3 inclusive, 0 being clubs, 3 being spades)
string Hand::getSuitName(int& suit) {
    switch(suit) {
        case CLUBS:
            return "C";
            break;
        case DIAMONDS:
            return "D";
            break;
        case HEARTS:
            return "H";
            break;
        case SPADES:
            return "S";
            break;
    }
    return "error, name of hand not found";
}

