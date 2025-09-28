#include <iostream>
using namespace std;

void eligibility( int age, char vehicle, char license){
	if(vehicle == 'M' && age >= 16 && license == 'Y'){
		cout << "Your are eligible to drive motorcyle.";
	}else if(vehicle == 'C' && age >= 18 && license == 'Y'){
		cout << "Your are eligible to drive car.";
	}else{
		cout << "Your are not eligible.";
	}
}

int main(){
	int age;
	char license, vehicle;
		
	cout << "Driving Eligibility Checker\n\n";
	cout << "Enter your age: ";
	cin >> age;
	cout << "Enter the type of vehicle you want to drive (C for car / M for Motorcyle) : ";
	cin >> vehicle;
	cout << "Do you have a valid driving license: (Y for Yes / N for No) : ";
	cin >> license;
	
	eligibility(age, vehicle, license);	
}