//
// Created by Naveed on 16/10/2025.
//

/*
 *Exercise 2 : System files Sorting
You are a software engineer working for a large multinational corporation.
As part of a project to optimize file management systems, you've been assigned the task of implementing quick sort
algorithm to organize files within the company's vast networked storage system in alphabetical order.
The goal is to improve access times and streamline file retrieval processes for employees across different departments
and locations.
 */

#include <iostream>
#include <cstring>
using namespace std;

int partition(char arr[][30], int low, int high) {
    char pivot[30];
    strcpy(pivot, arr[high]);
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (strcmp(arr[j], pivot) < 0) {
            i++;
            char temp[30];
            strcpy(temp, arr[i]);
            strcpy(arr[i], arr[j]);
            strcpy(arr[j], temp);
        }
    }
    char temp[30];
    strcpy(temp, arr[i + 1]);
    strcpy(arr[i + 1], arr[high]);
    strcpy(arr[high], temp);
    return i + 1;
}

void quickSort(char arr[][30], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    char files[8][30] = {
        "report.docx", "data.csv", "presentation.pptx",
        "notes.txt", "summary.pdf", "image.png",
        "archive.zip", "budget.xlsx"
    };
    int n = 8;

    cout << "Files before sorting:\n";
    for (int i = 0; i < n; i++)
        cout << files[i] << " ";

    cout << endl;
    quickSort(files, 0, n - 1);

    cout << "\nFiles after sorting (alphabetical order):\n";
    for (int i = 0; i < n; i++)
        cout << files[i] << " ";
    cout << endl;
}
