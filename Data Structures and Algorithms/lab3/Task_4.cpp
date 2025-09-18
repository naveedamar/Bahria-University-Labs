//
// Created by Naveed on 18/09/2025.
//

#include <iostream>
using namespace std;

struct product
{
    string name;
    float price, rating;
} p1, p2, p3, p4;

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

void selectionSort(int data[], int size)
{
    int comparisonCount = 0;

    cout << "UNSORTED Prices" << endl;
    display(data, size);

    cout << "Sorting the Price ASC" << endl;
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
    cout << "Sorted Prices: ";
    display(data, size);
}

void ReverseRating(float data[], n)
{
    float max = data[0];
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (max > data[i])
            {
                cout << data[i] << endl;
            }
        }
    }
}

int main()
{
    p1.name = "something";
    p1.price = 1348;
    p1.rating = 20.001;

    p2.name = "something";
    p2.price = 148;
    p2.rating = 2.001;

    p3.name = "something";
    p3.price = 128;
    p3.rating = 4.001;

    int price[3] = {1348, 148, 128};
    float rating[3] = {4.001, 2.001, 20.001};

    selectionSort(price, 3);
    ReverseRating(rating, 3);
}
