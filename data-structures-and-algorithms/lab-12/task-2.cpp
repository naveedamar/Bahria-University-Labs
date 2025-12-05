//
// Created by Naveed on 04/12/2025.
//

/*Exercise 2: Character codes
Suppose that the following character codes are used: 'A' =1, 'B' =2, ... ,'Y' =25, 'Z' = 26.
Using a hash table with eleven locations and the hashing function h(identifier) = average % 11, where average is the average of the codes
of the first and last letters in identifier, show the hash table that results when the following identifiers are inserted in the order
given, assuming that collisions are resolved using linear probing: BETA, RATE, FREQ, ALPHA, MEAN, SUM, NUM, BAR,WAGE, PAY, KAPPA.

Write a program for the above problem.
 */

#include <iostream>
#include <string>

using namespace std;

const int TABLE_SIZE = 11;

class HashTable
{
private:
    string* table;
    int tableSize;

    int hashFunction(string key)
    {
        if (key.length() == 0)
        {
            return 0;
        }
        int firstCharCode = key[0] - 'A' + 1;
        int lastCharCode = key[key.length() - 1] - 'A' + 1;
        int average = (firstCharCode + lastCharCode) / 2;
        return average % tableSize;
    }

public:
    HashTable(int size)
    {
        tableSize = size;
        table = new string[tableSize];
        for (int i = 0; i < tableSize; i++)
        {
            table[i] = ""; // Use empty string to indicate an empty slot
        }
    }

    ~HashTable()
    {
        delete[] table;
    }

    void Put(string key)
    {
        int hash = hashFunction(key);
        int i = 0;
        while (i < tableSize)
        {
            int index = (hash + i) % tableSize;
            if (table[index] == "")
            {
                table[index] = key;
                cout << "Inserted '" << key << "' at index " << index << endl;
                return;
            }
            i++;
        }
        cout << "Error: Hash table is full. Could not insert '" << key << "'." << endl;
    }

    void PrintTable()
    {
        cout << "\n--- Final Hash Table State ---" << endl;
        for (int i = 0; i < tableSize; i++)
        {
            cout << "Index " << i << ": ";
            if (table[i] == "")
            {
                cout << "[EMPTY]";
            }
            else
            {
                cout << "'" << table[i] << "'";
            }
            cout << endl;
        }
        cout << "------------------------------\n" << endl;
    }
};

int main()
{
    HashTable identifiers(TABLE_SIZE);

    string keys[] = {
        "BETA", "RATE", "FREQ", "ALPHA", "MEAN", "SUM", "NUM", "BAR", "WAGE", "PAY", "KAPPA"
    };

    cout << "--- Inserting Identifiers ---" << endl;
    for (const string& key : keys)
    {
        identifiers.Put(key);
    }

    identifiers.PrintTable();
}
