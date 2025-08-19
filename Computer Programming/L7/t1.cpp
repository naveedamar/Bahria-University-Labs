#include <iostream>
using namespace std;

int main(){	
	string Menu[4] = {"Appetizers", "Mains","Desserts","Beverages"};
	int choice, item, quantity;
	char delivery_opt, order;
	string menu, payment_method,address;
	
	for(int i = 0; i < 4; i++){
		cout << i + 1 << ". " << Menu[i];
		cout << endl;
	}
	
	cout << "Enter the number corresponding to your choice : ";
	cin >> choice;
	
	if(choice == 1){
		menu = "Appetizer";
	}else if(choice == 2){
		menu = "Main Dish";
	}else if(choice == 3){
		menu = "Dessert";
	}else if(choice == 4){
		menu = "Beverages";
	}
	
	cout << "Items in Category " << choice << ":\n";
	for(int i = 0; i < 3; i++){
		cout << i + 1 << ". " << menu << " " << i+1;
		cout << endl;
	}
	cout << "Enter Item: ";
	cin >> item;
	
	cout << "Enter quantity (1-10) : ";
	cin >> quantity;
	
	cout << "Choose delivery (D) or pickup (P) : ";
	cin >> delivery_opt;
	
	cout << "Enter delivery address: ";
	cin >> address;
	
	cout << "Choose payment method (Cash, Credit Card, Online Payment): ";
	cin >> payment_method;
	
	cout << "\nOrder Summary: \n" << menu << " " << item << " x" << quantity;
	cout << "\nDelivery Option: " << (delivery_opt == 'D') ? cout << "Delivery" : cout << "Pickup";
	cout << "\nDelivery Address: " << address;
	cout << "\nPayment Method: " << payment_method;
	cout << "\nConfirm Order (Y / N) ";                                                              
	cin >> order;
	
	cout << "\nOrder Confirmed. Thank You!";
}