#include <iostream>
using namespace std;

int main() {
    string name;
    int age;
    char grade;
    float cgpa;

    cout << "Enter Name: ";
    getline(cin, name);

    cout << "Enter Age: ";
    cin >> age;

    cout << "Enter Grade (A/B/C/etc): ";
    cin >> grade;

    cout << "Enter CGPA: ";
    cin >> cgpa;

    cout << "\nStudent Record:\n";
    cout << "Name: " << name << endl;
    cout << "Age: " << age << endl;
    cout << "Grade: " << grade << endl;
    cout << "CGPA: " << cgpa << endl;
}