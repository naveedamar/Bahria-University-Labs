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
using namespace std;

int main()
{
    int mins_exercise[10] = {12, 8, 17, 25, 5, 19, 6, 4, 21, 3};

    // paris
    cout << "Pairs of users whose exercise minutes sum to 25:\n";
    for (int i = 0; i < 10; i++)
    {
        for (int j = i + 1; j < 10; j++)
        {
            if (mins_exercise[i] + mins_exercise[j] == 25)
            {
                cout << "User " << i << " (" << mins_exercise[i] << ") and User " << j << " (" << mins_exercise[j] <<
                    ")\n";
            }
        }
    }

    // even or odd
    int even_count = 0, odd_count = 0;
    cout << "Even exercise minutes: ";
    for (int i = 0; i < 10; i++)
    {
        if (mins_exercise[i] % 2 == 0)
        {
            cout << mins_exercise[i] << " ";
            even_count++;
        }
    }
    cout << "\nOdd exercise minutes: ";
    for (int i = 0; i < 10; i++)
    {
        if (mins_exercise[i] % 2 != 0)
        {
            cout << mins_exercise[i] << " ";
            odd_count++;
        }
    }
    cout << "\nTotal even: " << even_count << ", Total odd: " << odd_count << endl;

    // max & min
    int max_time = mins_exercise[0], min_time = mins_exercise[0];
    for (int i = 1; i < 10; i++)
    {
        if (mins_exercise[i] > max_time) max_time = mins_exercise[i];
        if (mins_exercise[i] < min_time) min_time = mins_exercise[i];
    }
    cout << "Maximum exercise time: " << max_time << endl;
    cout << "Minimum exercise time: " << min_time << endl;

    // avg
    int sum = 0;
    for (int i = 0; i < 10; i++)
    {
        sum += mins_exercise[i];
    }
    double average = sum / 10.0;
    cout << "Average exercise minutes: " << average << endl;
}
