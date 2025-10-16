//
// Created by Naveed on 16/10/2025.
//

/*
Exercise 4: E Books sorting App

Bahria University’s E-Library has a vast collection of e-books covering diverse academic disciplines and research areas.
In order to modernize library system they have decided to organize the e-books in the library's digital repository alphabetically
to improve accessibility and streamline the browsing experience for students and faculty members searching for e-books.

*Write a progam that implements above scenario using quick and merge sort. Test your Program on following books

{Design And Analysis of Computer Algorithms, Compilers :Techniques And Tools, Data Structures and Algorithms, Fundamental of Mathematics,
Computer Communications and Networking, Artificial Intelligence, Principles of Compiler Design, Cloud Computing and Software Services,
Visual Basic .Net Programming, Oracle Database 11g : New Features for DBAs and Developers, Online Training : The New Age Training Method,
Applied Calculus and Analytical Geometry}
 */

#include <iostream>
#include <cstring>
using namespace std;

int partition(char arr[][80], int low, int high)
{
    char pivot[80];
    strcpy(pivot, arr[high]);
    int i = low - 1;
    for (int j = low; j < high; j++)
    {
        if (strcmp(arr[j], pivot) < 0)
        {
            i++;
            char temp[80];
            strcpy(temp, arr[i]);
            strcpy(arr[i], arr[j]);
            strcpy(arr[j], temp);
        }
    }
    char temp[80];
    strcpy(temp, arr[i + 1]);
    strcpy(arr[i + 1], arr[high]);
    strcpy(arr[high], temp);
    return i + 1;
}

void quickSort(char arr[][80], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void merge(char arr[][80], int l, int m, int r)
{
    int n1 = m - l + 1, n2 = r - m;
    char L[20][80], R[20][80];
    for (int i = 0; i < n1; i++) strcpy(L[i], arr[l + i]);
    for (int j = 0; j < n2; j++) strcpy(R[j], arr[m + 1 + j]);
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2)
    {
        if (strcmp(L[i], R[j]) <= 0) strcpy(arr[k++], L[i++]);
        else strcpy(arr[k++], R[j++]);
    }
    while (i < n1) strcpy(arr[k++], L[i++]);
    while (j < n2) strcpy(arr[k++], R[j++]);
}

void mergeSort(char arr[][80], int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

void display(char arr[][80], int n)
{
    for (int i = 0; i < n; i ++)
    {
        cout << i + 1 << ". " << arr[i] << endl;
    }
}

int main()
{
    char books[12][80] = {
        "Design And Analysis of Computer Algorithms",
        "Compilers :Techniques And Tools",
        "Data Structures and Algorithms",
        "Fundamental of Mathematics",
        "Computer Communications and Networking",
        "Artificial Intelligence",
        "Principles of Compiler Design",
        "Cloud Computing and Software Services",
        "Visual Basic .Net Programming",
        "Oracle Database 11g : New Features for DBAs and Developers",
        "Online Training : The New Age Training Method",
        "Applied Calculus and Analytical Geometry"
    };
    const int n = 12;

    char quickSorted[12][80];
    memcpy(quickSorted, books, sizeof(books));
    quickSort(quickSorted, 0, n - 1);
    cout << "Books sorted alphabetically (Quick Sort):\n";
    display(quickSorted, n);

    cout << endl;

    char mergeSorted[12][80];
    memcpy(mergeSorted, books, sizeof(books));
    mergeSort(mergeSorted, 0, n - 1);
    cout << "\nBooks sorted alphabetically (Merge Sort):\n";
    display(mergeSorted, n);
}
