#include <iostream>
using namespace std;

int main(){
	
	int size = 8;
	int arr[size];
	bool termination_zero;
	
	do{
		cout << "Enter array elements (press 0 for termination): " << endl;
		termination_zero = false;
		for(int i = 0; i < size; i++){
			cin >> arr[i];
			if(arr[i] == 0){
				termination_zero = true;
				break;
			}
		}
		
		if(termination_zero == false){
			cout << "Array with no zero: ";
			for(int i = 0; i < size; i++){
				cout << arr[i] << ", ";
			}
		}
		
	}while(termination_zero == true);
	
}