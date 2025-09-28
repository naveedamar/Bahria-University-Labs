//
// Created by Naveed on 27/09/2025.
//
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

constexpr int MAX = 3;
constexpr int JARS = 4;

void display(int jars[JARS][MAX], int top[JARS])
{
    cout << "\nJars State:\n";
    for (int i = 0; i < JARS; i++)
    {
        cout << "Jar " << i + 1 << ": ";
        if (top[i] == -1) cout << "Empty";
        else
        {
            for (int j = 0; j <= top[i]; j++)
            {
                if (jars[i][j] == 1) cout << "A ";
                else if (jars[i][j] == 2) cout << "K ";
                else if (jars[i][j] == 3) cout << "O ";
            }
        }
        cout << endl;
    }
}

bool push(int jar[], int& top, int fruit)
{
    if (top == MAX - 1) return false;
    if (top != -1 && jar[top] != fruit) return false;
    jar[++top] = fruit;
    return true;
}

int pop(int jar[], int& top)
{
    if (top == -1) return 0;
    return jar[top--];
}

bool checkWin(int jars[JARS][MAX], int top[JARS])
{
    int filled = 0;
    for (int i = 0; i < JARS; i++)
    {
        if (top[i] == 2)
        {
            int fruit = jars[i][0];
            bool same = true;
            for (int j = 1; j < MAX; j++)
            {
                if (jars[i][j] != fruit) same = false;
            }
            if (same) filled++;
        }
    }
    return (filled == 3);
}

int main()
{
    srand(time(0));
    int jars[JARS][MAX];
    int top[JARS];
    for (int i = 0; i < JARS; i++) top[i] = -1;

    int fruits[9] = {1, 1, 1, 2, 2, 2, 3, 3, 3};
    for (int i = 0; i < 9; i++)
    {
        int r = rand() % 9;
        swap(fruits[i], fruits[r]);
    }

    int idx = 0;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < MAX; j++)
        {
            jars[i][j] = fruits[idx++];
            top[i]++;
        }
    }

    display(jars, top);

    while (true)
    {
        if (checkWin(jars, top))
        {
            cout << "\nYou Win!\n";
            break;
        }
        int from, to;
        cout << "\nMove FROM (1-4, 0 quit): ";
        cin >> from;
        if (from == 0) break;
        cout << "Move TO (1-4): ";
        cin >> to;
        from--;
        to--;
        if (from < 0 || from >= JARS || to < 0 || to >= JARS)
        {
            display(jars, top);
            continue;
        }

        int fruit = pop(jars[from], top[from]);
        if (fruit == 0)
        {
            display(jars, top);
            continue;
        }

        if (!push(jars[to], top[to], fruit))
        {
            push(jars[from], top[from], fruit);
        }

        display(jars, top);
    }
}
