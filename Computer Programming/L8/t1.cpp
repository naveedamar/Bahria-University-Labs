#include <iostream>
using namespace std;

int main(){
	
	//numbers = {{1,2}, {1,2}}
	int numbers[2][2];
	
	for(int i = 0; i < 2; i++){
		for(int j = 0; j < 2; j++){
			cout << "Enter value: ";
			cin >> numbers[i][j];
		}
	}
	
	//Performing addition
	int	first;
	int second;
	cout << "\nOperations will be performed on array = {{a,b},{c,d}} , a operation b and c operation d\n";
	cout << "\nPerforming Addition \n";
	for(int i = 0; i < 2; i++){
		first = numbers[i][0];
		second = numbers[i][1];
		cout << "Addition of " << i+1 << " values: " << first + second;
		cout << endl;
	}
	
	cout << "\nPerforming Subtration \n";
	for(int i = 0; i < 2; i++){
		first = numbers[i][0];
		second = numbers[i][1];
		cout << "Addition of " << i+1 << " values: " << first - second;
		cout << endl;
	}
	
	cout << "\nPerforming Multiplication \n";
	for(int i = 0; i < 2; i++){
		first = numbers[i][0];
		second = numbers[i][1];
		cout << "Addition of " << i+1 << " values: " << first * second;
		cout << endl;
	}
	
	cout << "\nPerforming Inverse \n";
	for(int i = 0; i < 2; i++){
		first = numbers[i][0];
		second = numbers[i][1];
		if(first * -1 == first){
			cout << "Number is negative thus inverse = " << first << endl;
		}else{
			cout << "Number is positive thus inverse = " << first * -1 << endl;
		}
		
		if(second * -1 == second){
			cout << "Number is negative thus inverse = " << second << endl;
		}else{
			cout << "Number is positive thus inverse = " << second * -1 << endl;
		}
	}		
}
