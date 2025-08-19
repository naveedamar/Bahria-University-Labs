#include <iostream>
using namespace std;

int balance = 1000;

void deposit(int cash){
	balance += cash;	
}

void withdraw(int cash){
	balance -= cash;
}

int main(){
	int choice, cash;
	
	do{
		cout << "\nWelcome to the ATM System\n1. Check Balance\n2. Deposit\n3. Withdraw\n4. Exit\nChoose an option: ";
		cin >> choice;
		
		if(choice == 1){
			cout << "Your balance is: $" << balance << endl;
		}else if(choice == 2){
			cout << "Enter ammount to be deposited: ";
			cin >> cash;
			deposit(cash);
			cout << "Deposit Succesfull, Your new Balance is: " << balance << endl;
		}else if(choice == 3){
			cout << "Enter ammount to be withdrawn: ";
			cin >> cash;
			withdraw(cash);
			cout << "Withdraw Succesfull, Your new Balance is: " << balance << endl;
		}
	}while(choice != 4);
}