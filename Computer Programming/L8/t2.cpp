#include <iostream>
using namespace std;

int main(){
	
	int stud_Ass[3][4];
		
	//matrix has students in row and assignment number in coloumns {{1,2,3,4}{1,2,3,4}{1,2,3,4}}
	for(int i = 0; i < 3; i++){
		cout << "Enter Student " << i + 1 << endl;
		for(int j = 0; j < 4; j++){
			cin >> stud_Ass[i][j];
		}
	}
	
	//displaying matrix
	cout << "\nOriginal Matrix ( Students x Assignments )\n";
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 4; j++){
			cout << stud_Ass[i][j] << "  ";
		}
		cout << endl;
	}
	
	
	int trans_stud_Ass[4][3];
	
	//transpo means to convert row into coloum and vice versa {{1,2,3}{1,2,3}{1,2,3}{1,2,3}}
	cout<< "\nTransposed Verion of Original Matrix ( Assignement x Student )\n";
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 4; j++){
			trans_stud_Ass[j][i] = stud_Ass[i][j];
		}
	}
	
	//display transpo
	for(int i = 0; i < 4; i++){
		for(int j = 0; j < 3; j++){
			cout << trans_stud_Ass[i][j] << "  ";
		}
		cout << endl;
	}
	
	//average
	cout << "\nCalculating average for each assignment\n";
	for(int i = 0; i < 3; i++){
		int total = 0;
		for(int j = 0; j < 4; j++){
			total += trans_stud_Ass[j][i];
		}
		float average = (float)total / 4;
		cout << "Average A " << i + 1 << ": " << average;
		cout << endl;
	}
	
}