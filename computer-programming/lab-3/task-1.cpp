#include <iostream>
using namespace std;

int main(){
	char input;
	cout << "Enter a character: ";
	cin >> input;
	
	if(input >= '0' && input <='9'){
		cout << input <<" is a digit";
	}else{
		if(	input == 'A' || input == 'E' ||input == 'I' || input == 'O' || input == 'U'||input == 'a' 
			|| input == 'e' || input == 'i' || input == 'o' || input == 'u'){
			cout << input <<" is a vowel";
		}else{
			cout << input <<" is a consonant";
		}
	}
}
