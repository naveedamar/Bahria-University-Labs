//
// Created by Naveed on 21/09/2025.
//

#include <iostream>
using namespace std;

void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int main() {
    int notes[] = {200, 20, 500, 50, 10, 1000, 100};
    int n = 6;

    cout << "Initial Stack: ";
    for (int i = 0; i < n; i++) {
        cout << "$" << notes[i] << " ";
    }
    cout << endl;

    insertionSort(notes, n);

    cout << "Final Sorted Stack: ";
    for (int i = 0; i < n; i++) {
        cout << "$" << notes[i] << " ";
    }
    cout << endl;

    return 0;
}
