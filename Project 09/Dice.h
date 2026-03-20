//===================================================
// Tren Meckel
// March 8, 2024
// Dice.h
// this is the class header file which contains the class declaration.  
//===================================================

#ifndef DICE_H
#define DICE_H

class Dice {
private:
    int sides;

public:
    // Default constructor
    Dice();

    // Parameterized constructor
    Dice(int numSides);

    // Roll method
    int roll();
};

#endif // DICE_H

