#include <iostream>
using namespace std;

int main(){
	int total, discount;
	
	cout << "Enter the total purchase amount in rupees: ";
	cin >> total;
	
	if(total > 15000){
		discount = total * 0.1;
		total -= discount; 
		cout << "Congratulations You a 10% discount\n";
		cout << "Discounted Amount: " << total;
	}else{
		cout << "Your total is: " << total;
	}
}

