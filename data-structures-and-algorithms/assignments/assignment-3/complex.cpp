//
// Created by Naveed on 10/12/2025
//

/* Multiple Flights Reservation System (Full Version)

In this version, the airline can operate multiple flights with no limit.

- Flights are stored in a linked list.
- Each flight node contains a pointer to another linked list of passengers.
- Passenger lists are maintained in alphabetical order.

Menu Options
- Reserve a ticket for a specific flight
- Cancel a reservation
- Check if a passenger is reserved on a flight
- Display passengers of a selected flight
*/

#include <iostream>
#include <string>
using namespace std;

// Node to store passenger information
struct Passenger
{
    string name;
    Passenger* next;
};

// Node to store flight information, including a pointer to a list of passengers
struct Flight
{
    string name;
    Passenger* passengers; // Head of the passenger list for this flight
    Flight* next;
};

// Global head pointer for the list of flights
Flight* flights = NULL;

/**
 * @brief Finds a flight in the global flights list by its name.
 * @param fname The name of the flight to find.
 * @return A pointer to the Flight node if found, otherwise NULL.
 */
Flight* findFlight(string fname)
{
    Flight* temp = flights;
    while (temp != NULL)
    {
        if (temp->name == fname)
            return temp;
        temp = temp->next;
    }
    return NULL; // Return NULL if the flight is not found
}

/**
 * @brief Adds a new flight to the beginning of the global flights list.
 * @param fname The name of the new flight to add.
 */
void addFlight(string fname)
{
    Flight* f = new Flight;
    f->name = fname;
    f->passengers = NULL; // New flights have no passengers initially
    f->next = flights; // Link the new flight to the existing list
    flights = f; // Update the global head to the new flight
    cout << "Flight " << fname << " has been added." << endl;
}

/**
 * @brief Reserves a ticket for a passenger on a specific flight, maintaining alphabetical order.
 * If the flight doesn't exist, it is created.
 * @param fname The name of the flight.
 * @param pname The name of the passenger.
 */
void reserveTicket(string fname, string pname)
{
    Flight* f = findFlight(fname);
    if (f == NULL)
    {
        addFlight(fname);
        f = flights; // The new flight is now at the head of the list
    }

    Passenger* newNode = new Passenger{pname, NULL};

    // Insert the new passenger in alphabetical order within the flight's passenger list.
    // Case 1: The list is empty or the new passenger comes before the current head.
    if (!f->passengers || pname < f->passengers->name)
    {
        newNode->next = f->passengers;
        f->passengers = newNode;
    }
    // Case 2: Find the correct position to insert the new passenger.
    else
    {
        Passenger* temp = f->passengers;
        // Traverse the list to find the node after which the new passenger should be inserted.
        while (temp->next && temp->next->name < pname)
        {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }

    cout << "Ticket reserved for " << pname << " on flight " << fname << "." << endl;
}

/**
 * @brief Cancels a reservation for a passenger on a specific flight.
 * @param fname The name of the flight.
 * @param pname The name of the passenger whose reservation is to be cancelled.
 */
void cancelTicket(string fname, string pname)
{
    Flight* f = findFlight(fname);
    if (f == NULL || f->passengers == NULL)
    {
        cout << "Reservation not found for " << pname << " on flight " << fname << "." << endl;
        return;
    }

    Passenger* temp = f->passengers;

    // Case 1: The passenger to be deleted is the first one in the list.
    if (temp->name == pname)
    {
        f->passengers = temp->next; // Update the head of the passenger list
        delete temp;
        cout << "Reservation for " << pname << " on flight " << fname << " has been cancelled." << endl;
        return;
    }

    // Case 2: Search for the passenger in the rest of the list.
    while (temp->next && temp->next->name != pname)
    {
        temp = temp->next;
    }

    // If the passenger is found, delete their node.
    if (temp->next)
    {
        Passenger* del = temp->next;
        temp->next = del->next; // Unlink the node to be deleted
        delete del;
        cout << "Reservation for " << pname << " on flight " << fname << " has been cancelled." << endl;
    }
    else
    {
        cout << "Reservation not found for " << pname << " on flight " << fname << "." << endl;
    }
}

/**
 * @brief Checks if a passenger has a reservation on a specific flight.
 * @param fname The name of the flight.
 * @param pname The name of the passenger to check.
 * @return True if the passenger is reserved, false otherwise.
 */
bool isReserved(string fname, string pname)
{
    Flight* f = findFlight(fname);
    if (f == NULL)
    {
        cout << "Flight " << fname << " not found." << endl;
        return false;
    }

    // Traverse the passenger list for the given flight.
    Passenger* temp = f->passengers;
    while (temp)
    {
        if (temp->name == pname)
        {
            cout << pname << " IS reserved on flight " << fname << "." << endl;
            return true;
        }
        temp = temp->next;
    }

    cout << pname << " is NOT reserved on flight " << fname << "." << endl;
    return false;
}

/**
 * @brief Displays all passengers for a specific flight.
 * @param fname The name of the flight whose passengers are to be displayed.
 */
void displayPassengers(string fname)
{
    Flight* f = findFlight(fname);
    if (f == NULL || f->passengers == NULL)
    {
        cout << "No passengers found for flight " << fname << "." << endl;
        return;
    }

    // Traverse and print the names of all passengers on the flight.
    Passenger* temp = f->passengers;
    cout << "Passengers on flight " << fname << ":\n";
    while (temp != NULL)
    {
        cout << "- " << temp->name << endl;
        temp = temp->next;
    }
}

/**
 * @brief The main function that drives the program.
 * It displays a menu to the user and handles their choices.
 */
int main()
{
    int choice;
    string flight, passenger;

    // Pre-add some flights for easier testing and demonstration.
    addFlight("PK-301");
    addFlight("BA-249");

    do
    {
        cout << "\n--- Airline Reservation Menu ---\n";
        cout << "1. Reserve Ticket\n2. Cancel Ticket\n3. Check Reservation\n4. Display Flight Passengers\n5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); // To consume the newline character left by cin, preventing issues with getline.

        if (choice == 1)
        {
            cout << "Enter Flight Name: ";
            getline(cin, flight);
            cout << "Enter Passenger Name: ";
            getline(cin, passenger);
            reserveTicket(flight, passenger);
        }
        else if (choice == 2)
        {
            cout << "Enter Flight Name: ";
            getline(cin, flight);
            cout << "Enter Passenger Name: ";
            getline(cin, passenger);
            cancelTicket(flight, passenger);
        }
        else if (choice == 3)
        {
            cout << "Enter Flight Name: ";
            getline(cin, flight);
            cout << "Enter Passenger Name: ";
            getline(cin, passenger);
            isReserved(flight, passenger);
        }
        else if (choice == 4)
        {
            cout << "Enter Flight Name: ";
            getline(cin, flight);
            displayPassengers(flight);
        }
    }
    while (choice != 5);
}
