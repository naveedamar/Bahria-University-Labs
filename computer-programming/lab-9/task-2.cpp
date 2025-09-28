#include <iostream>
using namespace std;

void find_min_max(int arr[], int count) {
    int smallest = arr[0];
    int largest = arr[0];

    for (int i = 1; i < count; i++) {
        if (arr[i] < smallest)
            smallest = arr[i];
        if (arr[i] > largest)
            largest = arr[i];
    }

    cout << "\nResults for " << count << " number(s):" << endl;
    cout << "Smallest: " << smallest << endl;
    cout << "Largest: " << largest << endl;
}

int main() {
    int numbers[4];
    int total;

    cout << "Enter how many numbers you want to compare (2 to 4): ";
    cin >> total;

    if (total < 2 || total > 4) {
        cout << "Error: You must enter between 2 and 4 numbers." << endl;
        return 1;
    }

    for (int i = 0; i < total; i++) {
        cout << "Enter number " << (i + 1) << ": ";
        cin >> numbers[i];
    }

    find_min_max(numbers, total);
}