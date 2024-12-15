#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Function to encrypt the contents of a file
void encryptFile(const string& inputFile, const string& outputFile) {
    ifstream in(inputFile, ios::in);
    ofstream out(outputFile, ios::out);

    if (!in.is_open() || !out.is_open()) {
        cout << "Error: Unable to open file(s)." << endl;
        return;
    }

    char ch;
    while (in.get(ch)) {
        out.put(ch + 5); // Simple encryption by shifting ASCII value
    }

    cout << "File encrypted successfully." << endl;

    in.close();
    out.close();
}

// Function to decrypt the contents of a file
void decryptFile(const string& inputFile, const string& outputFile) {
    ifstream in(inputFile, ios::in);
    ofstream out(outputFile, ios::out);

    if (!in.is_open() || !out.is_open()) {
        cout << "Error: Unable to open file(s)." << endl;
        return;
    }

    char ch;
    while (in.get(ch)) {
        out.put(ch - 5); // Simple decryption by reversing the shift
    }

    cout << "File decrypted successfully." << endl;

    in.close();
    out.close();
}

int main() {
    int choice;
    string inputFile, outputFile;

    do {
        cout << "\nFile Encryption & Decryption Menu" << endl;
        cout << "1. Encrypt a File" << endl;
        cout << "2. Decrypt a File" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the name of the file to encrypt: ";
                cin >> inputFile;
                cout << "Enter the name of the output encrypted file: ";
                cin >> outputFile;
                encryptFile(inputFile, outputFile);
                break;

            case 2:
                cout << "Enter the name of the file to decrypt: ";
                cin >> inputFile;
                cout << "Enter the name of the output decrypted file: ";
                cin >> outputFile;
                decryptFile(inputFile, outputFile);
                break;

            case 3:
                cout << "Exiting the program." << endl;
                break;

            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 3);

    return 0;
}
