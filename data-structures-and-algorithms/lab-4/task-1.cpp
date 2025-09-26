#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

void display(string arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i];
        if (i < size - 1) cout << ", ";
    }
    cout << endl;
}

void bubbleSort(string arr[], int n)
{
    int time_comp_outer = 0;
    int time_comp_inner = 0;

    auto start = high_resolution_clock::now();

    for (int pass = 0; pass < n - 1; pass++)
    {
        bool swapped = false;
        time_comp_outer++;
        for (int j = 0; j < n - 1 - pass; j++)
        {
            time_comp_inner++;
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) break;
    }

    auto end = high_resolution_clock::now();

    cout << "\nBooks Sorted" << endl;
    display(arr, n);
    cout << "Number of steps BubbleSort: "
        << (time_comp_inner * time_comp_outer) << " operations" << endl;

    auto duration = duration_cast<microseconds>(end - start).count();
    cout << "Time = " << duration << " microseconds" << endl;
}

void selectionSort(string arr[], int n)
{
    int time_comp_outer = 0;
    int time_comp_inner = 0;

    auto start = high_resolution_clock::now();

    for (int i = 0; i < n - 1; i++)
    {
        time_comp_outer++;
        int minIndex = i;
        for (int j = i + 1; j < n; j++)
        {
            time_comp_inner++;
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }
        if (minIndex != i)
        {
            swap(arr[i], arr[minIndex]);
        }
    }

    auto end = high_resolution_clock::now();

    cout << "Number of steps Selection Sort: "
        << (time_comp_inner * time_comp_outer) << " operations" << endl;

    auto duration = duration_cast<microseconds>(end - start).count();
    cout << "Time = " << duration << " microseconds" << endl;
}

void insertionSort(string arr[], int n)
{
    int time_comp_outer = 0;
    int time_comp_inner = 0;

    auto start = high_resolution_clock::now();

    for (int i = 1; i < n; i++)
    {
        time_comp_outer++;
        string key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            time_comp_inner++;
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }

    auto end = high_resolution_clock::now();

    cout << "Number of steps Insertion Sort: "
        << (time_comp_inner + time_comp_outer) << " operations" << endl;

    auto duration = duration_cast<microseconds>(end - start).count();
    cout << "Time = " << duration << " microseconds" << endl;
}

int main()
{
    string books[22] = {
        "Introduction to the Theory of Computation",
        "Code: The Hidden Language of Computer Hardware and Software",
        "Clean Code: A Handbook of Agile Software Craftsmanship",
        "The Pragmatic Programmer",
        "Structure and Interpretation of Computer Programs",
        "Design Patterns: Elements of Reusable Object-Oriented Software",
        "Algorithms",
        "Compilers: Principles, Techniques, and Tools",
        "Artificial Intelligence: A Modern Approach",
        "Cracking the Coding Interview",
        "The Art of Computer Programming",
        "Operating Systems: Three Easy Pieces",
        "Computer Systems: A Programmer's Perspective",
        "Introduction to Algorithms",
        "The Mythical Man-Month: Essays on Software Engineering",
        "Refactoring: Improving the Design of Existing Code",
        "The C Programming Language",
        "The Elements of Computing Systems",
        "You Don’t Know JS: Scope & Closures",
        "Effective Java",
        "JavaScript: The Good Parts",
        "Programming Pearls"
    };

    int n = 22;

    // Bubble Sort
    bubbleSort(books, n);

    // Selection Sort
    selectionSort(books, n);

    // Insertion Sort
    insertionSort(books, n);
}
