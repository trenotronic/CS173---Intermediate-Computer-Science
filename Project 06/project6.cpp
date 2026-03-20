//====================================
// Coders: Jonah Richardson & Tren Meckel
// Tester: Lal Ertun
// Feb 22 2024
// project6.cpp
// This program reads in what is potentially a roman numeral. If it is a valid Roman numeral, it returns the base 10 value of that numeral.
// 	If it is not a valid Roman numeral, it says so.
//====================================

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool checkValidity(string numeral);
bool orderValidity(string numeral);
void calculateValue(string numeral);

int main(void) {

	string numeral;
	
	//getting the entered numeral from the user and making sure it's capitalized
	cin >> numeral;
	transform(numeral.begin(), numeral.end(), numeral.begin(), ::toupper);
	
	//if it is valid, calculate the value (calculateValue() prints the value)
	if (checkValidity(numeral)) {
	
		calculateValue(numeral);
	//otherwise, reject it
	} else {
	
		cout << "This is not a valid Roman Numeral" << endl;
	
	}

	return 0;

}


bool checkValidity(string numeral) {
	// checkValidity
	// inputs:
	//	numeral: string, is the Roman numeral being evaluated
	// outputs: returns a boolean indicating whether the numeral is valid
	// purpose: checks whether the numeral contains all valid letters, and makes sure there aren't any consectuive set of 4 letters.
	// 	Then it calls the orderValidity function, which makes sure that the actual letters are in a valid order for a correct Roman numeral.
	bool isNumeral;
	int streak = 1;
	int longestStreak = 0;
	int dCount = 0;
	int lCount = 0;
	int vCount = 0;
	string numerals = "MDCLXVI";
	string current = "";
	string last = "";
	
	//going through each letter of the inputted string to check validity
	for (int i = 0; i < numeral.size(); i++) {
		
		//keeping track of the character we are currently on
		current = numeral.substr(i, 1);
		
		//going through the set of available numerals to check if the current character is a valid option
		isNumeral = false;
		for (int j = 0; j < numerals.size(); j++) {
		
			if (current == numerals.substr(j, 1))
				isNumeral = true;
		
		}
		
		//returning false if the current character is not in the valid numerals set, because that would invalidate the inputted string
		if (isNumeral == false)
			return false;
		
		//can't have more than 1 D, L, or V, keeping track every time one is found
		if (current == "D")
			dCount++;
		if (current == "L")
			lCount++;
		if (current == "V")
			vCount++;
		
		//add 1 to the current streak of consecutive numerals if the current one is the same as the last
		if (current == last)
			streak++;
		else
			streak = 1;
		if (streak > longestStreak)
			longestStreak = streak;
			
		//keeping track of the current character for the next loop in case there is a streak of repeated characters
		last = current;
	
	}
	
	//invalid if more than 1 D, L, or V
	if (dCount > 1 || lCount > 1 || vCount > 1)
		return false;
		
	//invalid if there were more than 3 of the same numeral in a row
	if (longestStreak > 3)
		return false;
		
	return orderValidity(numeral);
	
}

bool orderValidity(string numeral) {
	// orderValidity
	// inputs:
	//	numeral: string, is the Roman numeral being evaluated
	// outputs: returns a boolean indicating whether the numeral is valid
	// purpose: checks whether the letters are in a valid order for a correct Roman numeral.

	//each array contains the possible values for that place (power of 10)
	string thousands[3] = {"MMM", "MM", "M"};
	string hundreds[9] = {"DCCC", "CCC", "DCC", "CC", "CD", "DC", "CM", "C", "D"};
	string tens[9] = {"LXXX", "XXX", "LXX", "XX", "XL", "LX", "XC", "X", "L"};
	string ones[9] = {"VIII", "III", "VII", "II", "IV", "VI", "IX", "I", "V"};
	int pointer = 0;
	
	//looking for a thousands value, if it exists, move the pointer past it
	for (int i = 0; i < 3; i++) {
	
		if (numeral.substr(pointer, thousands[i].size()) == thousands[i]) {
			pointer += thousands[i].size();
	
		}
	
	}
	
	//looking for a hundreds value, if it exists, move the pointer past it
	for (int j = 0; j < 9; j++) {
	
		if (numeral.substr(pointer, hundreds[j].size()) == hundreds[j]) {
			pointer += hundreds[j].size();
	
		}
	
	}
	
	//looking for a tens value, if it exists, move the pointer past it
	for (int k = 0; k < 9; k++) {
	
		if (numeral.substr(pointer, tens[k].size()) == tens[k]) {
			pointer += tens[k].size();
	
		}
	
	}
	
	//looking for a ones value, if it exists, move the pointer past it
	for (int m = 0; m < 9; m++) {
	
		if (numeral.substr(pointer, ones[m].size()) == ones[m]) {
			pointer += ones[m].size();
	
		}
	
	}
	
	//if the pointer is the same as the numeral size, it means we got all the way through the numeral, finding value values at every tens place, so it is a valid numeral
	return (pointer == numeral.size());
	
}

void calculateValue(string numeral) {
	// calculateValue
	// inputs:
	//	numeral: string, is the Roman numeral being evaluated
	// outputs: no returns, but prints the base 10 value of the numeral
	// purpose: calculates and prints the value of a valid Roman numeral.

	//each array contains the possible values for that place (power of 10)
	string thousands[3] = {"MMM", "MM", "M"};
	string hundreds[9] = {"DCCC", "CCC", "DCC", "CC", "CD", "DC", "CM", "C", "D"};
	string tens[9] = {"LXXX", "XXX", "LXX", "XX", "XL", "LX", "XC", "X", "L"};
	string ones[9] = {"VIII", "III", "VII", "II", "IV", "VI", "IX", "I", "V"};
	int pointer = 0;
	int sum = 0;
	
	int thousandsVals[3] = {3000, 2000, 1000};
	int hundredsVals[9] = {800, 300, 700, 200, 400, 600, 900, 100, 500};
	int tensVals[9] = {80, 30, 70, 20, 40, 60, 90, 10, 50};
	int onesVals[9] = {8, 3, 7, 2, 4, 6, 9, 1, 5};

	//adding any thousands values and moving the pointer past them if they exist
	for (int i = 0; i < 3; i++) {
	
		if (numeral.substr(pointer, thousands[i].size()) == thousands[i]) {
			pointer += thousands[i].size();
			sum += thousandsVals[i];
	
		}
	
	}
	
	//adding any hundreds values and moving the pointer past them if they exist
	for (int j = 0; j < 9; j++) {
	
		if (numeral.substr(pointer, hundreds[j].size()) == hundreds[j]) {
			pointer += hundreds[j].size();
			sum += hundredsVals[j];
			
		}
	
	}
	
	//adding any tens values and moving the pointer past them if they exist
	for (int k = 0; k < 9; k++) {
	
		if (numeral.substr(pointer, tens[k].size()) == tens[k]) {
			pointer += tens[k].size();
			sum += tensVals[k];
	
		}
	
	}
	
	//adding any ones values and moving the pointer past them if they exist
	for (int m = 0; m < 9; m++) {
	
		if (numeral.substr(pointer, ones[m].size()) == ones[m]) {
			pointer += ones[m].size();
			sum += onesVals[m];
	
		}
	
	}
	
	cout << "The value of the numeral is: " << sum << "." << endl;

}




