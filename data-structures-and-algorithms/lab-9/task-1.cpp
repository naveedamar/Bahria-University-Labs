//
// Created by Naveed on 16/10/2025.
//

/*
Exercise 1: Age Sorter
You are the lead organizer of a prestigious summer camp for young scholars bringing their unique talents and aspirations to create a vibrant and diverse community eager to learn and grow together . As part of the registration process, you've been tasked with sorting a list of students based on their ages, from youngest to oldest using quick and merge sort.
Name  Age	Name	Age	Name	Age
Ali	  14	Zara	18	Rameen	13
Zara  17	Faraz	14	Jamil	12
Hira  15	Danial	16	Asif	17
Saba  19	Namra	11	Sameen	10

Write a program in C++ to sort the age of student by applying quick sort and Merge sort algorithms .
 */

#include <iostream>
#include <cstring>
using namespace std;

struct Student
{
    char name[20];
    int age;
};

int partition(Student arr[], int low, int high)
{
    int pivot = arr[high].age;
    int i = low - 1;
    for (int j = low; j < high; j++)
    {
        if (arr[j].age < pivot)
        {
            i++;
            Student temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    Student temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    return i + 1;
}

void quickSort(Student arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void merge(Student arr[], int l, int m, int r)
{
    int n1 = m - l + 1;
    int n2 = r - m;
    Student L[20], R[20];
    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2)
    {
        if (L[i].age <= R[j].age)
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }
    while (i < n1)
        arr[k++] = L[i++];
    while (j < n2)
        arr[k++] = R[j++];
}

void mergeSort(Student arr[], int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

void display(Student arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i].name << " (" << arr[i].age << ")\n";
}

int main()
{
    Student students[12] = {
        {"Ali", 14}, {"Zara", 18}, {"Rameen", 13},
        {"Zara", 17}, {"Faraz", 14}, {"Jamil", 12},
        {"Hira", 15}, {"Danial", 16}, {"Asif", 17},
        {"Saba", 19}, {"Namra", 11}, {"Sameen", 10}
    };
    const int n = 12;

    // Quick Sort
    Student quickSorted[12];
    memcpy(quickSorted, students, sizeof(students));
    quickSort(quickSorted, 0, n - 1);
    cout << "Students sorted by age (Quick Sort):\n";
    display(quickSorted, n);

    // Merge Sort
    Student mergeSorted[12];
    memcpy(mergeSorted, students, sizeof(students));
    mergeSort(mergeSorted, 0, n - 1);
    cout << "\nStudents sorted by age (Merge Sort):\n";
    display(mergeSorted, n);
}
