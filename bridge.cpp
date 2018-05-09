/// File: bridge.cpp
/// Creates a deck of cards, shuffles them and displays them.

#include <iostream>
#include <iomanip>
#include <fstream>
#include "game.h"

const int NUM_DEALS = 4;

using namespace std;

int main(int argc, char *argv[]) {

   Game game;
   ifstream infile;
   bool fromFile = false;

   if (argc == 2) {

      // open the file and check it exists
      infile.open(argv[1]);
      if (infile.fail()) {
         cerr <<  "Error: Could not find file" << endl;
         return 1;
      }
      fromFile = true;
   }

   for (int deal = 0; deal < NUM_DEALS; deal++) {
      game.setup(fromFile);
      if (fromFile) {
         infile >> game;
      }
      game.deal();
      game.auction();
      cout << game << endl;
      cout << endl << "==============================================================" << endl << endl;
      game.nextDealer();

   }


   // close the file
   if (argc ==2) {
      infile.close();
   }

   return 0;
}

