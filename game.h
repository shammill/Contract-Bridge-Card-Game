/// File: game.h
/// This class is responsible for runing the game, including dealing, and bidding.
///

#ifndef GAME_H
#define GAME_H

#include "deck.h"
#include "card.h"
#include "hand.h"

#include <iostream>
#include <iomanip>
#include <fstream>

enum Position {NORTH, EAST, SOUTH, WEST};

using namespace std;

class Game {
public:

    /// No  args  constructor,  initialise  the  dynamic array of Hand, sets dealer to NORTH.
    Game();

    /// If input is NOT to be read from a file, shuffle the deck. Call the reset method on the deck. Also clears each Hand.
    void setup (bool fromFile);

    /// Deals  the  cards  from  the  deck  clockwise  to  each  player  in  turn  starting  with  the  player on the dealer’s left.
    void deal();

    /// Starting with the dealer, calls  makeBid() to see what bid is made.  If a bid other than  Pass is received from the current Hand, the  auction can stop.
    void auction();

    /// Increments  the  dealer  Position  to  the next player.
    void nextDealer();

    /// Puts  a  string  representation  of  the  game onto the output stream.
    friend ostream& operator<<(ostream& out, Game& game);

    /// Passes  the  input  stream  onto  the  deck  so that the cards can be read from a text file.
    friend istream& operator>>(istream& in, Game& game);

    /// Destructor  responsible  for  discarding  the array.
    ~Game();

protected:

private:

    /// Create game variables to keep track of dealer and bidder states.
    int dealer;
    int bidder;
    string bid;

    /// Create a deck object for the game.
    Deck deck;

    /// Create a players array with containing points to their hands.
    Hand** players;

    /// Returns the corresponding hand/player name based on their number (North, East, etc).
    string getHandName(int hand);
};

#endif // GAME_H
