#include <iostream>
using namespace std;

void fib(int num, int first, int second){
    for(int i = 0; i < num; i++){
        cout << first << " ";
        int next = first + second;
        first = second;
        second = next;
    }
}

int main(){
    int number;
    cout << "Enter Number: ";
    cin >> number;

    cout << "Fib Series: ";
    fib(number, 0, 1);
}
