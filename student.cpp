#include <iostream>
#include <string>
#include <vector>
#include <limits> // For numeric_limits
#include <stdexcept> // For exceptions

using namespace std;

class StudData;

class Student {
    string name;
    int roll_no;
    string cls;
    string division;
    string dob;
    string bloodgroup;
    StudData* studData;  // Raw pointer for dynamic memory
    static int count;

public:
    // Default Constructor
    Student()
        : name(""), roll_no(0), cls(""), division("Unknown"), dob("dd/mm/yyyy"), bloodgroup("Unknown"), studData(nullptr) {
        count++;
    }

    // Copy Constructor
    Student(const Student& other);

    // Destructor
    ~Student();

    // Static member function
    static int getCount() {
        return count;
    }

    // Member functions
    void getData();
    void dispData() const;

    // Friend function declaration
    friend void displayAllDetails(const Student& student);
};

class StudData {
    string caddress;
    long telno;
    long dlno;

    friend class Student;  // Allow Student class to access private members

public:
    StudData() : caddress(""), telno(0), dlno(0) {}

    // Copy Constructor
    StudData(const StudData& other)
        : caddress(other.caddress), telno(other.telno), dlno(other.dlno) {}

    // Destructor
    ~StudData() = default;

    void getStudData() {
        try {
            cout << "Enter Contact Address: ";
            cin >> ws;  // Ignore leading whitespace
            getline(cin, caddress);

            cout << "Enter Telephone Number: ";
            if (!(cin >> telno) || telno <= 0) throw invalid_argument("Invalid telephone number!");

            cout << "Enter Driving License Number: ";
            if (!(cin >> dlno) || dlno <= 0) throw invalid_argument("Invalid driving license number!");

        } catch (const invalid_argument& e) {
            cerr << e.what() << endl;
            cin.clear();//cin.clear() resets the error state flags of the input stream. This allows you
            // to continue using the cin object after an error without having to close or reopen the input stream.
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Correct usage of numeric_limits
            throw;  // Rethrow to handle further
        }
    }

    void dispStudData() const {
        cout << "Contact Address: " << caddress << endl;
        cout << "Telephone Number: " << telno << endl;
        cout << "Driving License Number: " << dlno << endl;
    }
};

// Static member initialization
int Student::count = 0;

// Copy Constructor Implementation
Student::Student(const Student& other)
    : name(other.name), roll_no(other.roll_no), cls(other.cls), division(other.division), dob(other.dob), bloodgroup(other.bloodgroup) {
    if (other.studData) {
        studData = new StudData(*other.studData);  // Deep copy
    } else {
        studData = nullptr;
    }
    count++;
}

// Destructor Implementation
Student::~Student() {
    delete studData;  // Free dynamically allocated memory
    count--;
}

// Inline function to get student data
inline void Student::getData() {
    try {
        studData = new StudData();  // Dynamically allocate memory

        cout << "Enter Student Name: ";
        cin >> ws;  // Ignore leading whitespace
        getline(cin, name);

        cout << "Enter Roll Number: ";
        if (!(cin >> roll_no) || roll_no <= 0) throw invalid_argument("Invalid roll number!");

        cout << "Enter Class: ";
        cin >> cls;

        cout << "Enter Division: ";
        cin >> division;

        cout << "Enter Date of Birth (dd/mm/yyyy): ";
        cin >> dob;

        cout << "Enter Blood Group: ";
        cin >> bloodgroup;

        studData->getStudData();

    } catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
        delete studData;  // Clean up on failure
        studData = nullptr;
        throw;  // Rethrow to indicate failure
    }
}

// Inline function to display student data
inline void Student::dispData() const {
    cout << "Student Name: " << this->name << endl;
    cout << "Roll Number: " << this->roll_no << endl;
    cout << "Class: " << this->cls << endl;
    cout << "Division: " << this->division << endl;
    cout << "Date of Birth: " << this->dob << endl;
    cout << "Blood Group: " << this->bloodgroup << endl;
    if (studData) {
        studData->dispStudData();
    }
}

int main() {
    vector<Student*> students;
    char ch;

    do {
        try {
            auto student = new Student();
            student->getData();
            students.push_back(student);

            cout << "Do you want to add another student (y/n): ";
            cin >> ch;

        } catch (const exception&) {
            cout << "Error occurred during data entry. Please try again." << endl;
        }

    } while (ch == 'y' || ch == 'Y');

    for (size_t i = 0; i < students.size(); i++) {
        cout << "---------------------------------------------------------------" << endl;
        students[i]->dispData();  // Display data once
    }

    cout << "---------------------------------------------------------------" << endl;
    cout << "Total Students: " << Student::getCount() << endl;

    // Clean up
    for (auto student : students) {
        delete student;
    }

    return 0;
}
