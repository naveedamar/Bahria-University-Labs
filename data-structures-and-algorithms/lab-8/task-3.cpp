//
// Created by Naveed on 12/10/2025.
//

/*Objective:
*Sara is passionate about music and enjoys listening to music during her free time. Over the years, she has amassed a vast collection of music albums comprising her favorite songs.
*Now, she desires to organize her favorite songs into a new playlist named "My Hit Collection". Each song in her playlist is characterized by its Song ID, song name, singer's name, and the year the song was released.
*Your task is to develop a C++ program that helps Sara manage her music playlist using a doubly linked list. The program should incorporate the following functionalities:
1.	.Adding New Songs: Sara should be able to add new songs to her playlist. Each new song will be appended to the end of the playlist.
2.	Playing Playlist: The program should enable Sara to play her playlist in both forward and backward directions, allowing her to enjoy her favorite songs in the sequence they were added or in reverse order.
3.	Circular Playback: Sara should have the option to play her playlist in a circular fashion, ensuring a seamless listening experience without interruption.
4.	.Searching by Year: The program should provide functionality for Sara to search for songs based on the year of release. Upon searching, the program should display all songs released in the specified year.
5.	.Deleting from the Beginning: Sara should be able to remove songs from the beginning of the playlist, enabling her to manage her playlist dynamically.
*Your program should efficiently implement these functionalities to cater to Sara's needs and enhance her music listening experience.
 */

#include <iostream>
#include <string>
using namespace std;

struct Song
{
    int id;
    string name;
    string singer;
    int year;
    Song* next;
    Song* prev;

    Song(int i, const string& n, const string& s, int y)
        : id(i), name(n), singer(s), year(y), next(nullptr), prev(nullptr)
    {
    }
};

void addSong(Song*& head, Song*& tail, int id, const string& name, const string& singer, int year)
{
    Song* song = new Song(id, name, singer, year);
    if (!head)
    {
        head = tail = song;
    }
    else
    {
        tail->next = song;
        song->prev = tail;
        tail = song;
    }
}

void playForward(Song* head)
{
    cout << "Playing playlist forward:\n";
    Song* curr = head;
    while (curr)
    {
        cout << curr->id << ". " << curr->name << " - " << curr->singer << " (" << curr->year << ")\n";
        curr = curr->next;
    }
}

void playBackward(Song* tail)
{
    cout << "Playing playlist backward:\n";
    Song* curr = tail;
    while (curr)
    {
        cout << curr->id << ". " << curr->name << " - " << curr->singer << " (" << curr->year << ")\n";
        curr = curr->prev;
    }
}

void playCircular(Song* head)
{
    if (!head) return;
    cout << "Circular playback (press q to stop):\n";
    Song* curr = head;
    char ch;
    do
    {
        cout << curr->id << ". " << curr->name << " - " << curr->singer << " (" << curr->year << ")\n";
        curr = curr->next ? curr->next : head;
        cout << "Next song? (q to quit, any other key to continue): ";
        cin >> ch;
        cin.ignore();
    }
    while (ch != 'q');
}

void searchByYear(Song* head, int year)
{
    cout << "Songs released in " << year << ":\n";
    Song* curr = head;
    bool found = false;
    while (curr)
    {
        if (curr->year == year)
        {
            cout << curr->id << ". " << curr->name << " - " << curr->singer << endl;
            found = true;
        }
        curr = curr->next;
    }
    if (!found) cout << "No songs found for this year.\n";
}

void deleteFromBeginning(Song*& head, Song*& tail)
{
    if (!head) return;
    Song* temp = head;
    head = head->next;
    if (head) head->prev = nullptr;
    else tail = nullptr;
    delete temp;
    cout << "Song removed from beginning.\n";
}

void deleteAll(Song*& head, Song*& tail)
{
    Song* curr = head;
    while (curr)
    {
        Song* next = curr->next;
        delete curr;
        curr = next;
    }
    head = tail = nullptr;
}

int main()
{
    Song* head = nullptr;
    Song* tail = nullptr;
    int choice;
    do
    {
        cout << "\nMenu:\n";
        cout << "1. Add new song\n";
        cout << "2. Play playlist forward\n";
        cout << "3. Play playlist backward\n";
        cout << "4. Circular playback\n";
        cout << "5. Search songs by year\n";
        cout << "6. Delete song from beginning\n";
        cout << "7. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        cin.ignore();
        if (choice == 1)
        {
            int id, year;
            string name, singer;
            cout << "Enter Song ID: ";
            cin >> id;
            cin.ignore();
            cout << "Enter Song Name: ";
            getline(cin, name);
            cout << "Enter Singer Name: ";
            getline(cin, singer);
            cout << "Enter Year: ";
            cin >> year;
            cin.ignore();
            addSong(head, tail, id, name, singer, year);
        }
        else if (choice == 2)
        {
            playForward(head);
        }
        else if (choice == 3)
        {
            playBackward(tail);
        }
        else if (choice == 4)
        {
            playCircular(head);
        }
        else if (choice == 5)
        {
            int year;
            cout << "Enter year to search: ";
            cin >> year;
            cin.ignore();
            searchByYear(head, year);
        }
        else if (choice == 6)
        {
            deleteFromBeginning(head, tail);
        }
    }
    while (choice != 7);
    deleteAll(head, tail);
}
