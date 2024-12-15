#include <iostream>

using namespace std;

// Template function for Selection Sort
template <class T>
void selection_sort(T a[], int n) {
    int i, j, minIndex;
    T temp;

    // Selection sort algorithm
    for (i = 0; i < n - 1; i++) { // Loop runs up to n-1
        minIndex = i;
        for (j = i + 1; j < n; j++) {
            if (a[j] < a[minIndex]) {
                minIndex = j; // Update minimum index
            }
        }
        // Swap elements
        temp = a[i];
        a[i] = a[minIndex];
        a[minIndex] = temp;
    }

    // Output the sorted array
    cout << "Sorted array: ";
    for (i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

int main() {
    int n, choice;

    do {
        // Menu display
        cout << "\nSelection Sort" << endl;
        cout << "MENU" << endl;
        cout << "1. Integer values" << endl;
        cout << "2. Float values" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: { // Integer sorting
                cout << "Enter the number of integer values in the array: ";
                cin >> n;
                if (n <= 0) {
                    cout << "Invalid size. Size must be positive." << endl;
                    break;
                }
                int* a = new int[n]; // Dynamically allocate memory
                cout << "Enter the integer elements of the array: ";
                for (int i = 0; i < n; i++) {
                    cin >> a[i];
                }
                selection_sort(a, n); // Call selection sort
                delete[] a;           // Free allocated memory
                break;
            }
            case 2: { // Float sorting
                cout << "Enter the number of float values in the array: ";
                cin >> n;
                if (n <= 0) {
                    cout << "Invalid size. Size must be positive." << endl;
                    break;
                }
                float* b = new float[n]; // Dynamically allocate memory
                cout << "Enter the float elements of the array: ";
                for (int i = 0; i < n; i++) {
                    cin >> b[i];
                }
                selection_sort(b, n); // Call selection sort
                delete[] b;           // Free allocated memory
                break;
            }
            case 3: // Exit program
                cout << "Exiting the program. Goodbye!" << endl;
                break;

            default: // Invalid choice
                cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 3);

    return 0;
}
