//
// Created by Naveed on 27/09/2025.
//
#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main()
{
    stack<string> edits;
    const int MAX_EDITS = 10;
    int choice;

    do
    {
        cout << "\n1. Apply edit\n2. Undo edit\n3. Show current image state\n4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1)
        {
            if (edits.size() < MAX_EDITS)
            {
                string edit;
                cout << "Enter edit description (e.g., 'apply filter', 'crop image'): ";
                cin.ignore();
                getline(cin, edit);
                edits.push(edit);
                cout << "Applied edit: " << edit << endl;
            }
            else
            {
                cout << "Maximum edits reached! Cannot apply more.\n";
            }
        }
        else if (choice == 2)
        {
            if (!edits.empty())
            {
                cout << "Undoing edit: " << edits.top() << endl;
                edits.pop();
            }
            else
            {
                cout << "No edits to undo.\n";
            }
        }
        else if (choice == 3)
        {
            if (!edits.empty())
            {
                cout << "Current image state after last edit: " << edits.top() << endl;
            }
            else
            {
                cout << "No edits applied yet.\n";
            }
        }
        else if (choice == 4)
        {
            cout << "Exiting...\n";
        }
        else
        {
            cout << "Invalid choice! Try again.\n";
        }
    }
    while (choice != 4);
}
