#include <iostream>
using namespace std;

int main() {
    string service;
    int quantity;
    double fee, total, tax, finalAmount;

    cout << "Enter service description (e.g., MRI,CT scan, blood test, X-ray): ";
    getline(cin, service);

    cout << "Enter quantity (for services like blood tests or X-rays): ";
    cin >> quantity;

    cout << "Enter service fee per unit: ";
    cin >> fee;

    total = quantity * fee;
    tax = total * 0.05;
    finalAmount = total + tax;

    cout << "\nReceipt\n";
    cout << "Service: " << service << endl;
    cout << "Quantity: " << quantity << endl;
    cout << "Service Fee per Unit: Rs. " << fee << endl;
    cout << "Total Cost: Rs. " << total << endl;
    cout << "Tax (5%): Rs. " << tax << endl;
    cout << "Final Amount: Rs. " << finalAmount << endl;
}
