#include <iostream>
using namespace std;

struct Student {
    string name;
    int age;
    int grade;
};

void swapStudents(Student* s1, Student* s2) {
    Student temp = *s1;
    *s1 = *s2;
    *s2 = temp;
}

int main() {
    Student student1 = {"Basit Khan Zada", 22, 10};
    Student student2 = {"Champak Lala", 52, 11};

    cout << "Before swapping:\n";
    cout << "Student 1: Name: " << student1.name << ", Age: " << student1.age << ", Grade: " << student1.grade << endl;
    cout << "Student 2: Name: " << student2.name << ", Age: " << student2.age << ", Grade: " << student2.grade << endl;

    swapStudents(&student1, &student2);

    cout << "\nAfter swapping:\n";
    cout << "Student 1: Name: " << student1.name << ", Age: " << student1.age << ", Grade: " << student1.grade << endl;
    cout << "Student 2: Name: " << student2.name << ", Age: " << student2.age << ", Grade: " << student2.grade << endl;

}