//
// Created by Naveed on 02/10/2025.
// Implementing queue using simple delivery system

#include <iostream>
#include <queue>
using namespace std;

void enQueue(queue<int>& q, int value)
{
    q.push(value);
}

void display_queue(queue<int> q)
{
    cout << "Packages: ";
    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }
}

void deQueue(queue<int> q)
{
    q.pop();
}


int main()
{
    queue<int> delivery;

    //entering packages
    enQueue(delivery, 10);
    enQueue(delivery, 7);
    enQueue(delivery, 4);
    enQueue(delivery, 8);
    enQueue(delivery, 2);
    enQueue(delivery, 15);

    cout << "Original Queue: \n";
    display_queue(delivery);

    enQueue(delivery, 25);
    deQueue(delivery);
    deQueue(delivery);

    cout << endl << endl << "After deleting 2 elements: " << endl;

    display_queue(delivery);
}
