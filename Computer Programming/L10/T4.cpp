#include <iostream>
#include <string>
using namespace std;

int main() {
    string input, copied;

    cout << "Please enter a string: ";
    getline(cin, input);

    copied = input;

    cout << "The copied string is: " << copied << endl;

}