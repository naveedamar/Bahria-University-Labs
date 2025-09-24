#include <iostream>
using namespace std;

int main(){
	int x = 65;
	char alpha = 'A';
	
	cout << "\nUppercase letter and their ASCIII\n" << endl;
	while(x < 91)
	{
		cout << "ASCII Character: " << alpha << ", ASCII Value: " << x;
		cout << endl;
		x++;
		alpha++;
	}
	
	cout << "\nLowercase letter and their ASCIII \n"<<endl;
	
	alpha = 'a';
	x = 97;
	while(x < 123)
	{
		cout << "ASCII Character: " << alpha << ", ASCII Value: " << x;
		cout << endl;
		x++;
		alpha++;
	}
}