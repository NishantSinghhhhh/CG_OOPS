#include <iostream>
#include <fstream>
using namespace std;

void calculateFileSize(const string& fileName) {
    ifstream file(fileName, ios::binary | ios::ate); // Open in binary mode, position at end
    if (!file) {
        cout << "Error: Unable to open file " << fileName << endl;
        return;
    }

    streamsize fileSize = file.tellg(); // Get position, equivalent to file size
    file.close();

    cout << "File Size of \"" << fileName << "\": " << fileSize << " bytes" << endl;
}

int main() {
    string fileName;

    cout << "Enter the file name: ";
    cin >> fileName;

    calculateFileSize(fileName);

    return 0;
}
