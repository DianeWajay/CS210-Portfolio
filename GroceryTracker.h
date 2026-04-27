#ifndef GROCERYTRACKER_H
#define GROCERYTRACKER_H

#include <string>
#include <map>

using namespace std;

// GroceryTracker class
// This class is responsible for reading grocery purchase data from a file,
// storing how many times each item was purchased, and displaying that
// information to the user in different formats.
class GroceryTracker {

public:
    // Constructor
    // Takes the name of the input file and loads all the data when
    // the object is first created
    GroceryTracker(string inputFilename);

    // GetItemFrequency
    // Looks up a specific item and returns how many times it was purchased
    // Returns 0 if the item was not found in the records
    int GetItemFrequency(string item);

    // PrintFrequencyList
    // Prints every item along with the number of times it was purchased
    void PrintFrequencyList();

    // PrintHistogram
    // Prints every item along with a row of asterisks
    // Each asterisk represents one purchase of that item
    void PrintHistogram();

    // WriteBackupFile
    // Saves all item names and their frequencies to an output file
    // This is used to back up the data
    void WriteBackupFile(string outputFilename);

private:
    // frequencyMap
    // This map stores each grocery item as a key and its purchase
    // count as the value. Example: frequencyMap["Potatoes"] = 10
    map<string, int> frequencyMap;

    // LoadFile
    // Opens the input file and reads every item into the frequency map
    // This is called automatically by the constructor
    void LoadFile(string filename);
};

#endif