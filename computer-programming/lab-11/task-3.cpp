#include <iostream>
using namespace std;


struct Patient {
    int id;
    char name[100];
    int age;
    char medicalHistory[500];
};

void addPatient(Patient *p) {
    cout << "Enter Patient ID: ";
    cin >> p->id;
    cin.ignore(); 
    
    cout << "Enter Patient Name: ";
    cin.getline(p->name, 100);

    cout << "Enter Patient Age: ";
    cin >> p->age;
    cin.ignore();  

    cout << "Enter Medical History: ";
    cin.getline(p->medicalHistory, 500);
}

void updatePatient(Patient *p) {
    int id;
    cout << "Enter the Patient ID to update: ";
    cin >> id;
    cin.ignore();  

    if (p->id == id) {
        cout << "Enter New Patient Name: ";
        cin.getline(p->name, 100);

        cout << "Enter New Patient Age: ";
        cin >> p->age;
        cin.ignore();  

        cout << "Enter New Medical History: ";
        cin.getline(p->medicalHistory, 500);
    } else {
        cout << "Patient ID not found." << endl;
    }
}

void displayPatient(const Patient *p) {
    cout << "Patient ID: " << p->id << endl;
    cout << "Name: " << p->name << endl;
    cout << "Age: " << p->age << endl;
    cout << "Medical History: " << p->medicalHistory << endl;
}

int main() {
    Patient patient1;

    int choice;
    while (true) {
        cout << "\nHospital Management System\n";
        cout << "1. Add Patient\n";
        cout << "2. Update Patient\n";
        cout << "3. Display Patient Details\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();  

        switch (choice) {
            case 1:
                addPatient(&patient1);
                break;
            case 2:
                updatePatient(&patient1);
                break;
            case 3:
                displayPatient(&patient1);
                break;
            case 4:
                cout << "Exiting the program." << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

}
