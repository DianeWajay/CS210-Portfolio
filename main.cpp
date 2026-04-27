// CS 210 - Project Three
//Diane Wajay 
// Corner Grocer Item Tracking Program
//
// This program reads a list of grocery items purchased throughout the day
// from an input file. It then lets the user look up item frequencies,
// view a full list of all items and their counts, and view a histogram.
// A backup file is automatically created when the program starts.

#include <iostream>
#include <string>
#include "GroceryTracker.h"

using namespace std;

int main() {

    // The name of the file that contains the grocery purchase records
    string inputFile = "CS210_Project_Three_Input_File.txt";

    // The name of the backup file that will be created automatically
    string backupFile = "frequency.dat";

    // Create the GroceryTracker object
    // This reads the input file and builds the frequency map right away
    GroceryTracker tracker(inputFile);

    // Write the backup file immediately when the program starts
    // This happens before the menu is shown, with no user input needed
    tracker.WriteBackupFile(backupFile);

    // choice stores which menu option the user picks
    int choice = 0;

    // Keep showing the menu until the user chooses option 4 to exit
    while (choice != 4) {

        // Display the menu options
        cout << endl;
        cout << "=== Corner Grocer Menu ===" << endl;
        cout << "1. Search for an item" << endl;
        cout << "2. Display all item frequencies" << endl;
        cout << "3. Display histogram" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        // Handle bad input - for example if the user types a letter instead of a number
        if (cin.fail()) {
            cin.clear();               // Clear the error so cin works again
            cin.ignore(1000, '\n');    // Throw away the bad input
            cout << "Please enter a number between 1 and 4." << endl;
            choice = 0;               // Reset choice so the loop continues
            continue;
        }

        // Option 1 - Search for a specific item
        if (choice == 1) {
            string searchItem;
            cout << "Enter item name: ";
            cin >> searchItem;

            // Ask the tracker how many times this item was purchased
            int frequency = tracker.GetItemFrequency(searchItem);

            // Tell the user the result
            if (frequency > 0) {
                cout << searchItem << " was purchased " << frequency << " time(s)." << endl;
            }
            else {
                cout << searchItem << " was not found in todays records." << endl;
            }
        }

        // Option 2 - Print the full list of items and their frequencies
        else if (choice == 2) {
            tracker.PrintFrequencyList();
        }

        // Option 3 - Print the histogram
        else if (choice == 3) {
            tracker.PrintHistogram();
        }

        // Option 4 - Exit the program
        else if (choice == 4) {
            cout << "Goodbye!" << endl;
        }

        // Catch anything outside the range 1-4
        else {
            cout << "Please enter a number between 1 and 4." << endl;
        }
    }

    return 0;
}