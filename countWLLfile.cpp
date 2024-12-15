#include <iostream>
#include <fstream>
#include <cctype> // For isalpha
using namespace std;

void countFileMetrics(const string& fileName) {
    ifstream file(fileName);
    
    if (!file) {
        cout << "Error: Unable to open file " << fileName << endl;
        return;
    }

    int letterCount = 0, wordCount = 0, lineCount = 0;
    string line;

    while (getline(file, line)) {
        ++lineCount; // Count lines
        bool inWord = false;

        for (char ch : line) {
            if (isalpha(ch)) { 
                ++letterCount; // Count letters
            }
            if (isspace(ch)) {
                if (inWord) {
                    ++wordCount; // End of a word
                    inWord = false;
                }
            } else {
                inWord = true; // Inside a word
            }
        }

        // If line ends with a word
        if (inWord) {
            ++wordCount;
        }
    }

    file.close();

    // Output the results
    cout << "File Metrics for \"" << fileName << "\":" << endl;
    cout << "Letters: " << letterCount << endl;
    cout << "Words: " << wordCount << endl;
    cout << "Lines: " << lineCount << endl;
}

int main() {
    string fileName;

    cout << "Enter the file name: ";
    cin >> fileName;

    countFileMetrics(fileName);

    return 0;
}
