//
// Created by Naveed on 16/10/2025.
//

/* Exercise 3: Running Speed Sorter
You are coordinating a marathon where participants submit their average running speed
(e.g., 7.2 represents 7 miles and 2 tenths of a mile per hour). To rank the participants fairly,
you need to arrange them based on their speed, from slowest to fastest, using merge sort.

2.4	0.9	0.6	5.1	8.0	2.2	8.6	4.3	6.7	7.9	5.4	3.2	9.5	5.5
 */

#include <iostream>
#include <iomanip>

using namespace std;

void merge(double arr[], int l, int m, int r)
{
    int n1 = m - l + 1;
    int n2 = r - m;
    double* L = new double[n1];
    double* R = new double[n2];

    for (int i = 0; i < n1; ++i) L[i] = arr[l + i];
    for (int j = 0; j < n2; ++j) R[j] = arr[m + 1 + j];

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j]) arr[k++] = L[i++];
        else arr[k++] = R[j++];
    }
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];

    delete[] L;
    delete[] R;
}

void mergeSort(double arr[], int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

int main()
{
    double speeds[] = {2.4, 0.9, 0.6, 5.1, 8.0, 2.2, 8.6, 4.3, 6.7, 7.9, 5.4, 3.2, 9.5, 5.5};
    const int n = sizeof(speeds) / sizeof(speeds[0]);

    cout << "Speeds before sorting (mph):\n";
    cout << fixed << setprecision(1);
    for (int i = 0; i < n; ++i) cout << speeds[i] << (i + 1 < n ? "  " : "\n");

    mergeSort(speeds, 0, n - 1);

    cout << "\nSpeeds after sorting (slowest to fastest):\n";
    for (int i = 0; i < n; ++i) cout << speeds[i] << (i + 1 < n ? "  " : "\n");
}
