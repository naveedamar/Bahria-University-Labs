//
// Created by Naveed on 04/09/2025.
//
/*
Exercise 3: Fitness tracking app
You are developing a fitness tracking system that records the number of minutes users
exercise daily. These values are stored in an array, representing the daily exercise minutes
for 10 different users over a week. The fitness app needs to perform various analyses on
the exercise data given as follows to provide insights to users and suggest improvements.
12 8 17 25 5 19 6 4 21 3
Write a program in C++ and perform following task:
a. Find All Pairs of Users Whose Exercise Minutes Sum to 25.
b. Count even and odd exercise minutes to create custom workout groups
c. Display maximum and minimum exercise time taken by users
d. Calculate average exercise minutes
 */


#include <iostream>
#include <map>
using namespace std;

int main() {

    int mins_exercise[10] = {12, 8, 17, 25, 5, 19, 6, 4, 21, 3};

    //minutes output
    cout << "Minutes Exercised: ";
    for (int i = 0; i < 10; i++) {
        cout << mins_exercise[i] << ", ";
    }
    cout << endl;


    int pairs[5];
    cout << "Pairs: ";
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (mins_exercise[i] + mins_exercise[j] == 25) {
                for (auto pair : pairs) {
                    continue;
                }
            }
        }
    }
    for (int i = 0; i < 10; i++) {
        cout << pairs[i] << " ";
    }
    cout << endl;

    //even odd
    int even[5], odd[5];
    for (int i = 0; i < 10; i++) {
        if (mins_exercise[i] % 2 == 0) {
            even[i] = mins_exercise[i];
        }else {
            odd[i] = mins_exercise[i];
        }
    }

    cout << "Even: ";
    for (int i = 0; i < 5; i++) {
        cout << even[i] << " ";
    }
    cout << endl;

    cout << "Odd: ";
    for (int i = 0; i < 5; i++) {
        cout << odd[i] << " ";
    }
    cout << endl;
}