//=========================================
// Coders: Tren Meckel & Lal Ertun
// Tester: Jonah Richardson 
// February 20 2024
// wolfTrack.cpp
// This program reads data from a text file containing GPS coordinates and timestamps
// of wolf pack movements within Yellowstone National Park. The goal is to identify
// the longest out-and-back sequence, where a wolf follows a track, stops, and then
// backtracks on the exact same route. The program processes the data to find the start
// and end timestamps of the longest out-and-back sequence in a 24-hour period and calculates
// the duration between them. It then prints the duration in the "hh:mm" format.
//==========================================

#include <iostream>
#include <iomanip> // for std::setw and std::setfill
#include <string>
using namespace std;

const int MAX_POINTS = 96;

void longestOutAndBack(string times[], int x[], int y[], string& start, string& end);

int main() 
{
    string times[MAX_POINTS];   // Array to store timestamps
    int x[MAX_POINTS], y[MAX_POINTS]; // Arrays to store x and y
    
    // Reading data from standard input
    for (int i = 0; i < MAX_POINTS; ++i) 
    {
        cin >> times[i] >> x[i] >> y[i];
    }
    
    
    string start, end;  // Variables to store start and end timestamps
    longestOutAndBack(times, x, y, start, end); 
    
    // if there is no sequence
    if (start == ""||end == "")
    {
        cout << "00:00" << endl;
        return 0;
    }
    
    // Calculate duration
    int startMinutes = stoi(start.substr(0, 2)) * 60 + stoi(start.substr(3));
    int endMinutes = stoi(end.substr(0, 2)) * 60 + stoi(end.substr(3));
    int duration = endMinutes - startMinutes;
    
    
    // Formatting output
    cout << setw(2) << setfill('0') << duration / 60 << ":" << setw(2) << setfill('0') << duration % 60 << endl;
    return 0;
}

//=================================================
// longestOutAndBack
// This function finds the longest out-and-back sequence
// in the given data.
// PARAMETERS:
// 	times: An array of strings representing timestamps
//      for each data point.
// 	x: An array of integers representing the x-coordinates
//      of wolf locations.
// 	y: An array of integers representing the y-coordinates
//      of wolf locations.
// 	start: A reference to a string to store the start timestamp
//      of the longest out-and-back sequence found.
// 	end: A reference to a string to store the end timestamp
//      of the longest out-and-back sequence found.
// RETURN VALUE:
// 	None. The start and end timestamps are returned via
// 	reference parameters.
//=================================================

void longestOutAndBack(string times[], int x[], int y[], string& start, string& end) 
{ 
    int maxDuration = 0;
    int duration = 0;
    start = end = "";
    
    // Loop through all pairs of timestamps
    for (int i = 0; i < MAX_POINTS; ++i) 
    {
        for (int j = i + 1; j < MAX_POINTS; ++j) 
        {
            bool isOutAndBack = true;
            duration = stoi(times[j].substr(0, 2)) * 60 + stoi(times[j].substr(3,5)) -
                            stoi(times[i].substr(0, 2)) * 60 + stoi(times[i].substr(3,5)); // calculate duration between timestamps
                            
            // No need to check further if duration is less than current max                
            if (duration < maxDuration) 
                continue;
                
            int mid = (i + j) / 2;  // calculate mid-point for comparision
            // check if the sequence is an out-and-back track
            for (int k = i; k <= mid; ++k) 
            {
                int backIdx = j - (k - i);
                // If coordinates don't match, it's not an out-and-back track
                if (x[k] != x[backIdx] || y[k] != y[backIdx]) 
                {
                    isOutAndBack = false;
                    break;
                }
            }
            
            // update maxDuration and start/end timestamps if this sequence is the longest out-and-back track
            if (isOutAndBack && duration > maxDuration) 
            {
                maxDuration = duration;
                start = times[i];
                end = times[j];
            }
        }
    }
}

