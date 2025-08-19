#include <iostream>
#include <fstream>
#include <string>
#include <limits>
using namespace std;

int main() {
    char choice;
    string name;
    string sem_str;
    int roll_no;

    cout << "\t\t---Student Management System---\n";
    cout << "1. Add a new student record\n";
    cout << "2. Search for a student record (by roll no)\n"; 
    cout << "What do you want to do: ";
    cin >> choice;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    switch (choice) {
        case '1': {
            cout << "Enter student name: ";
            getline(cin, name);

            cout << "Enter student rollno: ";
            cin >> roll_no;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            cout << "Enter student semester (e.g., 1 or 'Fall 2024'): ";
            getline(cin, sem_str);

            cout << "\nWriting to file...\n";
            fstream inputfile;
            inputfile.open("student_records.txt", ios::app);

            if (!inputfile.is_open()) {
                cerr << "Error: Could not open file 'student_records.txt' for writing.\n";
                return 1;
            }

            inputfile << roll_no << ", " << name << ", " << sem_str << endl;
            cout << "Wrote to file successfully!\n";
            inputfile.close();
            cout << "File closed.\n";
            break;
        }

        case '2': {
            int roll_to_search;
            cout << "Enter student roll no to search: ";
            cin >> roll_to_search;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            ifstream searchfile;
            searchfile.open("student_records.txt", ios::in);

            cout << "Opening student record file to search for student with roll " << roll_to_search << "!\n";

            if (!searchfile.is_open()) {
                cerr << "Error: Could not open file 'student_records.txt' for searching.\n";
                return 1;
            }

            string tempRollStr;
            string tempName;
            string tempSemStr;
            int currentRoll;
            bool found = false;

            while (getline(searchfile, tempRollStr, ',')) {
                searchfile.ignore();
                getline(searchfile, tempName, ',');
                searchfile.ignore();
                getline(searchfile, tempSemStr);

                try {
                    currentRoll = stoi(tempRollStr);
                } catch (const std::invalid_argument& e) {
                    cerr << "Warning: Malformed roll number found, skipping line.\n";
                    continue;
                } catch (const std::out_of_range& e) {
                    cerr << "Warning: Roll number out of range, skipping line.\n";
                    continue;
                }

                if (currentRoll == roll_to_search) {
                    cout << "\nRecord Found: ";
                    cout << tempRollStr << ", " << tempName << ", " << tempSemStr << endl;
                    found = true;
                    break;
                }
            }

            if (!found) {
                cout << "Student with roll number " << roll_to_search << " not found.\n";
            }
            searchfile.close();
            cout << "File closed.\n";
            break;
        }

        default:
            cout << "Invalid choice. Please select 1 or 2.\n";
            break;
    }
}