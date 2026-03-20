//=================================================
// Tren Meckel
// March 1 2024
// ozoneSim.cpp
// This program simulates the dynamics of ozone holes
// in the atmosphere over time and checks the presence
// of ozone holes at specific points after the simulation.
//=================================================

#include <iostream>

using namespace std;

const int G = 15;

// Structure to represent coordinates
struct Coordinates 
{
    int x;
    int y;
};

// Function declarations
int countNeighboringHoles(char grid[G][G], int row, int col);
void simulateOzoneLayer(Coordinates initialHoles[], int n, char grid[G][G]);

int main() 
{
    // Input initial data
    int n;
    cin >> n;
    Coordinates initialHoles[n];
    for (int i = 0; i < n; ++i) 
    {
        cin >> initialHoles[i].x >> initialHoles[i].y;
    }

    // Input final data
    int m;
    cin >> m;
    Coordinates finalPoints[m];
    for (int i = 0; i < m; ++i) 
    {
        cin >> finalPoints[i].x >> finalPoints[i].y;
    }

    // Simulate ozone layer
    char grid[G][G];
    simulateOzoneLayer(initialHoles, n, grid);

    // Print ozone status for each final data point
    for (int i = 0; i < m; ++i) 
    {
        int row = finalPoints[i].x;
        int col = finalPoints[i].y;
        cout << "(" << row << "," << col << ") ";
        if (grid[row][col] == '0') 
        {
            cout << "hole" << endl;
        } else 
        {
            cout << "no hole" << endl;
        }
    }

    return 0;
}

//=================================================
// printGrid
// This function prints the ozone grid to the console.
// PARAMETERS:
// grid: a 2D character array representing the ozone grid.
// RETURN VALUE:
// None
//=================================================
void printGrid(char grid[G][G]) 
{
    for (int i = 0; i < G; ++i) 
    {
        for (int j = 0; j < G; ++j) 
        {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

//=================================================
// countNeighboringHoles
// This function counts the number of neighboring holes
// around a cell in the ozone grid.
// PARAMETERS:
// grid: a 2D character array representing the ozone grid.
// row: the row index of the cell.
// col: the column index of the cell.
// RETURN VALUE:
// The number of neighboring holes.
//=================================================
int countNeighboringHoles(char grid[G][G], int row, int col) 
{
    int count = 0;
    for (int i = row - 1; i <= row + 1; ++i) 
    {
        for (int j = col - 1; j <= col + 1; ++j) 
        {
            if (i >= 0 && i < G && j >= 0 && j < G &&
             !(i == row && j == col) && grid[i][j] == '0') 
            {
                ++count;
            }
        }
    }
    return count;
}

//=================================================
// simulateOzoneLayer
// This function simulates the dynamics of ozone holes
// in the atmosphere over time.
// PARAMETERS:
// initialHoles: an array of Coordinates representing the initial hole positions.
// n: the number of initial holes.
// grid: a 2D character array representing the ozone grid.
// RETURN VALUE:
// None
//=================================================
void simulateOzoneLayer(Coordinates initialHoles[], int n, char grid[G][G]) 
{
    // Initialize grid with non-hole values
    for (int i = 0; i < G; ++i) 
    {
        for (int j = 0; j < G; ++j) 
        {
            grid[i][j] = 'X';
        }
    }

    // Set initial holes
    for (int i = 0; i < n; ++i) 
    {
        grid[initialHoles[i].x][initialHoles[i].y] = '0';
    }

    // Simulate for 24 months
    for (int month = 0; month <= 24; ++month) 
    {
        // Print current grid
        cout << "Month " << month << ":" << endl;
        printGrid(grid);

        // Skip the last iteration
        if (month == 24) break;

        char nextGrid[G][G]; // Create a copy of the grid for next month
        for (int i = 0; i < G; ++i) 
        {
            for (int j = 0; j < G; ++j) 
            {
                nextGrid[i][j] = grid[i][j];
            }
        }

        // Update grid based on rules
        for (int i = 0; i < G; ++i) 
        {
            for (int j = 0; j < G; ++j) 
            {
                int neighboringHoles = countNeighboringHoles(grid, i, j);
                if (grid[i][j] == '0') 
                { // Cell is currently a hole
                    if (neighboringHoles != 2 && neighboringHoles != 3) 
                    {
                        nextGrid[i][j] = 'X'; // Cell will no longer be a hole
                    }
                } else 
                { // Cell does not currently have a hole
                    if (neighboringHoles == 3) 
                    {
                        nextGrid[i][j] = '0'; // Cell will develop a hole
                    }
                }
            }
        }

        // Update grid for next month
        for (int i = 0; i < G; ++i) 
        {
            for (int j = 0; j < G; ++j) 
            {
                grid[i][j] = nextGrid[i][j];
            }
        }
    }
}


