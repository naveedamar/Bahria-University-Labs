#include <iostream>
#include <math.h>
using namespace std;

float calculator(int a, char op, int b){
	switch(op){
		case '/':
			return (a / b);
		case '*':
			return (a * b);
		case '+':
			return (a + b);
		case '-':
			return (a - b);
		case '^':
			return pow(a, b);			
	}
}
int main(){
	int num1,num2;
	char oper;
	
	cout << "Enter Number 1: ";
	cin >> num1;
	
	cout << "Select Operation (/, *, +, -, ^): ";
	cin >> oper;
	
	cout << "Enter Number 2: ";
	cin >> num2;
	
	cout << "Result: " << num1 << " " <<  oper << " " << num2 << " = " << calculator(num1, oper, num2);
}