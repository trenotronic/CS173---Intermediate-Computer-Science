//================================================
//  Tren Meckel
//  2 February 2024
//  euclidsGCD.cpp
// This is a program that reads in two integer
// inputs (x and y) and outputs the GCD of x and y
// Also accounts for incorrect inputs as negative values
// and floats, prompts the user to type in a int value
//================================================

#include <iostream>
#include <climits> 
using namespace std;

// Function to calculate the Greatest Common Divisor (GCD)
int findGCD(int x, int y);

//=================================================
// findGCD
// This function calculates the Greatest Common Divisor
// (GCD) of two integers x and y using Euclid's algorithm.
// It repeatedly replaces the two numbers with their remainder
// when divided until one of them becomes 0. The GCD is the
// other remaining non-zero number. The function returns the GCD.
// Parameters:
//  int x: number input by user
//  int y: another number input by user
// Return Value:
//  GCD of two ints (x and y)
//==================================================

int findGCD(int x, int y)
{
    while (y != 0) 
    {
        int temp = y;
        y = x % y;
        x = temp;
    }
    return x;
}


int main( void )
{
    // Input variables
    int x, y;

    // Prompt user for input
    cout << "Enter a positive integer (x): ";

    // Input validation for integer
    while (!(cin >> x) || x < 0|| cin.get() != '\n')
    {
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        cerr << "Error. Please enter a valid positive integer for x: ";

    }

    cout << "Enter another positive integer (y): ";

    // Input validation for integer
    while (!(cin >> y) || y < 0 || cin.get() != '\n')
    {
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        cerr << "Error. Please enter a valid positive integer for y: ";

    }


    // Calculate and output GCD
    int gcd = findGCD(x, y);
    cout << "GCD(" << x << ", " << y << ") ==> " << gcd << endl;

    return 0;
}


