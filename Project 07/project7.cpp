#include <iostream>
using namespace std;

int oneWeight(int goal, int weights[], int n);
void twoWeight(int goal, int weights[], int n, int solutions[]);
void threeWeight(int goal, int weights[], int n, int solutions[]);
void selectionSort(int array[], int n);

int main(void) {
	int goal;
	int n;
	int oneW;
	int twoW[2];
	int threeW[3];
	int twoWsolutions[] = {0, 0};
	int threeWsolutions[] = {0, 0, 0};
	int twoWsum = 0;
	int threeWsum = 0;

	//goal is the total weight we want to get as close to as possible, and n is the number of weights to be inputted
	cin >> goal;
	cin >> n;
	//generating the list of weights
	int weights[n];
	for (int i = 0; i < n; i++) {

		cin >> weights[i];
	}
	
	cout << "Desired weight : " << goal <<  endl;

	//taking care of the case where we don't get any weights
	if (n < 1)
		cout << "No weights provided";
	//taking care of the case where we get one weight
	else if (n == 1) {

		oneW = oneWeight(goal, weights, n);
		cout << "1 Weight: " << oneW << " for a total of " << oneW << "." << endl;
	//taking care of the case where we only get two weights
	} else if (n == 2) {
		
		oneW = oneWeight(goal, weights, n);
		twoWeight(goal, weights, n, twoWsolutions);
		
		twoWsum = twoWsolutions[0] + twoWsolutions[1];
		//printing the two weight solution if it is the best, otherwise printing the one weight solution
		if (abs(goal - twoWsum) < abs(goal - oneW))
			cout << twoWsolutions[0] << ", " << twoWsolutions[1] << ", sum = " << twoWsum << endl;
		else
			cout << oneW << " for a total of " << oneW << "." << endl;

	} else {
		
		oneW = oneWeight(goal, weights, n);
		twoWeight(goal, weights, n, twoWsolutions);
		threeWeight(goal, weights, n, threeWsolutions);
		
		twoWsum = twoWsolutions[0] + twoWsolutions[1];
		threeWsum = threeWsolutions[0] + threeWsolutions[1] + threeWsolutions[2];
		
		//printing whichever solution gets the closest to the goal weight, using the one that has fewer weights if there are multiple equally effective solutions
		if ((abs(goal - threeWsum) < abs(goal - oneW)) && (abs(goal - threeWsum) < abs(goal - twoWsum)))
			cout << threeWsolutions[0] << ", " << threeWsolutions[1] << ", " << threeWsolutions[2] <<  ", sum = " << threeWsum << endl;
		else if ((abs(goal - twoWsum) <= abs(goal - threeWsum)) && (abs(goal - twoWsum) < abs(oneW)))
			cout << twoWsolutions[0] << ", " << twoWsolutions[1] << ", sum = " << twoWsum << endl;
		else
			cout << oneW << ", sum = " << oneW << endl;
		
	
	}

	return 0;
	
}

int oneWeight(int goal, int weights[], int n) {
	// oneWeight
	// inputs:
	//	goal: int, the weight we are trying to get as close to as possible
	//	weights: array of ints, contains the weights we look in to find a solution
	//	n: int, the number of values in weights[]
	// outputs:
	//	a: int, the weight that is the closest to the goal
	// purpose: gets the optimal 1 weight solution given a list of weights and a goal weight to get as close as possible to
	
	//a stores the value of the current ideal weight
	int a = weights[0];
	for (int i = 0; i < n; i++) {
	
	//checking if any given value in weights[] gets us closer to the goal
	if (abs(goal - weights[i]) < abs(goal - a))
		a = weights[i];

	}
	
	return a;
}

