//
// Created by Naveed on 10/12/2025
//
/* Single Flight Reservation System (Simple Version)

In this version, the airline operates only one flight. Passenger information is stored in an **alphabetized linked list**.

Menu Options
- Reserve a ticket
- Cancel a reservation
- Check if a ticket is reserved for a specific person
- Display all passengers
*/

#include <iostream>
#include <string>

using namespace std;

struct Passenger
{
    string name;
    Passenger* next;
};

Passenger* head = NULL;

void reserveTicket(string name)
{
    if (name.empty())
    {
        cout << "Error: Name cannot be empty." << endl;
        return;
    }

    Passenger* newNode = new Passenger{name, NULL};

    // Case 1: List is empty or new name is alphabetically smaller than head
    if (!head || name < head->name)
    {
        newNode->next = head;
        head = newNode;
        cout << "Ticket Reserved for " << name << endl;
        return;
    }

    // Case 2: Find the correct position in the sorted list
    Passenger* temp = head;
    while (temp->next && temp->next->name < name)
        temp = temp->next;

    newNode->next = temp->next;
    temp->next = newNode;
    cout << "Ticket Reserved for " << name << endl;
}

void cancelTicket(string name)
{
    if (!head)
    {
        cout << "No reservation found for " << name << endl;
        return;
    }

    // Case 1: The passenger to cancel is at the head
    if (head->name == name)
    {
        Passenger* del = head;
        head = head->next;
        delete del;
        cout << "Reservation for " << name << " Cancelled" << endl;
        return;
    }

    // Case 2: Search for the passenger in the rest of the list
    Passenger* temp = head;
    while (temp->next && temp->next->name != name)
        temp = temp->next;

    if (temp->next)
    {
        Passenger* del = temp->next;
        temp->next = del->next;
        delete del;
        cout << "Reservation for " << name << " Cancelled" << endl;
    }
    else
    {
        cout << "No reservation found for " << name << endl;
    }
}

bool isReserved(string name)
{
    Passenger* temp = head;
    while (temp)
    {
        if (temp->name == name)
        {
            cout << name << " is Reserved" << endl;
            return true;
        }
        temp = temp->next;
    }
    cout << name << " is Not Reserved" << endl;
    return false;
}

void displayPassengers()
{
    if (!head)
    {
        cout << "No passengers reserved." << endl;
        return;
    }
    Passenger* temp = head;
    cout << "Passengers:\n";
    while (temp)
    {
        cout << "- " << temp->name << endl;
        temp = temp->next;
    }
}

int main()
{
    int choice;
    string name;

    do
    {
        cout << "\n--- Single Flight Reservation Menu ---\n";
        cout << "1. Reserve Ticket\n2. Cancel Ticket\n3. Check Reservation\n4. Display Passengers\n5. Exit\n";
        cout << "Enter your choice: ";

        cin >> choice;
        cin.ignore(); // Simple ignore to consume the newline character

        if (choice == 1)
        {
            cout << "Enter Name: ";
            getline(cin, name);
            reserveTicket(name);
        }
        else if (choice == 2)
        {
            cout << "Enter Name: ";
            getline(cin, name);
            cancelTicket(name);
        }
        else if (choice == 3)
        {
            cout << "Enter Name: ";
            getline(cin, name);
            isReserved(name);
        }
        else if (choice == 4)
        {
            displayPassengers();
        }
    }
    while (choice != 5);
}
