#include <iostream>
using namespace std;

int main() {
	
    int number, factorial, temp;
    
    cout << "Welcome to the Academic Excellence Awards Ceremony Calculator! \n\n"
         << "Enter the number of students receiving the awards: ";
    cin >> number;

    int problems[100];
    cout << endl;

    for (int i = 0; i < number; i++) {
        cout << "Student " << i + 1 << " How many problems did they solve correctly? ";
        cin >> problems[i];
    }

    cout << "\nHere are the factorial values corresponding to each student's score:\n";
    
    for (int i = 0; i < number; i++) {
        factorial = 1; 
        temp = problems[i];
        for (int j = temp; j > 0; j--) {
            factorial *= j;
        }
        cout << "Student " << i + 1 << ": " << problems[i] << "! = " << factorial << endl;
    }
}