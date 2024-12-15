#include <iostream>
#include <map>
#include <string>
#include <algorithm>
#include <iomanip> // For fixed-point precision
#include <limits>  // For numeric_limits

using namespace std;

string toLowerCase(const string& str) {
    string result = str;
    transform(result.begin(), result.end(), result.begin(), ::tolower);
    return result;
}

int main() {
    map<string, float> populationMap;

    // Inserting population data (in millions)
    populationMap["Maharashtra"] = 125;
    populationMap["Uttar Pradesh"] = 225;
    populationMap["Bihar"] = 120;
    populationMap["West Bengal"] = 100;
    populationMap["Madhya Pradesh"] = 90;
    populationMap["Tamil Nadu"] = 80;
    populationMap["Rajasthan"] = 78;
    populationMap["Andhra Pradesh"] = 53;
    populationMap["Odisha"] = 47;
    populationMap["Kerala"] = 38;
    populationMap["Telangana"] = 37;
    populationMap["Assam"] = 35;
    populationMap["Jharkhand"] = 38;
    populationMap["Karnataka"] = 68;
    populationMap["Gujarat"] = 70;
    populationMap["Punjab"] = 31;
    populationMap["Chhattisgarh"] = 30;
    populationMap["Haryana"] = 29;
    populationMap["UT Delhi"] = 19;
    populationMap["UT Jammu and Kashmir"] = 14;
    populationMap["Uttarakhand"] = 12;
    populationMap["Himachal Pradesh"] = 8;
    populationMap["Tripura"] = 4;
    populationMap["Meghalaya"] = 4;
    populationMap["Manipur"] = 3;
    populationMap["Nagaland"] = 2;
    populationMap["Goa"] = 2;
    populationMap["Arunachal Pradesh"] = 2;
    populationMap["Mizoram"] = 1;
    populationMap["Sikkim"] = 1;
    populationMap["UT Lakshadweep"] = 0.0003;
    populationMap["UT Ladakh"] = 0.00006;

    cout << fixed << setprecision(3); // For small population precision
    cout << "Total number of states/UTs: " << populationMap.size() << endl;

    for (auto iter = populationMap.begin(); iter != populationMap.end(); iter++) {
        cout << iter->first << ": " << iter->second << " million" << endl;
    }

    char cont;
    do {
        string state;
        cout << "Enter the State/UT to find population: ";
        cin.ignore();
        getline(cin, state);

        string lowerState = toLowerCase(state);
        bool found = false;

        for (const auto& entry : populationMap) {
            if (toLowerCase(entry.first) == lowerState) {
                cout << entry.first << "'s population is " << entry.second << " million" << endl;
                found = true;
                break;
            }
        }

        if (!found) {
            cout << "State/UT not found in the population map." << endl;
        }

        cout << "Do you want to search for another state? (y/n): ";
        cin >> cont;
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear input buffer

    } while (cont == 'y' || cont == 'Y');

    return 0;
}
