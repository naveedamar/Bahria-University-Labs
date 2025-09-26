#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(){

	cout << "Catalog backup process initiated...\n";

	string line;
		
	cout << "\nOpening input file \"main_cataglog.txt\"...";
	ifstream input_file("main_catalog.txt");
	cout <<"\nInput file opened successfully.\n";
	
	cout << "\n\nOpening ouput file \"backup_cataglog.txt\"...";
	ofstream output_file("backup_cataglog.txt");
	cout <<"\nOuput file opened successfully.\n\n";
	
	cout << "\n\nCoping data from input file to output file...";
	while (getline(input_file, line)) {
            output_file << line << "\n";
    }
	cout <<"\nContents coppied successfully.\n\n";
	
	cout << "\nClosing input file \"main_cataglog.txt\"...";
	input_file.close();
	cout <<"\nInput file closed successfully.\n";
	
	cout << "\n\nOpening ouput file \"backup_cataglog.txt\"...";
	output_file.close();
	cout <<"\nOuput file Closed successfully.\n\n";
	
}