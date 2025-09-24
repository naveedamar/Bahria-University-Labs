#include <iostream>
using namespace std;

int main(){

	string msg1, msg2;
	
	cout << "Enter first msg: ";
	getline(cin,msg1);

	cout << "Enter second msg: ";
	getline(cin,msg2);
	
	if(msg1.length() < msg2.length()){
		cout << "Shorter msg: " << msg1;
	}else if(msg1.length() == msg2.length()){
		cout << "Both msg have same length";		
	}else{
		cout << "Shorter msg: " << msg2;
	}
}