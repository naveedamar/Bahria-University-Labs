#include <iostream>
using namespace std;

struct Employee {
    string name;
    int id;
    string position;
};

struct Department {
    string name;
    Employee manager;
    bool hasManager;
    Employee emp1;
    Employee emp2;
};

void printDepartment(Department dept) {
    cout << "Department: " << dept.name << endl;

    if (dept.hasManager) {
        cout << "Manager: " << dept.manager.name << " (" << dept.manager.id << ") - " << dept.manager.position << endl;
    } else {
        cout << "Manager: None" << endl;
    }
    cout << "Employees:" << endl;
    if (dept.hasManager) {
        cout << " - " << dept.manager.name << " (" << dept.manager.id << ") - " << dept.manager.position << endl;
    }
    if (dept.emp1.id != 0) {
        cout << " - " << dept.emp1.name << " (" << dept.emp1.id << ") - " << dept.emp1.position << endl;
    }
    if (dept.emp2.id != 0) {
        cout << " - " << dept.emp2.name << " (" << dept.emp2.id << ") - " << dept.emp2.position << endl;
    }
    cout << endl;
}

int main() {
    Employee alice = {"Baby boss", 7, "Spy Kid"};
    Employee bob = {"Eminem", 1113, "FLow King"};
    Employee charlie = {"Dr. Dre", 223, "BOmb Producer"};

    Department hr;
    hr.name = "Human Resources";
    hr.manager = alice;
    hr.hasManager = true;
    hr.emp1 = alice;
    hr.emp2 = { "", 0, "" };  
    
    Department eng;
    eng.name = "Engineering";
    eng.hasManager = false;
    eng.emp1 = bob;
    eng.emp2 = charlie;

    printDepartment(hr);
    printDepartment(eng);
}