#include <iostream>
using namespace std;

int main() {
    int balance = 5000;

    cout << "Initial Balance: Rs. " << balance << endl;
    
    balance -= 2000;
    cout << "After withdrawing Rs. 2000, Balance: Rs. " << balance << endl;

    balance += 10000;
    cout << "After depositing Rs. 10000, Balance: Rs. " << balance << endl;

    return 0;
}
