#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <map>

using namespace std;

// Function to count words in a document
map<string, int> countWords(string filename) {
    ifstream file(filename);
    map<string, int> wordCount;

    if (!file.is_open()) {
        cerr << "Error opening file." << endl;
        return wordCount;
    }

    string word;
    while (file >> word) {
        // Remove punctuation and convert to lowercase
        for (char &c : word) {
            if (!isalnum(c)) {
                c = ' ';
            } else {
                c = tolower(c);
            }
        }
        // Increment word count
        if (!word.empty()) {
            wordCount[word]++;
        }
    }

    file.close();
    return wordCount;
}

int main() {
    string filename;
    cout << "Enter the filename: ";
    cin >> filename;

    map<string, int> wordCount = countWords(filename);

    // Display word counts
    cout << "Word counts:" << endl;
    for (const auto &pair : wordCount) {
        cout << pair.first << ": " << pair.second << endl;
    }

    return 0;
}