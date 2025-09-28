#include <iostream>
using namespace std;

int power(int base, int exponent){
	
	if (exponent == 0) {
    	return 1;
  	} else if (exponent < 0) {
    	return 1 / power(base, -exponent);
 	} else {
    	return base * power(base, exponent - 1);
  	}
}

int main(){
	
	int base_no, exponent;

	cout << "Enter the base number: ";
	cin >> base_no;
	
	cout << "Enter the exponent: ";
	cin >> exponent;
	
	cout << base_no << " raised to the power of " << exponent << " is: " << power(base_no, exponent);

}
