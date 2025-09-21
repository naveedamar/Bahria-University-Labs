//
// Created by Naveed on 21/09/2025.
//
#include <iostream>
#include <string>
using namespace std;

struct Song {
    string title;
    int duration; //secs
};

void insertionSort(Song playlist[], int n) {
    for (int i = 1; i < n; i++) {
        Song key = playlist[i];
        int j = i - 1;

        while (j >= 0 && playlist[j].duration > key.duration) {
            playlist[j + 1] = playlist[j];
            j--;
        }
        playlist[j + 1] = key;
    }
}

int main() {
    Song playlist[] = {
        {"Shape of You", 233},
        {"Blinding Lights", 200},
        {"Bohemian Rhapsody", 354},
        {"Levitating", 203},
        {"Peaches", 198}
    };

    int n = 5;

    cout << "Initial Playlist:\n";
    for (int i = 0; i < n; i++) {
        cout << playlist[i].title << " (" << playlist[i].duration << "s)\n";
    }

    insertionSort(playlist, n);

    cout << "\nSorted Playlist (by duration):\n";
    for (int i = 0; i < n; i++) {
        cout << playlist[i].title << " (" << playlist[i].duration << "s)\n";
    }
}
