//
// Created by Naveed on 04/09/2025.
//

/*
Exercise 2: Employee Record
At XYZ company, the administration maintains detailed records for all employees,
including their joining years. As part of this record-keeping process, they store the joining
year of each employee in an array. Following array represents the joining years of the 15
employees. Write a program in C++ to do the following task
{2005, 2010, 2015, 2000, 1995, 1998, 2001, 2000, 2002, 1994, 2019, 2016, 2017, 1992, 2020}
a. Display the years spent in the company of all employees (assuming the current year is
2025).
b. Identify and print the position of oldest employee in the company.
c. Identify and print the position of the recent employee in the company.
d. Count and display how many employees have more than 10 years of
experience in the company (assuming the current year is 2025).
 */

#include <algorithm>
#include <iostream>
using namespace std;

int main() {
    int joining_years[15] = {
        2005, 2010, 2015, 2000, 1995, 1998, 2001, 2000, 2002, 1994, 2019, 2016, 2017, 1992, 2020
    };
    int years_spent[15];

    //years spent in company
    cout << "Years spent: ";
    for (int i = 0; i < 15; i++) {
        years_spent[i] = 2025 - joining_years[i];
        cout << years_spent[i] << " ";
    }
    cout << endl;

    //oldest employee
    int oldest_employee = 0;
    cout << "Oldest Employee Position: ";
    for (int i = 0; i < 15; i++) {
        if (years_spent[i] > oldest_employee) {
            oldest_employee = i;
        }
    }
    cout << oldest_employee << endl;

    //newest employee
    int newest_employee = *min_element(years_spent, years_spent + 15);
    cout << "New Employee Position: ";
    for (int i = 0; i < 15; i++) {
        if (newest_employee == years_spent[i]) {
            cout << i;
            break;
        }
    }
    cout << endl;

    //how many have 10 or more years experience
    int counting_years = 0;
    for (int i = 0; i < 15; i++) {
        if (years_spent[i] > 10) {
            counting_years++;
        }
    }
    cout << counting_years << " employee have more than 10 years of experience";
}