#include <iostream>
using namespace std;

struct Book {
    string title;
    string author;
    int publicationYear;
};

int main() {
    const int SIZE = 3;
    Book books[SIZE];

    cout << "Enter details for " << SIZE << " books:\n";
    for (int i = 0; i < SIZE; i++) {
        cout << "\nBook " << (i + 1) << ":\n";
        cout << "Title: ";
        getline(cin, books[i].title);
        cout << "Author: ";
        getline(cin, books[i].author);
        cout << "Publication Year: ";
        cin >> books[i].publicationYear;
        cin.ignore();
    }

    string search;
    cout << "\nSearch book by title or author: ";
    getline(cin, search);

    cout << "\nSearch Results:\n";
    bool found = false;
    for (int i = 0; i < SIZE; i++) {
        if (books[i].title == search || books[i].author == search) {
            cout << "Title: " << books[i].title << endl;
            cout << "Author: " << books[i].author << endl;
            cout << "Year: " << books[i].publicationYear << endl << endl;
            found = true;
        }
    }

    if (!found) {
        cout << "No matching book found.\n";
    }
}
