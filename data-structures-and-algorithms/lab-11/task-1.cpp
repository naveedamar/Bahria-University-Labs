//
// Created by Naveed on 27/11/2025.
//

/*
 Exercise 1: Cricket Player Performance
Develop a program to build a max heap for a collection of cricket players based on their performance ratings to enhance team management by prioritizing high-performing players.
Write a program in C++ and perform the following tasks:
 1.	Insert player names along with their performance ratings.
 2.	Build a max heap to organize players by their performance.
 3.	Display the players in the heap.
 4.	Find the highest-rated player.
 5.	Delete a player from the heap (e.g., when a player is injured or dropped from the team).
*/
#include <iostream>
using namespace std;

struct Player {
    string name;
    int rating;
};

class MaxHeap {
public:
    Player heap[100];
    int size;

    MaxHeap() {
        size = 0;
    }

    void insertPlayer(string name, int rating) {
        heap[size] = {name, rating};
        siftUp(size);
        size++;
    }

    void buildHeap() {
        for(int i = size / 2 - 1; i >= 0; i--)
            siftDown(i);
    }

    void displayHeap() {
        if(size == 0) {
            cout << "Heap is empty" << endl;
            return;
        }
        for(int i = 0; i < size; i++)
            cout << heap[i].name << " (" << heap[i].rating << ")" << endl;
    }

    Player getMax() {
        if(size == 0) return {"", -1};
        return heap[0];
    }

    void deletePlayer() {
        if(size == 0) {
            cout << "Heap is empty" << endl;
            return;
        }
        heap[0] = heap[size - 1];
        size--;
        siftDown(0);
    }

private:
    void siftUp(int i) {
        while(i > 0) {
            int parent = (i - 1) / 2;
            if(heap[i].rating > heap[parent].rating) {
                Player temp = heap[i];
                heap[i] = heap[parent];
                heap[parent] = temp;
                i = parent;
            } else break;
        }
    }

    void siftDown(int i) {
        while(true) {
            int left = 2 * i + 1;
            int right = 2 * i + 2;
            int largest = i;

            if(left < size && heap[left].rating > heap[largest].rating)
                largest = left;
            if(right < size && heap[right].rating > heap[largest].rating)
                largest = right;

            if(largest != i) {
                Player temp = heap[i];
                heap[i] = heap[largest];
                heap[largest] = temp;
                i = largest;
            } else break;
        }
    }
};

int main() {
    MaxHeap h;
    int choice;

    while(true) {
        cout << "\n1. Insert Player\n2. Display All Players\n3. Show Highest Rated Player\n4. Delete Highest Rated Player\n5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if(choice == 1) {
            string name;
            int rating;
            cout << "Enter player name: ";
            cin >> name;
            cout << "Enter rating: ";
            cin >> rating;
            h.insertPlayer(name, rating);
        }
        else if(choice == 2) {
            h.displayHeap();
        }
        else if(choice == 3) {
            Player p = h.getMax();
            if(p.rating == -1) cout << "Heap is empty" << endl;
            else cout << "Highest Rated Player: " << p.name << " (" << p.rating << ")" << endl;
        }
        else if(choice == 4) {
            h.deletePlayer();
            cout << "Highest player removed." << endl;
        }
        else if(choice == 5) {
            break;
        }
        else {
            cout << "Invalid choice" << endl;
        }
    }
}
