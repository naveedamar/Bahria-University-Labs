#include <iostream>
using namespace std;

void Shift(int arr[5], int shift){
	
	int temp[5];
	
	for(int i = 0; i < 5; i++){
		temp[(i + shift) % 5] = arr[i];
	}
	
	for(int i = 0; i < 5; i++){
		cout << temp[i] << ", ";
	}
}

int main(){
	
	int clock[5] = {1,2,3,4,5};
	char choice;
	int shift;
	
	
	cout << "Original Array: ";
	for(int i = 0; i < 5; i++){
		cout << clock[i] << " ";
	}
	cout << endl;
	
	cout << "Enter R for Right AND L for Left Shift : ";
	cin >> choice;
	cout << "Enter Shift Quantity: ";
	cin >> shift;
	
	
	if(choice == 'L'){
		shift = -shift;	
	}
	
	cout << "Array after shift: ";
	Shift(clock, shift);
}