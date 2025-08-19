#include <iostream>
using namespace std;

int main(){
	float miles;
	cout<<"Welcome to the World Travel Planner! \n\n"<<"Enter the distance you plan to travel in miles: ";
	cin>>miles;
	
	cout<<"\nConverted Distance:\n-------------------\nYou plan to travel: "
	<<miles<<" miles\n"<<"In international metrices, that is approximately: "
	<<miles*1.60934;
}
