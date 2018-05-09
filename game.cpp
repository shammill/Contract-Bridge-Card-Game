/// File: game.cpp
/// This class is responsible for runing the game, including dealing, and bidding.
///
#include "game.h"
#include "deck.h"
#include "card.h"
#include "hand.h"

#include <iostream>
#include <iomanip>
#include <fstream>

const int NUMBER_OF_HANDS = 4;
const int MAX_NUMBER_OF_CARDS_PER_HAND = 13;

using namespace std;

/// No args constructor, initialise the dynamic array of Hand, sets dealer to NORTH.
Game::Game() {
    dealer = NORTH;

    players = new Hand*[NUMBER_OF_HANDS];

    players[NORTH] = new Hand;
    players[EAST] = new Hand;
    players[SOUTH] = new Hand;
    players[WEST] = new Hand;
}

/// If input is NOT to be read from a file, shuffle the deck. Call the reset method on the deck. Also clears each Hand.
void Game::setup (bool fromFile) {
    if (fromFile == false) {
        deck.shuffle();
    }
    deck.reset();
    for (int hand = NORTH; hand < NUMBER_OF_HANDS; hand++) {
        players[hand]->clear();
    }
}

/// Deals the cards from the deck clockwise to each player in turn starting with the player on the dealer’s left.
void Game::deal() {
    Card* dealtCard;

    int currentPosition = dealer + 1;
    for (int card = NORTH; card < MAX_NUMBER_OF_CARDS_PER_HAND; card++) {
        for (int cardsDealt = 0; cardsDealt < NUMBER_OF_HANDS; cardsDealt++) {
        dealtCard = deck.dealNextCard();
            if (currentPosition > WEST) {
                currentPosition = NORTH;
            }
            players[currentPosition]->addCard(dealtCard);
            currentPosition++;
        }
    }
}

/// Starting with the dealer, calls  makeBid() to see what bid is made.  If a bid other than Pass is received from the current Hand, the auction can stop.
void Game::auction() {
    int currentBidder = dealer;
    bool bidDecided = false;
    string currentBid;

    for (int hand = NORTH; hand < NUMBER_OF_HANDS; hand++) {
        if (bidDecided == false) {
            if (currentBidder > WEST) {
                currentBidder = NORTH;
                }
            currentBid = players[currentBidder]->makeBid();
            if (currentBid != "PASS") {
                bidder = currentBidder;
                bidDecided = true;
            }
            currentBidder++;
        }
    }
    bid = currentBid;
}

/// Increments  the  dealer  Position  to  the next player.
void Game::nextDealer() {
    dealer++;
    if (dealer > WEST) {
        dealer = NORTH;
    }
}

/// Puts  a  string  representation  of  the  game onto the output stream.
ostream& operator<<(ostream& out, Game& game) {
    int currentPosition = game.dealer;

    for (int hand = NORTH; hand < NUMBER_OF_HANDS; hand++) {
        if (currentPosition > WEST) {
            currentPosition = NORTH;
            }
        string handName = game.getHandName(currentPosition);
        out << handName << endl << *game.players[currentPosition] << endl;
        currentPosition++;
    }
    if (game.bid == "PASS") {
        out << "All hands PASS";
    }
    else {
        out << "Opening bid is " << game.bid << " made by " << game.getHandName(game.bidder) <<".";
    }
    return out;
}

/// Passes  the  input  stream  onto  the  deck  so that the cards can be read from a text file.
istream& operator>>(istream& in, Game& game) {
    in >> game.deck;
    return in;
}

/// Destructor  responsible  for  discarding  the array.
Game::~Game() {
    delete[] players;
}

/// Returns the corresponding hand/player name based on their number (North, East, etc).
string Game::getHandName(int hand) {
    switch(hand) {
        case NORTH:
            return "NORTH";
            break;
        case EAST:
            return "EAST";
            break;
        case SOUTH:
            return "SOUTH";
            break;
        case WEST:
            return "WEST";
            break;
    }
    return "error, name of hand not found";
}



