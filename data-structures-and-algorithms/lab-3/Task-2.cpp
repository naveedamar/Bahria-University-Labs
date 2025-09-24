//
// Created by Naveed on 21/09/2025.
//

#include <iostream>
#include <string>
using namespace std;

void bubbleSort(string files[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (files[j] > files[j + 1]) {
                string temp = files[j];
                files[j] = files[j + 1];
                files[j + 1] = temp;
            }
        }
    }
}

int main() {
    string files[] = {"Banana", "Zebra", "Apple", "Monkey", "Orange"};
    int n = 5;

    cout << "Files before sorting:\n";
    for (int i = 0; i < n; i++) {
        cout << files[i] << endl;
    }

    bubbleSort(files, n);

    cout << "\nFiles sorted by name in ascending order:\n";
    for (int i = 0; i < n; i++) {
        cout << files[i] << endl;
    }

    return 0;
}
