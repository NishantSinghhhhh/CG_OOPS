#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main() {
    const string filename = "example.txt";

    // Writing to the file
    {
        ofstream outFile(filename);
        if (!outFile) {
            cerr << "Error opening file to write." << endl;
            return 1;
        }
        outFile << "Hello, World" << endl;
        outFile << "This is a simple C++ program." << endl;
        outFile << "Goodbye!" << endl;
        outFile.close();
    }

    // Reading from the file
    {
        ifstream inFile(filename);
        if (!inFile) {
            cerr << "Error opening file for reading." << endl;
            return 1;
        }
        string line;
        while (getline(inFile, line)) {
            cout << line << endl;
        }
        inFile.close();
    }

    return 0;
}
