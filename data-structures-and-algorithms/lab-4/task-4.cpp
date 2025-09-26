#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;

long long fact_1(int n)
{
    if (n == 0 || n == 1)
        return 1;
    else
        return n * fact_1(n - 1);
}

long long fact_2(int n)
{
    long long result = 1;
    for (int i = 2; i <= n; i++)
        result *= i;
    return result;
}

void test_factorial(int n)
{
    auto start1 = high_resolution_clock::now();
    fact_1(n);
    auto stop1 = high_resolution_clock::now();
    auto duration1 = duration_cast<nanoseconds>(stop1 - start1);

    cout << "Recursive factorial of " << n
        << " | Time: " << duration1.count() << " ns\n";

    auto start2 = high_resolution_clock::now();
    fact_2(n);
    auto stop2 = high_resolution_clock::now();
    auto duration2 = duration_cast<nanoseconds>(stop2 - start2);

    cout << "Iterative factorial of " << n
        << " | Time: " << duration2.count() << " ns\n\n";
}

int main()
{
    test_factorial(10);
    test_factorial(50);
    test_factorial(100);
    test_factorial(150);
    test_factorial(200);
    test_factorial(250);
    test_factorial(300);
}
