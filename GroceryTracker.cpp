#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include "GroceryTracker.h"

using namespace std;

// Constructor
// When a GroceryTracker object is created, it immediately calls LoadFile
// to read the input file and fill up the frequency map
GroceryTracker::GroceryTracker(string inputFilename) {
    LoadFile(inputFilename);
}

// LoadFile
// Opens the input file and reads one item at a time
// Each time an item is read, its count in the map increases by 1
// If the item is new, the map automatically starts its count at 1
void GroceryTracker::LoadFile(string filename) {
    ifstream inputFile;
    string item;

    // Open the input file
    inputFile.open(filename);

    // Make sure the file opened successfully before trying to read it
    if (!inputFile.is_open()) {
        cout << "Error: Could not open file " << filename << endl;
        return;
    }

    // Read one word at a time until the end of the file
    // Each word is one grocery item (ex: "Potatoes")
    while (inputFile >> item) {
        // If the item is already in the map, this adds 1 to its count
        // If the item is new, the map creates it and sets the count to 1
        frequencyMap[item]++;
    }

    // Close the file when done reading
    inputFile.close();
}

// GetItemFrequency
// Searches the map for a specific item and returns how many times it appeared
// Returns 0 if the item does not exist in the map
int GroceryTracker::GetItemFrequency(string item) {

    // Check if the item exists in the map before trying to access it
    if (frequencyMap.count(item) > 0) {
        return frequencyMap[item]; // Return the count for this item
    }
    else {
        return 0; // Item was not found
    }
}

// PrintFrequencyList
// Loops through every item in the map and prints the name and count
// The map is already sorted alphabetically so no sorting is needed
void GroceryTracker::PrintFrequencyList() {
    cout << endl;
    cout << "Item Frequency List" << endl;
    cout << "-------------------" << endl;

    // i points to each item in the map one at a time
    // i->first is the item name, i->second is the count
    for (auto i = frequencyMap.begin(); i != frequencyMap.end(); i++) {
        cout << i->first << " " << i->second << endl;
    }

    cout << endl;
}

// PrintHistogram
// Loops through every item in the map and prints the name followed
// by asterisks. The number of asterisks equals the purchase count.
// Example: Potatoes **********
void GroceryTracker::PrintHistogram() {
    cout << endl;
    cout << "Item Frequency Histogram" << endl;
    cout << "------------------------" << endl;

    // Loop through every item in the map
    for (auto i = frequencyMap.begin(); i != frequencyMap.end(); i++) {

        // Print the item name first
        cout << i->first << " ";

        // Print one asterisk for each time the item was purchased
        for (int j = 0; j < i->second; j++) {
            cout << "*";
        }

        cout << endl;
    }

    cout << endl;
}

// WriteBackupFile
// Creates a new file and writes every item and its frequency to it
// This backup file is named frequency.dat
void GroceryTracker::WriteBackupFile(string outputFilename) {
    ofstream outputFile;
    outputFile.open(outputFilename);

    // Make sure the file was created successfully
    if (!outputFile.is_open()) {
        cout << "Error: Could not create backup file." << endl;
        return;
    }

    // Write each item name and count to the file, one per line
    for (auto i = frequencyMap.begin(); i != frequencyMap.end(); i++) {
        outputFile << i->first << " " << i->second << endl;
    }

    // Close the file when done writing
    outputFile.close();
    cout << "Backup file created: " << outputFilename << endl;
}