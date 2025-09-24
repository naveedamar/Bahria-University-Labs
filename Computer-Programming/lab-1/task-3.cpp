#include <iostream>
#include <string>

using namespace std;

int main() {
    string studentName = "Ali Raza";
    int rollNumber = 101;
    string className = "10th Grade";

    double mathMarks = 85.5;
    double scienceMarks = 78.0;
    double englishMarks = 92.5;

    double totalMarks = mathMarks + scienceMarks + englishMarks;
    double percentage = (totalMarks / 300.0) * 100.0;

    cout << "\n\n--- Student Report Card ---" << endl;
    cout << "---------------------------" << endl;
    cout << "Name: " << studentName << endl;
    cout << "Roll Number: " << rollNumber << endl;
    cout << "Class: " << className << endl;
    cout << "---------------------------" << endl;

    cout << "Subject   Marks" << endl;
    cout << "Math      " << mathMarks << endl;
    cout << "Science   " << scienceMarks << endl;
    cout << "English   " << englishMarks << endl;
    cout << "---------------------------" << endl;

    cout << "Total Marks: " << totalMarks << endl;
    cout << "Percentage:  " << percentage << "%" << endl;
    cout << "---------------------------" << endl;

}