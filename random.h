#ifndef _random_h
#define _random_h


/// This class provides several functions for generating pseud-random numbers.
///
class Random {
public:

   /// \brief
   ///
   /// Initialize the randomizer.
   ///
   Random();


   /// \brief
   ///
   /// Generates a random integer number greater than or equal to low and less than high.
   /// \param low int - lower bound for range (inclusive).
   /// \param high int - upper bound for range (exclusive).
   /// \return int - A random integer number greater than or equal to low and less than high.
   ///
   int randomInteger(int low, int high);

   /// \brief
   /// Generates a random real number greater than or equal to low and less than high.
   ///
   /// \param low double - lower bound for range (inclusive).
   /// \param high double - upper bound for range (exclusive).
   /// \return double - A random real number greater than or equal to low and less than high.
   ///
   double randomReal(double low, double high);

   /// \brief
   /// Generates a true false outcome based on the probability p.
   /// Calling randomChance(0.30) returns true 30% of the time.
   ///
   /// \param p double - Value between 0 (never) and 1 (always).
   /// \return bool - true or false based on p.
   ///
   bool randomChance(double p);

private:

   /// \brief
   ///
   /// Initializes teh random-number generator so that its results are unpredictable.  If this function is
   /// not called the other functions will return the same values on each run.
   ///
   void randomize();
};

#endif // _random_h
