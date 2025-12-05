//
// Created by Naveed on 04/12/2025.
//

/*Exercise 3: Country’s capital
As a software engineer at GeoMap Solutions, you are tasked to design a system that stores country names in a
hash table of size 13 using hash function h(country_name)=country_name.length()%table_size. Write a program and perform following task:

1.	Insert given keys in the hashtable: United States, Brazil, Japan, Germany, Pakistan, Argentina, Australia.
2.	Delete a country from the hastable.
3.	Update a country using its key.
4.	Search for country with respect to its key.
Note: Use linear probing for collision handling if there’s any
*/

#include <iostream>
#include <string>

using namespace std;

const string EMPTY = "";
const string DELETED = "--DELETED--";

class HashTable
{
private:
    string* table;
    int tableSize;

    int hashFunction(string key)
    {
        return key.length() % tableSize;
    }

public:
    HashTable(int size)
    {
        tableSize = size;
        table = new string[tableSize];
        for (int i = 0; i < tableSize; i++)
        {
            table[i] = EMPTY;
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
            int index = (hash + i) % tableSize; // Linear probing
            if (table[index] == EMPTY || table[index] == DELETED)
            {
                table[index] = key;
                cout << "Inserted '" << key << "' at index " << index << endl;
                return;
            }
            i++;
        }
        cout << "Error: Hash table is full. Could not insert '" << key << "'." << endl;
    }

    int Get(string key)
    {
        int hash = hashFunction(key);
        int i = 0;
        while (i < tableSize)
        {
            int index = (hash + i) % tableSize;
            if (table[index] == EMPTY)
            {
                return -1;
            }
            if (table[index] == key)
            {
                return index;
            }
            i++;
        }
        return -1;
    }

    void Delete(string key)
    {
        int index = Get(key);
        if (index != -1)
        {
            table[index] = DELETED;
            cout << "Deleted '" << key << "' from index " << index << endl;
        }
        else
        {
            cout << "Error: '" << key << "' not found for deletion." << endl;
        }
    }

    void Update(string oldKey, string newKey)
    {
        int index = Get(oldKey);
        if (index != -1)
        {
            Delete(oldKey);
            Put(newKey);
            cout << "Updated '" << oldKey << "' to '" << newKey << "'." << endl;
        }
        else
        {
            cout << "Error: '" << oldKey << "' not found for update." << endl;
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
                cout << "'" << table[i] << "'";
            }
            cout << endl;
        }
        cout << "---------------------------\n" << endl;
    }
};

int main()
{
    HashTable countryTable(13);


    cout << "--- 1. Inserting Countries ---" << endl;
    countryTable.Put("United States");
    countryTable.Put("Brazil");
    countryTable.Put("Japan");
    countryTable.Put("Germany");
    countryTable.Put("Pakistan");
    countryTable.Put("Argentina");
    countryTable.Put("Australia");

    countryTable.PrintTable();

    cout << "\n--- 4. Searching for a Country ---" << endl;
    string searchKey = "Germany";
    int result = countryTable.Get(searchKey);
    if (result != -1)
    {
        cout << "Found '" << searchKey << "' at index " << result << "." << endl;
    }
    else
    {
        cout << "'" << searchKey << "' not found." << endl;
    }

    searchKey = "India";
    result = countryTable.Get(searchKey);
    if (result != -1)
    {
        cout << "Found '" << searchKey << "' at index " << result << "." << endl;
    }
    else
    {
        cout << "'" << searchKey << "' not found." << endl;
    }

    cout << "\n--- 2. Deleting a Country ---" << endl;
    countryTable.Delete("Japan");
    countryTable.PrintTable();

    cout << "\n--- 3. Updating a Country ---" << endl;
    countryTable.Update("Brazil", "Federative Republic of Brazil");
    countryTable.PrintTable();
}
