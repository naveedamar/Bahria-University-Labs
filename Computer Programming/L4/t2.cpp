#include <iostream>
using namespace std;

int main(){
	int stock,quantity = 0,price = 0, quantity_total=0, total=0;
	
	cout << "Enter the number of different items in stock: " ;
	cin >> stock;
	
	for(int i = 1; i <= stock; i++){
		cout << "Enter the price per unit for item " << i << ": ";
		cin >> price;
		
		cout << "Enter the quantity in stock for item "<< i << ": ";
		cin >> quantity;
		
		quantity_total = quantity*price;
		
		total += quantity_total;
		cout << endl;
	}
	
	cout << "\nTotal Value of the inventory: " << total;
}
