#include <iostream>
using namespace std;

int main(){
	
	int arr[10];
	int reverse_arr[10];
	
	cout << "Enter ten integer ratings: \n";
	for(int i = 0; i < 10; i++){
		cout << "Rating " << i + 1 << ": ";
		cin >> arr[i];
	}
	
	for(int i = 0; i < 10; i++){
		reverse_arr[i] = arr[9-i];
	}
	
	cout << "\nRating in reverse order: \n";
	for(int i = 0; i < 10; i++){
		cout << reverse_arr[i] << " ";
	}
}