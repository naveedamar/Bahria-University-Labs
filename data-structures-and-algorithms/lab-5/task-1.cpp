//
// Created by Naveed on 27/09/2025.
//
#include <iostream>
#include <string>

using namespace std;

constexpr int MAX = 10;
string bills[MAX];
int top = -1;

void addBill(const string& bill)
{
    if (top >= MAX - 1)
    {
        cout << "Stack is full; cannot add more bills.\n";
    }
    else
    {
        top++;
        bills[top] = bill;
        cout << bill << " added to stack.\n";
    }
}

void removeBill()
{
    if (top < 0)
    {
        cout << "Stack is empty; no bills to pay.\n";
    }
    else
    {
        cout << bills[top] << " paid and removed from stack.\n";
        top--;
    }
}

void displayBills()
{
    if (top < 0)
    {
        cout << "Stack is empty.\n";
    }
    else
    {
        cout << "Current bills in stack:\n";
        for (int i = top; i >= 0; i--)
        {
            cout << bills[i] << endl;
        }
    }
}

int main()
{
    addBill("Electricity Bill");
    addBill("Water Bill");
    addBill("Gas Bill");
    addBill("Internet Bill");
    addBill("Phone Bill");
    addBill("Cable Bill");
    addBill("Trash Collection Bill");
    addBill("Insurance Bill");
    addBill("Property Tax Bill");
    addBill("Credit Card Bill");
    addBill("Loan Repayment Bill");
}
