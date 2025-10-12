//
// Created by Naveed on 09/10/2025.
//

/*
Problem Statement:
Imagine a city’s transportation system with a circular train route. The train stations are arranged in a circular route, meaning that the first station is connected to the last station to form a loop. The train starts from a station, travels to the next station, and continues in a loop without having to stop at the "end." Design a Circular Train Route System using a Circular Linked List. The system should support the following operations:

1.	Add a new station to the circular route.
2.	Display the entire route of stations.
*/

#include <iostream>
#include <string>
using namespace std;

struct Station {
    string name;
    Station* next;
    Station(const string& n) : name(n), next(nullptr) {}
};

class CircularTrainRoute {
    Station* last;
public:
    CircularTrainRoute() : last(nullptr) {}

    void addStation(const string& stationName) {
        Station* newStation = new Station(stationName);
        if (!last) {
            last = newStation;
            last->next = last;
        } else {
            newStation->next = last->next;
            last->next = newStation;
            last = newStation;
        }
    }

    void displayRoute() const {
        if (!last) {
            cout << "No stations in the route.\n";
            return;
        }
        Station* temp = last->next;
        do {
            cout << temp->name << " -> ";
            temp = temp->next;
        } while (temp != last->next);
        cout << "(back to start)\n";
    }

    ~CircularTrainRoute() {
        if (!last) return;
        Station* temp = last->next;
        last->next = nullptr;
        while (temp) {
            Station* next = temp->next;
            delete temp;
            temp = next;
        }
    }
};

int main() {
    CircularTrainRoute route;
    int choice;
    do {
        cout << "\nCircular Train Route System\n";
        cout << "1. Add Station\n2. Display Route\n3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();
        if (choice == 1) {
            string name;
            cout << "Enter station name: ";
            getline(cin, name);
            route.addStation(name);
            cout << "Station added.\n";
        } else if (choice == 2) {
            cout << "Train Route:\n";
            route.displayRoute();
        }
    } while (choice != 3);
    cout << "Exiting...\n";
}
