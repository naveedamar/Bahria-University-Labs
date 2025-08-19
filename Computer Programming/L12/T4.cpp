#include <iostream>
using namespace std;

void findTallest(int* heights, int size) {
    int tallest = *heights;
    int index = 0;

    for (int i = 1; i < size; i++) {
        if (*(heights + i) > tallest) {
            tallest = *(heights + i);
            index = i;
        }
    }

    cout << "Tallest person is at index " << index << " with a height of " << tallest << " cm.";
}

int main() {
    int heights[10];

    cout << "Enter heights of 10 individuals:\n";
    for (int i = 0; i < 10; i++) {
        cin >> heights[i];
    }

	cout << endl;
    findTallest(heights, 10);

    return 0;
}
