#include <iostream>
using namespace std;

float area(float radius) {
    return 3.142f * radius * radius;
}

float area(float length, float width) {
    return length * width;
}

float area(float base, float height, bool isTriangle) {
    return 0.5f * base * height;
}

int main() {
    int choice;
    cout << "Select shape to find its area:\n";
    cout << "1. Circle\n";
    cout << "2. Rectangle\n";
    cout << "3. Triangle\n";
    cout << "Your Choice: ";
    cin >> choice;

    if (choice == 1) {
        float radius;
        cout << "Enter radius of the circle: ";
        cin >> radius;
        cout << "Area of circle = " << area(radius);
    }
    else if (choice == 2) {
        float length, width;
        cout << "Enter length and width of the rectangle: ";
        cin >> length >> width;
        cout << "Area of rectangle = " << area(length, width);
    }
    else if (choice == 3) {
        float base, height;
        cout << "Enter base and height of the triangle: ";
        cin >> base >> height;
        cout << "Area of triangle = " << area(base, height, true);
    }
    else {
        cout << "Invalid choice, try again!";
    }
}