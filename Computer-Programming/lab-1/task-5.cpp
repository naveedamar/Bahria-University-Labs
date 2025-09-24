#include <iostream>

#include <string>
#include <random>
using namespace std;

int main(){
	string traffic[3] = {"Red-Stop", "Green-Go", "Yellow-Ready"};
	
	cout << "Traffic Light is: " << traffic[rand() % 3];

}
