/// File: card.cpp
/// This class is responsible for creating and managing Cards and outputting them.
///

#include "card.h"
#include <iostream>

using namespace std;

const int RANK_INDEX = 0;
const int SUIT_INDEX = 1;

/// No argument constructor.
Card::Card() {
    rank = TWO;
    suit = CLUBS;
}

/// Constructor  that  sets  the  rank  and  suit  for  a Card object.
Card::Card(Rank rank, Suit suit) {
    this->rank = rank;
    this->suit = suit;
}

/// Constructor  that  sets  the  rank  and  suit  for  a Card object from an input string.
Card::Card(string input) {
    char rankString = input.at(RANK_INDEX);
    char suitString = input.at(SUIT_INDEX);

    switch(rankString) {
    case '2':
        rank = TWO;
        break;
    case '3':
        rank = THREE;
        break;
    case '4':
        rank = FOUR;
        break;
    case '5':
        rank = FIVE;
        break;
    case '6':
        rank = SIX;
        break;
    case '7':
        rank = SEVEN;
        break;
    case '8':
        rank = EIGHT;
        break;
    case '9':
        rank = NINE;
        break;
    case 'T':
        rank = TEN;
        break;
    case 'J':
        rank = JACK;
        break;
    case 'Q':
        rank = QUEEN;
        break;
    case 'K':
        rank = KING;
        break;
    case 'A':
        rank = ACE;
        break;
    }

    switch(suitString) {
    case 'C':
        suit = CLUBS;
        break;
    case 'D':
        suit = DIAMONDS;
        break;
    case 'H':
        suit = HEARTS;
        break;
    case 'S':
        suit = SPADES;
        break;
    }
}

/// Accessor for the Rank instance variable.
Rank Card::getRank() const {
    return rank;
}

/// Accessor for the Suit instance variable.
Suit Card::getSuit() const {
    return suit;
}

/// Overloads  the  function  operator  to  provide  a comparison  which  sets  an  ordering  between two Card objects.
bool Card::operator()(Card* card1, Card* card2) {
    if (card1->getRank() < card2->getRank()) {
        return false;
    }
    return true;
}

/// Puts  a  string  representation  of  this  Card  on the output stream.
ostream& operator<<(ostream& out, const Card& card) {
    Rank cardRank = card.getRank();
    Suit cardSuit = card.getSuit();

    string rankString;
    string suitString;

    switch(cardRank) {
    case TWO:
        rankString = '2';
        break;
    case THREE:
        rankString = '3';
        break;
    case FOUR:
        rankString = '4';
        break;
    case FIVE:
        rankString = '5';
        break;
    case SIX:
        rankString = '6';
        break;
    case SEVEN:
        rankString = '7';
        break;
    case EIGHT:
        rankString = '8';
        break;
    case NINE:
        rankString = '9';
        break;
    case TEN:
        rankString = 'T';
        break;
    case JACK:
        rankString = 'J';
        break;
    case QUEEN:
        rankString = 'Q';
        break;
    case KING:
        rankString = 'K';
        break;
    case ACE:
        rankString = 'A';
        break;
    }

    switch(cardSuit) {
    case CLUBS:
        suitString = 'C';
        break;
    case DIAMONDS:
        suitString = 'D';
        break;
    case HEARTS:
        suitString = 'H';
        break;
    case SPADES:
        suitString = 'S';
        break;
    }
    out << rankString << suitString;
    return out;
}

/// Destructor – does nothing as no objects are created dynamically by the constructor of this class.
Card::~Card() {
    //dtor
}
