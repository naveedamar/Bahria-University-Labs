#include <iostream>
using namespace std;

int main(){
	int no1,no2, hcf;
	
	cout<< "Welcome to the GCD/HCF Calculator\n";
	cout<< "Enter two numbers to find their GCD/HCF:\n";
	cout<< "Enter first number: ";
	cin>>no1;
	cout<< "Enter second number: ";
	cin>>no2;
	
	for (int i = 1; i <= no1 && i <= no2; i++) {
        if (no1 % i == 0 && no2 % i == 0) {
            hcf = i;
        }
    }

    cout << "The Greatest Common Divisor (GCD) or Highest Common Factor (HCF) of " 
    << no1 << " and " << no2 << " is: " << hcf << endl;
}
