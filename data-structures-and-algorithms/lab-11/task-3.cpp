//
// Created by Naveed on 27/11/2025.
//

/*Exercise 3: Patient’s Priority Queue
There are different patients of different age group visit to Dr. ABC for treatment. They are waiting in a queue in FIFO fashion.
Dr. ABC attends the patient to facilitate them in following order.
Emergency patient visit first then old age patient, then children, then new patients, then regular patients.
Priorities are given as
1.	Emergency patient
2.	Old age patients
3.	Children
4.	New patient
5.	Regular Patients.
*/

#include <iostream>
using namespace std;

struct Patient
{
    int id;
    int priority;
};

class PriorityQueue
{
public:
    Patient arr[100];
    int size;

    PriorityQueue()
    {
        size = 0;
    }

    void insertPatient(int id, int priority)
    {
        arr[size].id = id;
        arr[size].priority = priority;
        size++;
        rearrange();
    }

    void rearrange()
    {
        for (int i = 0; i < size - 1; i++)
        {
            for (int j = i + 1; j < size; j++)
            {
                if (arr[j].priority < arr[i].priority)
                {
                    Patient temp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp;
                }
            }
        }
    }

    void displayQueue()
    {
        if (size == 0)
        {
            cout << "Queue is empty" << endl;
            return;
        }
        for (int i = 0; i < size; i++)
            cout << "Patient ID: " << arr[i].id << ", Priority: " << arr[i].priority << endl;
    }

    void servePatient()
    {
        if (size == 0)
        {
            cout << "No patients in queue" << endl;
            return;
        }
        cout << "Serving Patient ID: " << arr[0].id << endl;
        for (int i = 1; i < size; i++)
            arr[i - 1] = arr[i];
        size--;
    }
};

int main()
{
    PriorityQueue pq;
    int choice;

    while (true)
    {
        cout << "\n1. Add Patient\n2. Serve Next Patient\n3. Display Queue\n4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1)
        {
            int type, id;
            cout << "Select patient type:\n";
            cout << "1. Emergency\n2. Old Age\n3. Children\n4. New Patient\n5. Regular Patient\n";
            cout << "Enter type: ";
            cin >> type;
            cout << "Enter Patient ID: ";
            cin >> id;
            pq.insertPatient(id, type);
        }
        else if (choice == 2)
        {
            pq.servePatient();
        }
        else if (choice == 3)
        {
            pq.displayQueue();
        }
        else if (choice == 4)
        {
            break;
        }
        else
        {
            cout << "Invalid choice" << endl;
        }
    }
}