void twoWeight(int goal, int weights[], int n, int solutions[]) {
	// twoWeight
	// inputs:
	//	goal: int, the weight we are trying to get as close to as possible
	//	weights: array of ints, contains the weights we look to combine to find a solution
	//	n: int, the number of values in weights[]
	//	solutions: array of ints, contains the two weights that combine to get the closest to the goal
	// outputs:
	//	no returns, but modifies the solutions[] array (twoWsolutions[] in main) to contain the optimal lists
	// purpose: gets the optimal 2 weight solution given a list of weights and a goal weight to get as close as possible to


	//a and b hold the current ideal weights
	int a = weights[0];
	int b = weights[1];

	for (int i = 0; i < n; i++) {

		for (int j = 0; j < n; j++) {
			//replacing a and b if there is a new combination of two indexes (j != i) that get closer to the goal than the current a and b values
			if ((j != i) && ((abs(goal - (weights[i] + weights[j]))) < abs(goal - (a + b)))) {
				
				a = weights[i];
				b = weights[j];

			}
	
		}

	}
	
	solutions[0] = a;
	solutions[1] = b;

}

void threeWeight(int goal, int weights[], int n, int solutions[]) {
	// threeWeight
	// inputs:
	//	goal: int, the weight we are trying to get as close to as possible
	//	weights: array of ints, contains the weights we look to combine to find a solution
	//	n: int, the number of values in weights[]
	//	solutions: array of ints, contains the two weights that combine to get the closest to the goal
	// outputs:
	//	no returns, but modifies the solutions[] array (threeWsolutions[] in main)to contain the optimal weights
	// purpose: gets the optimal 3 weight solution given a list of weights and a goal weight to get as close as possible to


	//a, b, and c are the indexes of the 3 current optimal weights
	int a = 0;
	int b = 1;
	int c = 2;
	
	//newSet is the collection of new weight indexes that will be tested against the current optimal weights
	int newSet[3];
	
	//solutions holds the indexes of the current optimal weights until the very end of the function
	solutions[0] = a;
	solutions[1] = b;
	solutions[2] = c;
	
	//newCombination tells us whether the new indexes being tested are a new combination of numbers or not
	bool newCombination;
	
	for (int i = 0; i < n; i++) {

		for (int j = 0; j < n; j++) {

			for (int k = 0; k < n; k++) {
				
				//newSet gets the current set of 3 indexes
				newSet[0] = i;
				newSet[1] = j;
				newSet[2] = k;

				//solutions
				selectionSort(solutions, 3);
				selectionSort(newSet, 3);

				//checking if the new i, j, and k are a new combination of indexes.
				//If they are 3 different values, and get closer to the goal than the current a, b, and c indicies, we replace a, b, and c, and the values of the solutions set
				newCombination = false;
				
				if ((i != j) && (i != k) && (j != k)) {
					newCombination = true;
				
				if (newCombination && (abs(goal - (weights[i] + weights[j] + weights[k])) < abs(goal - (weights[a] + weights[b] + weights[c])))) {
					
					
					a = i;
					b = j;
					c = k;
					solutions[0] = a;
					solutions[1] = b;
					solutions[2] = c;
				}


				}

			}

		}

	}
	
	//replacing the solutions set with the actual values, not just the index values
	solutions[0] = weights[solutions[0]];
	solutions[1] = weights[solutions[1]];
	solutions[2] = weights[solutions[2]];
	
}

void selectionSort(int array[], int n) {
	// selectionSort
	// inputs:
	//	array: an array of ints to be sorted
	//	n: int, the number of items in array[]
	// outputs:
	//	no returns, but sorts array[]
	// purpose: sorts an array in ascending numerical order
	
	int min;
	for (int i = 0; i < n; i++) {
	
		min = i;
		for (int j = i; j < n; j++) {
		
			//identifying the minimum value to the right of i that must also be lower than i
			if (array[j] < array[min]) {
			
				min = j;
			
			}
		
		}
		
		//swapping i with the lowest value to the right of i in the array. If there
		//	was not a lower value, this swap function will just swap i with 
		//	itself, so nothing happens
		swap(array[i], array[min]);
	
	}

}
