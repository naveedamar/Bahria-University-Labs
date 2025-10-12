//
// Created by Naveed on 09/10/2025.
//
/*
Problem Statement:
BeanBuzz is a popular coffee shop located in the heart of the city. With a constant stream of customers, managing orders efficiently is essential to keep the business running smoothly. To improve customer service, the management has decided to implement a digital queue system.

Your task is to develop a C++ program that utilizes a singly linked list to manage the queue of customer orders at BeanBuzz. The program should include the following functionalities:

1.	Placing Orders: Customers can place their orders at the counter, and each order will be added to the end of the queue. Implement a function that allows customers to place orders, specifying the type of drink and any customizations.
2.	Serving Orders: Baristas will prepare orders one by one, starting with the order at the front of the queue. Implement a function to serve orders, removing them from the front of the queue as they are completed.
3.	Displaying Queue Status: Provide a feature to display the current queue status, showing the details of orders (such as order number, type of drink, and customizations) in the order they are queued.
4.	Displaying Order Details: Implement an option to display details of a specific order in the queue. This could include information such as the customer's name, order type, customizations, and estimated wait time.
5.	Exit()
*/

#include <iostream>
#include <string>
using namespace std;

struct Order
{
    int orderNumber;
    string customerName;
    string drinkType;
    string customizations;
    Order* next;

    Order(int num, const string& name, const string& drink, const string& custom)
        : orderNumber(num), customerName(name), drinkType(drink), customizations(custom), next(nullptr)
    {
    }
};

class OrderQueue
{
    Order* front;
    Order* rear;
    int nextOrderNumber;

public:
    OrderQueue() : front(nullptr), rear(nullptr), nextOrderNumber(1)
    {
    }

    void placeOrder(const string& name, const string& drink, const string& custom)
    {
        Order* newOrder = new Order(nextOrderNumber++, name, drink, custom);
        if (!rear)
        {
            front = rear = newOrder;
        }
        else
        {
            rear->next = newOrder;
            rear = newOrder;
        }
        cout << "Order placed! Order number: " << newOrder->orderNumber << endl;
    }

    void serveOrder()
    {
        if (!front)
        {
            cout << "No orders to serve.\n";
            return;
        }
        Order* temp = front;
        cout << "Serving order #" << temp->orderNumber << " for " << temp->customerName << endl;
        front = front->next;
        if (!front) rear = nullptr;
        delete temp;
    }

    void displayQueue() const
    {
        if (!front)
        {
            cout << "Queue is empty.\n";
            return;
        }
        cout << "Current queue:\n";
        Order* curr = front;
        while (curr)
        {
            cout << "Order #" << curr->orderNumber << ": " << curr->customerName
                << " - " << curr->drinkType << " (" << curr->customizations << ")\n";
            curr = curr->next;
        }
    }

    void displayOrderDetails(int orderNum) const
    {
        Order* curr = front;
        int position = 1;
        while (curr)
        {
            if (curr->orderNumber == orderNum)
            {
                cout << "Order Details:\n";
                cout << "Order Number: " << curr->orderNumber << "\n";
                cout << "Customer Name: " << curr->customerName << "\n";
                cout << "Drink Type: " << curr->drinkType << "\n";
                cout << "Customizations: " << curr->customizations << "\n";
                cout << "Estimated Wait Time: " << (position - 1) * 2 << " minutes\n";
                return;
            }
            curr = curr->next;
            position++;
        }
        cout << "Order not found.\n";
    }

    ~OrderQueue()
    {
        while (front)
        {
            Order* temp = front;
            front = front->next;
            delete temp;
        }
    }
};

int main()
{
    OrderQueue queue;
    int choice;
    do
    {
        cout << "\nBeanBuzz Digital Queue System\n";
        cout << "1. Place Order\n2. Serve Order\n3. Display Queue Status\n4. Display Order Details\n5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();
        if (choice == 1)
        {
            string name, drink, custom;
            cout << "Enter customer name: ";
            getline(cin, name);
            cout << "Enter drink type: ";
            getline(cin, drink);
            cout << "Enter customizations: ";
            getline(cin, custom);
            queue.placeOrder(name, drink, custom);
        }
        else if (choice == 2)
        {
            queue.serveOrder();
        }
        else if (choice == 3)
        {
            queue.displayQueue();
        }
        else if (choice == 4)
        {
            int orderNum;
            cout << "Enter order number: ";
            cin >> orderNum;
            cin.ignore();
            queue.displayOrderDetails(orderNum);
        }
    }
    while (choice != 5);
    cout << "Exiting...\n";
}
