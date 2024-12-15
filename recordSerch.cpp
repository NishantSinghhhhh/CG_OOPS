#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

class Item {
public:
    char name[20];
    int quantity;
    int cost;
    int code;

    bool operator == (const Item& i1) const {
        return code == i1.code;
    }

    bool operator < (const Item& i1) const {
        return code < i1.code;
    }
};

vector<Item> itemList;

void print(const Item& i1);
void display();
void search();
void insert();
void del();
bool compareByCost(const Item& i1, const Item& i2);
bool compareByCode(const Item& i1, const Item& i2);

int main() {
    int ch;
    do {
        cout << "\n ****Menu****" << endl;
        cout << "1.Insert an item" << endl;
        cout << "2.Display the items" << endl;
        cout << "3.Search for an item" << endl;
        cout << "4.Sort by code" << endl;
        cout << "5.Sort by cost" << endl;
        cout << "6.Delete an item" << endl;
        cout << "Enter your choice: " << endl;
        cin >> ch;
        switch (ch) {
            case 1:
                insert();
                break;
            case 2:
                display();
                break;
            case 3:
                search();
                break;
            case 4:
                sort(itemList.begin(), itemList.end(), compareByCode); // Corrected
                cout << "\nSorted by code: " << endl;
                break;
            case 5:
                sort(itemList.begin(), itemList.end(), compareByCost);
                cout << "\nSorted by cost: " << endl;
                break;
            case 6:
                del();
                break;
            case 7:
                return 0;  // Exit the program gracefully
                break;
            default:
                cout << "Enter valid choice!" << endl;
        }
    } while (ch != 7);
    return 0;
}

void insert() {
    Item newItem;
    cout << "\nEnter the name of the item: ";
    cin.ignore();
    cin.getline(newItem.name, 20);
    cout << "Enter the quantity of item: ";
    cin >> newItem.quantity;
    cout << "Enter the cost of item: ";
    cin >> newItem.cost;
    cout << "Enter the code of item: ";
    cin >> newItem.code;
    itemList.push_back(newItem);
    cout << "\nItem added successfully!";
}

void display() {
    if (itemList.empty()) {
        cout << "\nNo items to display.\n";
        return;
    }
    cout << "\nItems in the list: " << endl;
    for_each(itemList.begin(), itemList.end(), print);  // Corrected
}

void print(const Item& item) {
    cout << "\nItem name: " << item.name;
    cout << "\nItem quantity: " << item.quantity;
    cout << "\nItem cost: " << item.cost;
    cout << "\nItem code: " << item.code << endl;
}

void search() {
    int searchCode;
    if (itemList.empty()) {
        cout << "\nList is empty" << endl;
        return;
    }
    cout << "Enter the Item code to search: " << endl;
    cin >> searchCode;
    auto it = find_if(itemList.begin(), itemList.end(), [searchCode](const Item& item) {
        return item.code == searchCode;
    });
    if (it != itemList.end()) {
        cout << "\nItem found!" << endl;
        print(*it);
    }
    else {
        cout << "\nItem not found!" << endl;
    }
}

void del() {
    int deleteCode;
    if (itemList.empty()) {
        cout << "List is empty" << endl;
        return;
    }
    cout << "Enter the code of item to delete: ";
    cin >> deleteCode;
    auto it = find_if(itemList.begin(), itemList.end(), [deleteCode](const Item& item) {
        return item.code == deleteCode;
    });
    if (it != itemList.end()) {
        itemList.erase(it);
        cout << "Item deleted successfully!" << endl;
    }
    else {
        cout << "Item not found" << endl;
    }
}

bool compareByCost(const Item& i1, const Item& i2) {
    return i1.cost < i2.cost;
}

bool compareByCode(const Item& i1, const Item& i2) {
    return i1.code < i2.code;
}
