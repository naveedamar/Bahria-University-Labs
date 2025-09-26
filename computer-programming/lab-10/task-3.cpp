#include <iostream>
#include <string>
using namespace std;

int main() {
	
    string part1, part2, part3, part4, fullMessage;

    cout << "Enter the first part of the response: ";
    getline(cin, part1);

    cout << "Enter the second part of the response: ";
    getline(cin, part2);

    cout << "Enter the third part of the response: ";
    getline(cin, part3);

    cout << "Enter the fourth part of the response: ";
    getline(cin, part4);

    fullMessage = part1 + " " + part2 + " " + part3 + " " + part4;

    cout << "\nThe complete response is:\n";
    cout << "\"" << fullMessage << "\"" << endl;
}