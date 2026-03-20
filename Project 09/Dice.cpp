//===================================================
// Tren Meckel
// March 8, 2024
// Dice.cpp
// this is the class definition file 
// that contains the three method definitions.  
//===================================================

#include "Dice.h"
#include <cstdlib> // For srand() and rand() functions
#include <ctime>   // For time() function
#include <iostream> // For error message

using namespace std;

//===================================================
// default constructor
// PARAMETERS: none
// RETURN VALUE: none
// It sets up a regular six-side dice.
//===================================================

Dice::Dice() 
{
    // Seed the random number generator with the current time
    srand(static_cast<unsigned int>(time(0)));
    sides = 6; // Set default number of sides to 6
}

//=================================================
// Parameterized constructor for Dice class
// This constructor allows the user to specify the
// number of sides for the dice within the range
// of 2 to 1000 inclusive. If the provided value is
// outside this range, an error is printed, and the
// number of sides is set to the default value of 6.
// PARAMETERS: 
//    numSides: an integer representing the desired
//    number of sides for the dice.
// RETURN VALUE: none
//=================================================

Dice::Dice(int numSides) 
{
    // Seed the random number generator with the current time
    srand(static_cast<unsigned int>(time(0)));
    
    // Validate and set the number of sides
    if (numSides >= 2 && numSides <= 1000) 
    {
        sides = numSides;
    } else 
    {
        // If invalid, print error and set default number of sides to 6
        cerr << "Error: Number of sides must be in the range of 2 to 1000 inclusive. Setting sides to default value of 6." << endl;
        sides = 6;
    }
}

//=================================================
// Roll method for Dice class
// This method simulates rolling the dice and
// returns a random value between 1 and the number
// of sides specified for the dice.
// PARAMETERS: none
// RETURN VALUE:
//    An integer representing the result of the dice roll.
//=================================================

int Dice::roll() 
{
    // Use rand() to obtain a random value between 1 and sides
    return (rand() % sides) + 1;
}





