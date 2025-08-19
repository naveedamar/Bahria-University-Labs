#include <iostream>
using namespace std;

int main(){
	int reserved = 35,book;
	
	cout<<"Welcome to the Ticket Reservation System!\n"<<"Enter the number of seats you want to reserve: ";
	cin>>book;
	
	if(book <= reserved){
		cout<<"Seats reserved successfully! Enjoy your journey. \n"<<"Remaining Avaiable seats: "
		<< reserved - book;
	}else{
		while(book > reserved){
			cout<<endl;
			cout << "Entered seats exceed limit, please try again. \n";
			cout<<"Welcome to the Ticket Reservation System!\n"
			<<"Enter the number of seats you want to reserve: ";
			cin>>book;
			if(book <= reserved){
				cout<<endl;
				cout<<"Seats reserved successfully! Enjoy your journey. \n"
				<<"Remaining Avaiable seats: "<< reserved - book;
			}
		}
	}
}
