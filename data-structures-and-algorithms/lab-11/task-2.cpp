//
// Created by Naveed on 27/11/2025.
//

/*Exercise 2: Prioritizing Recipes by Cooking Time
Develop a program to manage a collection of recipes based on their cooking times using a min heap and heap sort.
The program should allow the insertion of recipes along with their cooking times, build a min heap to organize the recipes
with the shortest cooking time at the root, and display the recipes in the heap.
Additionally, the program should perform heap sort to sort the recipes in increasing order of their cooking times.
The program should also be able to find and display the recipe with the shortest cooking time.
*/

#include <iostream>
using namespace std;

struct Recipe
{
    string name;
    int time;
};

class MinHeap
{
public:
    Recipe heap[100];
    int size;

    MinHeap()
    {
        size = 0;
    }

    void insertRecipe(string name, int time)
    {
        heap[size] = {name, time};
        siftUp(size);
        size++;
    }

    void buildHeap()
    {
        for (int i = size / 2 - 1; i >= 0; i--)
            siftDown(i);
    }

    void displayHeap()
    {
        if (size == 0)
        {
            cout << "Heap is empty" << endl;
            return;
        }
        for (int i = 0; i < size; i++)
            cout << heap[i].name << " (" << heap[i].time << " hours)" << endl;
    }

    Recipe getMinimum()
    {
        if (size == 0) return {"", -1};
        return heap[0];
    }

    void heapSort()
    {
        int originalSize = size;
        Recipe sorted[100];
        int idx = 0;

        while (size > 0)
        {
            sorted[idx++] = heap[0];
            heap[0] = heap[size - 1];
            size--;
            siftDown(0);
        }

        cout << "Recipes sorted by cooking time:" << endl;
        for (int i = 0; i < originalSize; i++)
            cout << sorted[i].name << " (" << sorted[i].time << " min)" << endl;

        size = originalSize;
        buildHeap();
    }

private:
    void siftUp(int i)
    {
        while (i > 0)
        {
            int parent = (i - 1) / 2;
            if (heap[i].time < heap[parent].time)
            {
                Recipe temp = heap[i];
                heap[i] = heap[parent];
                heap[parent] = temp;
                i = parent;
            }
            else break;
        }
    }

    void siftDown(int i)
    {
        while (true)
        {
            int left = 2 * i + 1;
            int right = 2 * i + 2;
            int smallest = i;

            if (left < size && heap[left].time < heap[smallest].time)
                smallest = left;
            if (right < size && heap[right].time < heap[smallest].time)
                smallest = right;

            if (smallest != i)
            {
                Recipe temp = heap[i];
                heap[i] = heap[smallest];
                heap[smallest] = temp;
                i = smallest;
            }
            else break;
        }
    }
};

int main()
{
    MinHeap h;
    int choice;

    while (true)
    {
        cout <<
            "\n1. Insert Recipe\n2. Display Min Heap\n3. Show Shortest Cooking Time\n4. Heap Sort (Ascending)\n5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1)
        {
            string name;
            int time;
            cout << "Enter recipe name: ";
            cin >> name;
            cout << "Enter cooking time: ";
            cin >> time;
            h.insertRecipe(name, time);
        }
        else if (choice == 2)
        {
            h.displayHeap();
        }
        else if (choice == 3)
        {
            Recipe r = h.getMinimum();
            if (r.time == -1)
                cout << "Heap is empty" << endl;
            else
                cout << "Shortest Recipe: " << r.name << " (" << r.time << " min)" << endl;
        }
        else if (choice == 4)
        {
            h.heapSort();
        }
        else if (choice == 5)
        {
            break;
        }
        else
        {
            cout << "Invalid choice" << endl;
        }
    }
}
