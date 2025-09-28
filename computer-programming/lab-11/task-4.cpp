#include <iostream>
using namespace std;

struct Room {
    double length;
    double width;
};

void inputDimensions(Room &room) {
    cout << "Enter the length of the room (in meters): ";
    cin >> room.length;
    cout << "Enter the width of the room (in meters): ";
    cin >> room.width;
}

double calculateArea(const Room &room) {
    return room.length * room.width;
}

void displayArea(const Room &room) {
    double area = calculateArea(room);
    cout << "The area of the room is: " << area << " square meters" << endl;
}

int main() {
    Room room;
    inputDimensions(room);
    displayArea(room);
}