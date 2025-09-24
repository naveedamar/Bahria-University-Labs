#include <iostream>
using namespace std;

void calculateExpenses(int* expenses, int size, int* total, float* average) {
    *total = 0;
    for (int i = 0; i < size; i++) {
        *total += expenses[i];
    }
    *average = static_cast<float>(*total) / size;
}

int main() {
    int n;
    cout << "Enter number of friends: ";
    cin >> n;

    int expenses[n];
    for (int i = 0; i < n; i++) {
        cout << "Enter amount spent by friend " << i + 1 << ": ";
        cin >> expenses[i];
    }

    int total;
    float average;
    calculateExpenses(expenses, n, &total, &average);

    cout << "Total expenditure: " << total << endl;
    cout << "Average spending per person: " << average << endl;
}