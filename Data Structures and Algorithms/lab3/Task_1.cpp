#include <iostream>
using namespace std;

void display(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i];
        if (i < size - 1) cout << ", ";
    }
    cout << endl;
}

void bubbleSort(int arr[], int n) {
    int comparisons = 0;
    cout << "--BUBBLE SORT--" << endl;

    for (int pass = 0; pass < n - 1; pass++) {
        bool swapped = false;
        for (int j = 0; j < n - 1 - pass; j++) {
            comparisons++;
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = true;
            }
        }
        cout << "Pass " << pass + 1 << ": ";
        display(arr, n);
        if (!swapped) break;
    }

    cout << "Comparisons: " << comparisons << endl;
    cout << "Sorted Array: ";
    display(arr, n);
}

void selectionSort(int arr[], int n) {
    int comparisons = 0;
    cout << "--SELECTION SORT--" << endl;

    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            comparisons++;
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            int temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }
        cout << "Pass " << i + 1 << ": ";
        display(arr, n);
    }

    cout << "Comparisons: " << comparisons << endl;
    cout << "Sorted Array: ";
    display(arr, n);
}

void insertionSort(int arr[], int n) {
    int comparisons = 0;
    cout << "--INSERTION SORT--" << endl;

    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            comparisons++;
            arr[j + 1] = arr[j];
            j--;
        }
        if (j >= 0) comparisons++;
        arr[j + 1] = key;

        cout << "Pass " << i << ": ";
        display(arr, n);
    }

    cout << "Comparisons: " << comparisons << endl;
    cout << "Sorted Array: ";
    display(arr, n);
}

int main() {
    int arr[] = {450, 320, 550, 290, 400, 610, 370, 480, 540, 300};
    int n = sizeof(arr) / sizeof(arr[0]);

    int bubbleArr[10], selectArr[10], insertArr[10];
    for (int i = 0; i < n; i++) {
        bubbleArr[i] = selectArr[i] = insertArr[i] = arr[i];
    }

    bubbleSort(bubbleArr, n);
    cout << endl;

    selectionSort(selectArr, n);
    cout << endl;

    insertionSort(insertArr, n);
}
