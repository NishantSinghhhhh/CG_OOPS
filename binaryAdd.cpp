#include <iostream>
#include <stack>
using namespace std;

void addBinary(const string& binary1, const string& binary2) {
    stack<int> stack1, stack2, result;

    // Push binary digits of the first number into stack1
    for (char bit : binary1) {
        stack1.push(bit - '0');
    }

    // Push binary digits of the second number into stack2
    for (char bit : binary2) {
        stack2.push(bit - '0');
    }

    int carry = 0;

    // Add the two binary numbers bit by bit
    while (!stack1.empty() || !stack2.empty() || carry != 0) {
        int bit1 = 0, bit2 = 0;

        if (!stack1.empty()) {
            bit1 = stack1.top();
            stack1.pop();
        }

        if (!stack2.empty()) {
            bit2 = stack2.top();
            stack2.pop();
        }

        int sum = bit1 + bit2 + carry;
        result.push(sum % 2); // Push the current bit of the result
        carry = sum / 2;      // Update carry
    }

    // Print the result binary number
    cout << "Result: ";
    while (!result.empty()) {
        cout << result.top();
        result.pop();
    }
    cout << endl;
}

int main() {
    string binary1, binary2;

    // Input two binary numbers
    cout << "Enter the first binary number: ";
    cin >> binary1;

    cout << "Enter the second binary number: ";
    cin >> binary2;

    // Call the function to add the binary numbers
    addBinary(binary1, binary2);

    return 0;
}
