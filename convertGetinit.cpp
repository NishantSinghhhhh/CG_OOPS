#include <iostream>
using namespace std;

// Base class
class Convert {
protected:
    double val1; // Initial value
    double val2; // Converted value

public:
    // Constructor
    Convert(double initial) : val1(initial), val2(0) {}

    // Getter for the initial value
    double getInit() const {
        return val1;
    }

    // Getter for the converted value
    double getConv() const {
        return val2;
    }

    // Pure virtual function for performing conversion
    virtual void compute() = 0;

    // Virtual destructor
    virtual ~Convert() {}
};

// Derived class: Fahrenheit to Celsius
class FahrenheitToCelsius : public Convert {
public:
    // Constructor
    FahrenheitToCelsius(double fahrenheit) : Convert(fahrenheit) {}

    // Override compute() to perform the conversion
    void compute() override {
        val2 = (val1 - 32) * 5 / 9;
    }
};

// Derived class: Kilometers to Miles
class KilometersToMiles : public Convert {
public:
    // Constructor
    KilometersToMiles(double kilometers) : Convert(kilometers) {}

    // Override compute() to perform the conversion
    void compute() override {
        val2 = val1 * 0.621371;
    }
};

int main() {
    // Example: Convert Fahrenheit to Celsius
    double fahrenheit;
    cout << "Enter temperature in Fahrenheit: ";
    cin >> fahrenheit;
    FahrenheitToCelsius fToC(fahrenheit);
    fToC.compute();
    cout << fahrenheit << " Fahrenheit is " << fToC.getConv() << " Celsius." << endl;

    // Example: Convert Kilometers to Miles
    double kilometers;
    cout << "Enter distance in Kilometers: ";
    cin >> kilometers;
    KilometersToMiles kmToMiles(kilometers);
    kmToMiles.compute();
    cout << kilometers << " Kilometers is " << kmToMiles.getConv() << " Miles." << endl;

    return 0;
}
