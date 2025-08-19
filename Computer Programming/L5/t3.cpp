#include <iostream>
using namespace std;

char most_sig(string num){
	return num[0];	
}

char least_sig(string num){
	int length = num.length();
	return num[length - 1];
}

bool is_palindrome(string num){
	if( least_sig(num) == most_sig(num) ){
		return true;
	}else{
		return false;
	}
}

int main(){
	string num;
	
	cout << "Enter a three-digit number: ";
	cin >> num;
	
	cout << "Most Significant Digit: " << most_sig(num);
	cout << endl;
	cout << "Least Significant Digit: " << least_sig(num);
	cout << endl;
	
	bool pal =  is_palindrome(num);
	if(pal == true){
		cout << num << " is a palindrome.";
	}else{
		cout << num << " is a not palindrome.";
	}
}