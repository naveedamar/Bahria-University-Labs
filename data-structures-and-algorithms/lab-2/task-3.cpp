//
// Created by Naveed on 17/09/2025.
//
#include <iostream>
#include <string>
using namespace std;

int main() {
    string menu[15] = {
        "Burger", "Cheese Burger", "Zinger Burger", "Fries", "Cheese Fries",
        "Chicken Nuggets", "Hot Wings", "Pizza Slice", "Wrap", "Sandwich",
        "Pepsi", "Coke", "Sprite", "Water", "Coffee"
    };

    string search;
    bool found = false;

    cout << "Welcome to FlavorRush Menu Search!\n";
    cout << "Enter the item you want to search: ";
    getline(cin, search);

    for (int i = 0; i < 15; i++) {
        if (menu[i] == search) {
            cout << "Item found: " << menu[i] << " (Available at all outlets)" << endl;
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Sorry, '" << search << "' is not offered on the menu." << endl;
    }

    return 0;
}
