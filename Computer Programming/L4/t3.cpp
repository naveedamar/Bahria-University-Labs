#include <iostream>
using namespace std;

int main() {
    int number[10], sum = 0;
    
    cout << "Please enter 10 integers:\n";
    for (int i = 0; i < 10; i++) {
        cout << "Enter integer " << i + 1 << ": ";
        cin >> number[i];
    }

    for (int i = 0; i < 10; i++) {
        if (number[i] % 2 != 0) {
            sum += number[i];
        }
    }

    cout << "Sum of odd numbers = " << sum;
}