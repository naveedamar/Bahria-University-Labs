#include <iostream>
using namespace std;

int main(){
	int f1,f2,f3;
	
	cout <<"Enter Age of friend 1: ";
	cin >> f1;
	cout <<"Enter Age of friend 2: ";
	cin >> f2;
	cout <<"Enter Age of friend 3: ";
	cin >> f3;
	
	if(f1 < f2 && f1 < f3 ){
		cout<<"The youngest friend is friend 1 with an age of " << f1 << " years.";
	}else if(f2 < f1 && f2 < f3 ){
		cout<<"The youngest friend is friend 2 with an age of " << f2 << " years.";
	}else{
		cout<<"The youngest friend is friend 3 with an age of " << f3 << " years.";
	}
}

