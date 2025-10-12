//
// Created by Naveed on 12/10/2025.
//

/*Objective:
 *Design a user-friendly navigation application to assist commuters traveling between their home and Bahria University.
 *The application must utilize a doubly linked list data structure to store the sequence of directions for the route.
 *Users should be able to add new route steps, delete the entire route, and seamlessly navigate between home and university.
 *Clear and concise navigation instructions, including turning directions and approximate distances, must be provided for each route step.
 *Also show the reverse the route to navigate from Bahria University back to the user's home.
 */

#include <iostream>
#include <string>
using namespace std;

struct RouteStep
{
    string instruction;
    double distance;
    RouteStep* next;
    RouteStep* prev;

    RouteStep(const string& instr, double dist)
        : instruction(instr), distance(dist), next(nullptr), prev(nullptr)
    {
    }
};

void addStep(RouteStep*& head, RouteStep*& tail, const string& instr, double dist)
{
    RouteStep* step = new RouteStep(instr, dist);
    if (!head)
    {
        head = tail = step;
    }
    else
    {
        tail->next = step;
        step->prev = tail;
        tail = step;
    }
}

void showRoute(RouteStep* head)
{
    RouteStep* curr = head;
    cout << "Route from Home to University:\n";
    while (curr)
    {
        cout << curr->instruction << " (" << curr->distance << " km)\n";
        curr = curr->next;
    }
}

void showReverseRoute(RouteStep* tail)
{
    RouteStep* curr = tail;
    cout << "Route from University to Home:\n";
    while (curr)
    {
        cout << curr->instruction << " (" << curr->distance << " km)\n";
        curr = curr->prev;
    }
}

void deleteRoute(RouteStep*& head, RouteStep*& tail)
{
    RouteStep* curr = head;
    while (curr)
    {
        RouteStep* next = curr->next;
        delete curr;
        curr = next;
    }
    head = tail = nullptr;
}

int main()
{
    RouteStep* head = nullptr;
    RouteStep* tail = nullptr;
    int choice;

    do
    {
        cout << "\nNavigation Menu:\n";
        cout << "1. Add route step\n";
        cout << "2. Show route (Home to University)\n";
        cout << "3. Show reverse route (University to Home)\n";
        cout << "4. Delete route\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        if (choice == 1)
        {
            string instr;
            double dist;
            cout << "Enter instruction: ";
            getline(cin, instr);
            cout << "Enter distance (km): ";
            cin >> dist;
            cin.ignore();
            addStep(head, tail, instr, dist);
        }
        else if (choice == 2)
        {
            showRoute(head);
        }
        else if (choice == 3)
        {
            showReverseRoute(tail);
        }
        else if (choice == 4)
        {
            deleteRoute(head, tail);
            cout << "Route deleted.\n";
        }
    }
    while (choice != 5);

    deleteRoute(head, tail);
}
