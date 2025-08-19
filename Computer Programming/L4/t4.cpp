#include <iostream>
using namespace std;

int main(){
	
	int number;
	
	cout << "Enter a number to see it\'s multiplication table: ";
	cin >> number;
	
	cout << "Multiplication table for " << number << endl;
	
	for(int i = 0; i < 10; i++){
		cout << number << " * " << i + 1 << " = " << number * (i + 1) << endl;
	}
}