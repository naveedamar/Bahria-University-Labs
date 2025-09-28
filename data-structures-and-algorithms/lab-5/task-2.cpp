//
// Created by Naveed on 27/09/2025.
//
#include <iostream>
#include <stack>
#include <sstream>
using namespace std;

int evaluatePostfix(string expression)
{
    stack<int> s;
    stringstream ss(expression);
    string token;

    while (ss >> token)
    {
        if (isdigit(token[0]))
        {
            s.push(stoi(token));
        }
        else
        {
            int b = s.top();
            s.pop();
            int a = s.top();
            s.pop();

            if (token == "+") s.push(a + b);
            else if (token == "-") s.push(a - b);
            else if (token == "*") s.push(a * b);
            else if (token == "/") s.push(a / b);
        }
    }
    return s.top();
}

int main()
{
    string expr1 = "8 7 + 4 *";
    cout << "Input: " << expr1 << endl;
    cout << "Output: Result: " << evaluatePostfix(expr1) << endl << endl;


    string expr2 = "9 5 + 6 +";
    cout << "Input: " << expr2 << endl;
    cout << "Output: Result: " << evaluatePostfix(expr2) << endl;

}
