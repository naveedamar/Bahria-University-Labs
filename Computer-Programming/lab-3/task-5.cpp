#include <iostream>
using namespace std;

int main(){
	float temp;
	
	cout <<"Enter Temperature: ";
	cin>>temp;
	
	if(temp <36.5){
		cout<<"You have Hypothermia";
	}else if(temp >= 36.5 && temp< 37.5){
		cout<<"You have Normal Body Temperature";
	}else if(temp >= 37.5 && temp< 38.5){
		cout<<"You have Low grade Fever";
	}else{
		cout<<"You have High Fever";
	}
}
