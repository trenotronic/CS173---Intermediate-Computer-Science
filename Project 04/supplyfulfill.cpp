//===================================================
// Tren Meckel
// 9 February 2024
// supplyfulfill.cpp
// This program reads in two integer arrays 
// (Need and Inventory) and determines if the supply 
// array Inventory (B) covers (satisfies or fulfills)
// the needs as represented by array Need (A). 
//===================================================

#include <iostream>
#include <algorithm>
using namespace std;

// declaring function into scope
bool coversInventory(int need[], int needSize, int inventory[], int inventorySize);

int main() 
{
    // Read the size of the Needs array (A)
    int needSize;
    cin >> needSize;
    int need[needSize];
    for (int i = 0; i < needSize; ++i) 
    {
        cin >> need[i];
    }

    // Read the size of the Inventory array (B)
    int inventorySize;
    cin >> inventorySize;
    int inventory[inventorySize];
    for (int i = 0; i < inventorySize; ++i) 
    {
        cin >> inventory[i];
    }

    // Check if Inventory array covers Needs array
    if (coversInventory(need, needSize, inventory, inventorySize)) 
    {
        cout << "satisfies" << endl;
    } else 
    {
        cout << "does not satisfy" << endl;
    }

    return 0;

}

//===================================================
//  coversInventory
// This function checks if the Inventory array covers the Needs array
// It is to return true or false depending on whether or not the given inventory 
// list (array B) covers the needed list of supplies (array A).
// Parameters:
//	int need[]: the array (a)
//	int needSize: the size of the array (how many elements)
//	int inventory[]: the array (b)
// 	int inventorySize: the size of array (how many elements)
// Return Value:
//	True or False (bool) 
//===================================================

bool coversInventory(int need[], int needSize, int inventory[], int inventorySize) 
{
    // Sort both arrays for efficient comparison
    sort(need, need + needSize);
    sort(inventory, inventory + inventorySize);
    
    int i = 0, j = 0;

    // Traverse both arrays simultaneously
    while (i < needSize && j < inventorySize) 
    {
        // If the current element in inventory is less than the current need
        if (inventory[j] < need[i]) 
        {
            j++; // Move to the next element in inventory
        }
        // If the current element in inventory is greater than the current need
        else if (inventory[j] > need[i]) 
        {
            return false; // Element not found in inventory
        }
        // If the current element in inventory is equal to the current need
        else 
        {
            // Increment both pointers to check for the next element
            int countNeed = 1;
            while (i + 1 < needSize && need[i] == need[i + 1]) 
            {
                countNeed++;
                i++;
            }

            int countInventory = 1;
            while (j + 1 < inventorySize && inventory[j] == inventory[j + 1]) 
            {
                countInventory++;
                j++;
            }

            if (countInventory < countNeed) 
            {
                return false; // Inventory doesn't have enough of the current need
            }

            i++; // Move to the next element in needs
            j++; // Move to the next element in inventory
        }
    }

    // If all elements in needs are covered by inventory
    return (i == needSize);
}





































