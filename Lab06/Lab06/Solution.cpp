#include "WordFreq.h"
#include <vector>
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <map>
#include <unordered_map> // Required library for hash table-based map.
#include <algorithm>
#include <cctype>

using namespace std;

// Function that cleans a word and returns a lowercase word consisting only of letters.
string cleanWord(const string& word) {
    string cleaned; // String variable to hold the cleaned word.
    for (char c : word) { // Checks each character of the word.
        if (isalpha(c)) { // If the character is a letter.
            cleaned += tolower(c); // Converts the character to lowercase and adds it to the cleaned string.
        }
    }
    return cleaned; // Returns the cleaned word.
}

// Splits a line into words and adds the cleaned words to the specified vector.
void parseWordsFromLine(const string& line, vector<string>& words) {
    stringstream ss(line); // Creates a string stream to split the line.
    string word; // Temporarily holds each word.
    while (ss >> word) { // Reads word by word from the string stream.
        word = cleanWord(word); // Cleans the read word.
        if (word.length() > 2) { // Adds it if the word's length is greater than 2.
            words.push_back(word); // Adds the cleaned word to the vector.
        }
    }
}

// Helper function that compares two WordFreq objects for sorting.
bool compareWordFreq(const WordFreq& a, const WordFreq& b) {
    return a.freq > b.freq || (a.freq == b.freq && a.word < b.word); // Sorts primarily by frequency, alphabetically if frequencies are equal.
}

///-----------------------------------------------------------------
/// Process the given text file and return the most frequent "k" words
///
vector<WordFreq> GetMostFrequentKWords(string filename, int k) {
    ifstream file(filename); // Opens file input stream.
    if (!file.is_open()) { // Prints an error message if the file cannot be opened.
        cerr << "File not opened" << endl;
        return {}; // Returns an empty vector.
    }

    unordered_map<string, int> wordFreqMap; // Hash table to hold word-frequency pairs.
    string line; // Holds each line read from the file.
    while (getline(file, line)) { // Reads the file line by line.
        vector<string> words; // Temporary vector to hold words in the line.
        parseWordsFromLine(line, words); // Splits the line into words, cleans them, and adds them to the vector.
        for (const string& word : words) { // Processes each word in the vector.
            wordFreqMap[word]++; // Increases the frequency of the word.
        }
    }
    file.close(); // Closes the file.

    vector<WordFreq> wordFreqVector; // Vector to hold word-frequency pairs.
    for (const auto& entry : wordFreqMap) { // Processes each word-frequency pair in the hash table.
        wordFreqVector.emplace_back(entry.first); // Adds a new WordFreq object to the vector.
        wordFreqVector.back().freq = entry.second; // Sets the frequency of the newly added object.
    }

    sort(wordFreqVector.begin(), wordFreqVector.end(), compareWordFreq); // Sorts the words by their frequencies.

    if (k > wordFreqVector.size()) { // Prints a warning message if k exceeds the total number of words.
        cout << "Warning: 'k' exceeds the number of unique words. Showing all words." << endl;
    }

    return vector<WordFreq>(wordFreqVector.begin(), wordFreqVector.begin() + min(k, static_cast<int>(wordFreqVector.size())));
    // Returns the first "k" words. If k is greater than the number of words, returns all words.
} //end-GetMostFrequentKWords

// Function that prints word-frequency pairs to the screen.
void printWordFrequencies(const vector<WordFreq>& wordFreqs) {
    for (const auto& wf : wordFreqs) { // Iterates over each word-frequency pair in the vector.
        cout << wf.word << ": " << wf.freq << endl; // Prints the word and its frequency.
    }
}