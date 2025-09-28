#include <iostream>
using namespace std;

void find_min_max(float arr[]) {
    float largest = 0.0;

    for (int i = 1; i < 3; i++) {
        if (arr[i] > largest)
            largest = arr[i];
    }

    cout << "Largest Reading is " << largest << endl;
}

int main() {
    float numbers[3];

    for (int i = 0; i < 3; i++) {
        cout << "Enter Reading " << (i + 1) << ": ";
        cin >> numbers[i];
    }

    find_min_max(numbers);
}