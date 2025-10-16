//
// Created by Naveed on 04/09/2025.
//
/* Objective
Exercise 4: Library books record
XYZ Library maintains a digital record of the books in their collection. Each book's title is stored in a list to keep track of their current order. The library recently decided to reverse the order of the books in their records to reflect the latest arrangement on their website. Write a C++ program and perform following task:
a.	Insert a book in the list
b.	Calculate total number of books the collection.
c.	Reverse the order of the books.
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<string> books;
    int choice;
    string title;

    do {
        cout << "\n1. Insert a book\n2. Show total number of books\n3. Reverse order of books\n4. Display books\n0. Exit\nEnter choice: ";
        cin >> choice;
        cin.ignore();

        if (choice == 1) {
            cout << "Enter book title: ";
            getline(cin, title);
            books.push_back(title);
            cout << "Book inserted.\n";
        } else if (choice == 2) {
            cout << "Total number of books: " << books.size() << endl;
        } else if (choice == 3) {
            reverse(books.begin(), books.end());
            cout << "Order of books reversed.\n";
        } else if (choice == 4) {
            cout << "Books in collection:\n";
            for (const auto& b : books) cout << b << endl;
        }
    } while (choice != 0);
}
