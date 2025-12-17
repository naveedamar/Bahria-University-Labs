#include <iostream>
#include <string>
#include <limits>
using namespace std;

struct Parcel
{
    string name;
    int location;
    int priority;
    bool delivered;
    Parcel* next;
};

string areas[6] = {
    "Clifton Main",
    "Boat Basin",
    "Zamzama",
    "Khayaban-e-Ittehad",
    "DHA Phase 8",
    "Sea View"
};

int graph[6][6] = {
    {0, 2, 3, 4, 5, 6},
    {2, 0, 1, 2, 0, 0},
    {3, 1, 0, 1, 2, 0},
    {4, 2, 1, 0, 1, 2},
    {5, 0, 2, 1, 0, 2},
    {6, 0, 0, 2, 2, 0}
};

Parcel* head = NULL;

void heading()
{
    cout << "\n=============================================\n";
    cout << " CLIFTON PARCEL DELIVERY SYSTEM (SINGLE RIDER)\n";
    cout << "=============================================\n";
}

int getValidatedInt(int min, int max)
{
    int value;
    do
    {
        cin >> value;
        if (cin.fail() || value < min || value > max)
        {
            cout << "Invalid input! Try again: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        else
        {
            break;
        }
    }
    while (true);
    return value;
}

void showAreas()
{
    cout << "\nSelect Delivery Location:\n";
    for (int i = 0; i < 6; i++)
        cout << i << " -> " << areas[i] << "\n";
    cout << "Enter choice (0-5): ";
}

void viewMap()
{
    cout << "\n========== CLIFTON INTERNAL DELIVERY MAP ==========\n\n";
    for (int i = 0; i < 6; i++)
    {
        cout << areas[i] << " --> ";
        bool connected = false;
        for (int j = 0; j < 6; j++)
        {
            if (graph[i][j] != 0)
            {
                cout << areas[j] << "(" << graph[i][j] << " km) ";
                connected = true;
            }
        }
        if (!connected) cout << "No direct roads";
        cout << "\n";
    }
    cout << "===============================================\n";
}

void insertParcel()
{
    Parcel* p = new Parcel();

    cout << "Enter Parcel Name: ";
    cin.ignore();
    getline(cin, p->name);

    showAreas();
    p->location = getValidatedInt(0, 5);

    cout << "Priority (2 = Urgent, 1 = Normal): ";
    p->priority = getValidatedInt(1, 2);

    p->delivered = false;
    p->next = head;
    head = p;

    cout << "Parcel Added Successfully\n";
}

void deleteParcel()
{
    if (!head)
    {
        cout << "No parcels to delete\n";
        return;
    }

    string name;
    cout << "Enter Parcel Name to Delete: ";
    cin.ignore();
    getline(cin, name);

    Parcel* t = head;
    Parcel* p = NULL;

    while (t)
    {
        if (t->name == name)
        {
            if (p) p->next = t->next;
            else head = t->next;
            delete t;
            cout << "Parcel Deleted\n";
            return;
        }
        p = t;
        t = t->next;
    }
    cout << "Parcel Not Found\n";
}

void markDelivered()
{
    if (!head)
    {
        cout << "No parcels available\n";
        return;
    }

    string name;
    cout << "Enter Parcel Name Delivered: ";
    cin.ignore();
    getline(cin, name);

    Parcel* t = head;
    while (t)
    {
        if (t->name == name)
        {
            t->delivered = true;
            cout << "Parcel Marked Delivered\n";
            return;
        }
        t = t->next;
    }
    cout << "Parcel Not Found\n";
}

int minDist(int dist[], bool vis[])
{
    int m = 9999, idx = -1;
    for (int i = 0; i < 6; i++)
        if (!vis[i] && dist[i] < m)
        {
            m = dist[i];
            idx = i;
        }
    return idx;
}

void dijkstra(int src, int dist[], int prev[])
{
    bool vis[6] = {false};
    for (int i = 0; i < 6; i++)
    {
        dist[i] = 9999;
        prev[i] = -1;
    }
    dist[src] = 0;

    for (int i = 0; i < 6; i++)
    {
        int u = minDist(dist, vis);
        if (u == -1) break;
        vis[u] = true;
        for (int v = 0; v < 6; v++)
        {
            if (graph[u][v] &&
                dist[u] + graph[u][v] < dist[v])
            {
                dist[v] = dist[u] + graph[u][v];
                prev[v] = u;
            }
        }
    }
}

Parcel* selectNextParcel(int current)
{
    Parcel* t = head;
    Parcel* best = NULL;
    int dist[6], prev[6];
    dijkstra(current, dist, prev);

    while (t)
    {
        if (!t->delivered)
        {
            if (!best ||
                t->priority > best->priority ||
                (t->priority == best->priority &&
                    dist[t->location] < dist[best->location]))
            {
                best = t;
            }
        }
        t = t->next;
    }
    return best;
}

void deliverParcelsAtLocation(int loc)
{
    Parcel* t = head;
    bool deliveredHere = false;

    while (t)
    {
        if (!t->delivered && t->location == loc)
        {
            cout << t->name << " ";
            t->delivered = true;
            deliveredHere = true;
        }
        t = t->next;
    }

    if (deliveredHere)
        cout << "\n";
}

void showBestRoute()
{
    int current = 0;
    int totalFuel = 0;
    bool deliveredAny = false;

    cout << "\nOptimized Delivery Route:\n";
    cout << areas[current] << "\n";

    while (true)
    {
        Parcel* target = selectNextParcel(current);
        if (!target) break;

        int dist[6], prev[6];
        dijkstra(current, dist, prev);

        int path[6], c = 0;
        int d = target->location;
        while (d != -1)
        {
            path[c++] = d;
            d = prev[d];
        }

        for (int i = c - 1; i >= 0; i--)
        {
            int nextLoc = path[i];

            if (nextLoc != current)
            {
                cout << "Moving to " << areas[nextLoc] << "\n";
                totalFuel += graph[current][nextLoc];
                current = nextLoc;
            }

            cout << "Delivering at " << areas[current] << ": ";
            deliverParcelsAtLocation(current);
            deliveredAny = true;
        }
    }

    if (!deliveredAny)
    {
        cout << "\nNo Pending Parcels\n";
        return;
    }

    cout << "\nTotal Estimated Fuel Cost: " << totalFuel << "\n";
}


int main()
{
    int ch;
    do
    {
        heading();
        cout << "1 Insert Parcel\n";
        cout << "2 Delete Parcel\n";
        cout << "3 Mark Delivered\n";
        cout << "4 Show Best Route\n";
        cout << "5 View Clifton Map\n";
        cout << "0 Exit\n";
        cout << "Choice: ";

        ch = getValidatedInt(0, 5);

        if (ch == 1) insertParcel();
        else if (ch == 2) deleteParcel();
        else if (ch == 3) markDelivered();
        else if (ch == 4) showBestRoute();
        else if (ch == 5) viewMap();
    }
    while (ch != 0);
}
