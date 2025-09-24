#include <iostream>
using namespace std;

struct Product {
    string name;
    float price;
    float rating;
};

// Function to display products
void display(Product arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i].name << " | Price: " << arr[i].price << " | Rating: " << arr[i].rating << endl;
    }
    cout << "----------------------------------" << endl;
}

// Selection Sort by Price (Ascending)
void sortByPrice(Product arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j].price < arr[minIndex].price) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            swap(arr[i], arr[minIndex]);
        }
    }
}

// Selection Sort by Rating (Descending)
void sortByRating(Product arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int maxIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j].rating > arr[maxIndex].rating) {
                maxIndex = j;
            }
        }
        if (maxIndex != i) {
            swap(arr[i], arr[maxIndex]);
        }
    }
}

int main() {
    Product products[3] = {
        {"Burger", 1348, 20.001},
        {"Fries", 148, 2.001},
        {"Drink", 128, 4.001}
    };

    cout << "Original List:" << endl;
    display(products, 3);

    cout << "Sorted by Price (Ascending):" << endl;
    sortByPrice(products, 3);
    display(products, 3);

    cout << "Sorted by Rating (Descending):" << endl;
    sortByRating(products, 3);
    display(products, 3);

    return 0;
}