#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

void display(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i];
        if (i < size - 1)
        {
            cout << ", ";
        }
    }
    cout << endl;
}

void bubbleSort(int data[], int size)
{
    int comparisonCount = 0;

    cout << "--UNSORTED ARRAY--" << endl;
    display(data, size);
    cout << endl;

    cout << "--BUBBLE SORT--" << endl;

    for (int pass = 0; pass < size - 1; pass++)
    {
        bool swapped = false;

        for (int j = 0; j < size - 1 - pass; j++)
        {
            comparisonCount++;

            if (data[j] > data[j + 1])
            {
                swap(data[j], data[j + 1]);
                swapped = true;
            }
        }

        cout << pass + 1 << " Pass: ";
        display(data, size);

        if (swapped == false)
        {
            break;
        }
    }

    cout << "\nNumber of comparisons made are: " << comparisonCount << endl;
    cout << "Sorted Array : ";
    display(data, size);
}

void selectionSort(int data[], int size)
{
    int comparisonCount = 0;

    cout << "UNSORTED ARRAY" << endl;
    display(data, size);

    cout << "SELECTION SORT" << endl;
    for (int i = 0; i < size - 1; i++)
    {
        int min_index = i;

        for (int j = i + 1; j < size; j++)
        {
            comparisonCount++;
            if (data[j] < data[min_index])
            {
                min_index = j;
            }
        }

        if (min_index != i)
        {
            swap(data[i], data[min_index]);
        }

        cout << i + 1 << " Pass: ";
        display(data, size);
    }

    cout << "\nNumber of comparisons made are: " << comparisonCount << endl;
    cout << "Sorted Array : ";
    display(data, size);
}

void insertionSort(int data[], int size)
{
    int comparisonCount = 0;

    cout << "UNSORTED ARRAY" << endl;
    display(data, size);

    cout << "INSERTION SORT" << endl;

    for (int i = 1; i < size; i++)
    {
        int key = data[i];
        int j = i - 1;

        while (j >= 0 && data[j] > key)
        {
            comparisonCount++;
            data[j + 1] = data[j];
            j = j - 1;
        }

        // Count the final comparison where the condition fails (j < 0 or data[j] <= key)
        if (j >= 0)
        {
            comparisonCount++;
        }

        data[j + 1] = key;

        cout << i << " Pass: ";
        display(data, size);
    }

    cout << "\nNumber of comparisons made are: " << comparisonCount << endl;
    cout << "Sorted Array : ";
    display(data, size);
}

int main()
{
    int arr[] = {450, 320, 550, 290, 400, 610, 370, 480, 540, 300};
    int n = sizeof(arr) / sizeof(arr[0]);

    int arrBubble[] = {450, 320, 550, 290, 400, 610, 370, 480, 540, 300};
    bubbleSort(arrBubble, n);

    cout << endl;

    int arrSelect[] = {450, 320, 550, 290, 400, 610, 370, 480, 540, 300};
    selectionSort(arrSelect, n);

    cout << endl;

    int arrInsert[] = {450, 320, 550, 290, 400, 610, 370, 480, 540, 300};
    insertionSort(arrInsert, n);
}
