//
// Created by Naveed on 25/09/2025.
//
#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;

void print_stars(int N)
{
    int operation_number_1 = 0;
    int operation_number_2 = 0;
    int operation_number_3 = 0;

    auto start = high_resolution_clock::now();

    for (int i = 1; i <= N; i++)
    {
        operation_number_1++;
        for (int j = 1; j <= N - i; j++)
        {
            operation_number_2++;
            cout << "  ";
        }
        for (int j = 1; j <= 2 * i - 1; j++)
        {
            operation_number_3++;
            cout << "*";
        }
        cout << "\n";
    }

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<nanoseconds>(stop - start);

    cout << "Operations for N = " << N << " is " << operation_number_1 * operation_number_2 * operation_number_3 <<
        " and time taken is " << duration.count() << " nanoseconds" << endl;
}

int main()
{
    print_stars(10);
    print_stars(15);
    print_stars(25);
    print_stars(50);
    print_stars(100);
}
