/*Exercise 1: Student records

Write a program to design a system for storing student’s records keyed using last three digits of enrollment numbers and
the size of hash table must be a prime number. Resolve the collision with quadratic probing if occurs.
Your program should have following functions

•	HashTable( ) : This function is used  to create a new hash table.
•	Delete( ): This function is used to delete enrollment number from the hash table.
•	Get( ): This function is used to search enrollment number inside the hash table.
•	Put( ): This function is used  to insert enrollment number inside the hash table.

*Insert at least 25 records.
*/

#include <iostream>
#include <string>
using namespace std;

const int EMPTY = -1;
const int DELETED = -2;

class HashTable
{
private:
    int* table;
    int tableSize;

    int hashFunction(int key)
    {
        return (key % 1000) % tableSize;
    }

public:
    HashTable(int size)
    {
        tableSize = size;
        table = new int[tableSize];
        for (int i = 0; i < tableSize; i++)
        {
            table[i] = EMPTY;
        }
        cout << "Hash table of size " << tableSize << " created." << endl;
    }

    ~HashTable()
    {
        delete[] table;
        cout << "Hash table destroyed." << endl;
    }

    void Put(int enrollmentNumber)
    {
        if (enrollmentNumber <= 0)
        {
            cout << "Error: Invalid enrollment number." << endl;
            return;
        }
        int hash = hashFunction(enrollmentNumber);
        int i = 0;
        while (i < tableSize)
        {
            int index = (hash + i * i) % tableSize;
            if (table[index] == EMPTY || table[index] == DELETED)
            {
                table[index] = enrollmentNumber;
                cout << "Inserted " << enrollmentNumber << " at index " << index << endl;
                return;
            }
            i++;
        }
        cout << "Error: Hash table is full. Could not insert " << enrollmentNumber << "." << endl;
    }

    int Get(int enrollmentNumber)
    {
        int hash = hashFunction(enrollmentNumber);
        int i = 0;
        while (i < tableSize)
        {
            int index = (hash + i * i) % tableSize;
            if (table[index] == EMPTY)
            {
                return -1;
            }
            if (table[index] == enrollmentNumber)
            {
                return index;
            }
            i++;
        }
        return -1;
    }

    void Delete(int enrollmentNumber)
    {
        int index = Get(enrollmentNumber);
        if (index != -1)
        {
            table[index] = DELETED;
            cout << "Deleted " << enrollmentNumber << " from index " << index << endl;
        }
        else
        {
            cout << "Error: " << enrollmentNumber << " not found for deletion." << endl;
        }
    }

    void PrintTable()
    {
        cout << "\n--- Hash Table Contents ---" << endl;
        for (int i = 0; i < tableSize; i++)
        {
            cout << "Index " << i << ": ";
            if (table[i] == EMPTY)
            {
                cout << "[EMPTY]";
            }
            else if (table[i] == DELETED)
            {
                cout << "[DELETED]";
            }
            else
            {
                cout << table[i];
            }
            cout << endl;
        }
        cout << "---------------------------\n" << endl;
    }
};

int main()
{
    HashTable studentRecords(29);

    int enrollments[] = {
        1001, 2002, 3003, 1004, 2005, 5001, 6002, 7003, 8004, 9005,
        1101, 1202, 1303, 1404, 1505, 2101, 2202, 2303, 2404, 2505,
        3111, 4112, 5113, 6114, 7115, 8111, 9112
    };

    cout << "\n--- Inserting Records ---" << endl;
    for (int enrollment : enrollments)
    {
        studentRecords.Put(enrollment);
    }

    studentRecords.PrintTable();

    cout << "\n--- Searching for Records ---" << endl;
    int searchKey = 2005;
    int result = studentRecords.Get(searchKey);
    if (result != -1)
    {
        cout << "Found " << searchKey << " at index " << result << "." << endl;
    }
    else
    {
        cout << searchKey << " not found." << endl;
    }

    searchKey = 9999;
    result = studentRecords.Get(searchKey);
    if (result != -1)
    {
        cout << "Found " << searchKey << " at index " << result << "." << endl;
    }
    else
    {
        cout << searchKey << " not found." << endl;
    }

    cout << "\n--- Deleting a Record ---" << endl;
    int deleteKey = 1004;
    studentRecords.Delete(deleteKey);

    result = studentRecords.Get(deleteKey);
    if (result != -1)
    {
        cout << "Found " << deleteKey << " at index " << result << "." << endl;
    }
    else
    {
        cout << deleteKey << " not found after deletion." << endl;
    }

    searchKey = 8004;
    result = studentRecords.Get(searchKey);
    if (result != -1)
    {
        cout << "Found " << searchKey << " at index " << result << " after deleting a collided item." << endl;
    }
    else
    {
        cout << searchKey << " not found." << endl;
    }

    studentRecords.PrintTable();
}
