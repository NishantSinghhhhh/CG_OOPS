#include <iostream>
#include <cmath> // For sqrt
#include <stdexcept> // For exception handling
using namespace std;

class Quadratic {
private:
    double a, b, c; // Coefficients of the polynomial

public:
    // Default constructor (creates the 0 polynomial)
    Quadratic() : a(0), b(0), c(0) {}

    // Parameterized constructor
    Quadratic(double a, double b, double c) : a(a), b(b), c(c) {}

    // Overloaded operator+ to add two Quadratic polynomials
    Quadratic operator+(const Quadratic& other) const {
        return Quadratic(a + other.a, b + other.b, c + other.c);
    }

    // Overloaded operator>> to read a polynomial
    friend istream& operator>>(istream& in, Quadratic& q) {
        cout << "Enter coefficients a, b, and c (for ax^2 + bx + c): ";
        in >> q.a >> q.b >> q.c;
        return in;
    }

    // Overloaded operator<< to print a polynomial
    friend ostream& operator<<(ostream& out, const Quadratic& q) {
        out << q.a << "x^2 ";
        if (q.b >= 0) out << "+ ";
        out << q.b << "x ";
        if (q.c >= 0) out << "+ ";
        out << q.c;
        return out;
    }

    // Function to evaluate the polynomial for a given value of x
    double eval(double x) const {
        return a * x * x + b * x + c;
    }

    // Function to compute the two solutions of the equation ax^2 + bx + c = 0
    pair<double, double> solve() const {
        if (a == 0) {
            throw invalid_argument("This is not a quadratic equation.");
        }

        double discriminant = b * b - 4 * a * c;
        if (discriminant < 0) {
            throw runtime_error("No real solutions exist.");
        }

        double root1 = (-b + sqrt(discriminant)) / (2 * a);
        double root2 = (-b - sqrt(discriminant)) / (2 * a);
        return {root1, root2};
    }
};

int main() {
    try {
        Quadratic p1, p2;
        cout << "Enter the first polynomial:\n";
        cin >> p1;

        cout << "Enter the second polynomial:\n";
        cin >> p2;

        Quadratic sum = p1 + p2;
        cout << "The sum of the polynomials is: " << sum << endl;

        double x;
        cout << "Enter a value of x to evaluate the first polynomial: ";
        cin >> x;
        cout << "The value of the first polynomial at x = " << x << " is: " << p1.eval(x) << endl;

        cout << "Solving the first polynomial for roots:\n";
        pair<double, double> roots = p1.solve();
        cout << "The roots are: " << roots.first << " and " << roots.second << endl;
    } catch (const exception& e) {
        cout << "Error: " << e.what() << endl;
    }

    return 0;
}
