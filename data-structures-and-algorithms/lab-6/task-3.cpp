// Created by Naveed on 02/10/2025.
// Implementing circular queue using array

#include <iostream>
using namespace std;

const int capacity = 6;
int queue[capacity];
int front = -1, rear = -1;

bool isFull() {
    return (front == 0 && rear == capacity - 1) || (rear + 1 == front);
}

bool isEmpty() {
    return (front == -1);
}

void add_customers(int value)
{
    if (isFull()) {
        cout << "Queue is full" << endl;
        return;
    }

    if (front == -1) front = 0; // first element
    rear = (rear + 1) % capacity;
    queue[rear] = value;
    cout << "Customer " << value << " added to queue\n";
}

void remove_customer()
{
    if (isEmpty()) {
        cout << "Queue is empty" << endl;
        return;
    }

    cout << "Customer " << queue[front] << " removed from queue\n";

    if (front == rear) {
        front = rear = -1;
    } else {
        front = (front + 1) % capacity;
    }
}

void display_queue()
{
    if (isEmpty()) {
        cout << "Queue is empty" << endl;
        return;
    }

    cout << "Customer Queue: ";
    int i = front;
    while (true) {
        cout << queue[i] << " ";
        if (i == rear) break;
        i = (i + 1) % capacity;
    }
    cout << endl;
}

int main()
{
    cout << "--Welcome to the Movies--\n";
    add_customers(101);
    add_customers(102);
    add_customers(103);
    add_customers(104);
    add_customers(105);
    add_customers(106);

    cout << endl;
    display_queue();
    cout << endl;

    cout << "Adding another customer: ";
    add_customers(111); //full

    cout << endl;
    cout << "Checking queue after removing a customer: ";
    remove_customer();

    display_queue();
    cout << endl;

    cout << "Adding new 111 customer: ";
    add_customers(111);

    cout << endl;
    display_queue();
    cout << endl;
}
