//
// Created by Naveed on 03/09/2025.
//

/*
Exercise 1: Delivery Trucks
Imagine you are working as a Computer Scientist for a shipping company that manages a
fleet of delivery trucks. Each truck has a unique ID, and these IDs are stored in an array to
monitor the fleet. Due to regular updates in the fleet, you need to perform several operations
such as inserting new trucks, removing old ones, searching for specific truck IDs, and
traversing the list to display the fleet status. Following list represent the truck IDS:
1005 1023 1030 1044 1056 1067 1078 1001 1129 1115 1180
Write a program in C++ and perform following task:
a. Insert a new truck ID 1011 at position 5
b. Traverse the array.
c. Delete a truck ID located at position 9
 */

#include <iostream>
using namespace std;

int main() {
    int size = 11;
    int truck_id[11] = {1005, 1023, 1030, 1044, 1056, 1067, 1078, 1001, 1129, 1115, 1180};

    cout << "Original IDs: " << endl;
    for (const int i : truck_id) {
        cout << i << " ";
    }
    cout << endl;

    truck_id[4] = 1011;
    cout << endl;
    cout << "After adding 1011 at 5: " << endl;
    for (const int i : truck_id) {
        cout << i << " ";
    }
    cout << endl;
    cout << endl;

    cout << "Deleting at 9: ";
    int to_remove = 8;
    if (to_remove >= 0 && to_remove < size) {
        for (int i = to_remove; i < size - 1; ++i) {
            truck_id[i] = truck_id[i + 1];
        }
        size--;
    }

    cout<< endl;
    for (const int i : truck_id) {
        cout << i << " ";
    }
}