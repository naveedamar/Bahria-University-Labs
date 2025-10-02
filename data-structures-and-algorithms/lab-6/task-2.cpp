//
// Created by Naveed on 02/10/2025.
// Implementing circular queue using string array

#include <iostream>
using namespace std;

// Declaring global variables
const int capacity = 10;
int queue[capacity];
int front = -1, rear = -1;

void add_customers(int value)
{
    if (rear == capacity - 1)
    {
        cout << "Queue is full" << endl;
        return;
    }
    if (front == -1) front = 0; // first element
    queue[++rear] = value;
    cout << "Customer " << value << " added to queue\n";
}

void remove_customer()
{
    if (front == -1 || front > rear)
    {
        cout << "Queue is already empty" << endl;
        return;
    }

    cout << "Removing all customers..." << endl;
    while (front <= rear)
    {
        cout << "Customer " << queue[front] << " removed from queue\n";
        front++;
    }

    front = rear = -1;
    cout << "All customers removed from queue\n";
}


void display_queue()
{
    if (front == -1 || front > rear)
    {
        cout << "Queue is empty" << endl;
        return;
    }
    cout << "Customer Queue: ";
    for (int i = front; i <= rear; i++)
    {
        cout << queue[i] << " ";
    }
    cout << endl;
}

int main()
{
    cout << "--Welcome to Thrilltopia--\n";
    add_customers(101);
    add_customers(102);
    add_customers(103);
    add_customers(104);
    add_customers(105);
    add_customers(106);
    add_customers(107);
    add_customers(108);
    add_customers(109);
    add_customers(110);

    cout << endl;
    display_queue();
    cout << endl;

    cout << "adding another customer: ";
    add_customers(111);

    cout << endl;
    remove_customer();

    cout << "checking queue after removing all customers: ";
    display_queue();
    cout << endl;

    cout << "adding new 111 customer: ";
    add_customers(111);

    cout << endl;
    display_queue();
    cout << endl;
}
