#include <iostream>
#include <fstream>
#include <bits/stdc++.h>
#include <string>
using namespace std;

int main(){

	int quote_word_limit = 4;
	string four_words_quote[quote_word_limit];
	
	for(int i = 0; i < quote_word_limit; i++){
		cout << "Enter the " << i + 1 << " word of your quote: ";
		cin >> four_words_quote[i];
	}
	
	string choice;
	cout << "\n\nDo you wish to save this in upper-case or lower-case? ";
	cin >> choice;
	
	if (choice == "upper"){
		ofstream upper;
		upper.open("upper_quotes.txt", ios::app);
		cout << "\n\nHere is your quote in upper-case: ";
		for(int i = 0; i < quote_word_limit; i++){
			transform(four_words_quote[i].begin(), four_words_quote[i].end(), four_words_quote[i].begin(),::toupper);
			cout << four_words_quote[i] << " ";
		}
		for(int i = 0; i < quote_word_limit; i++){
			upper << four_words_quote[i] << " ";
		}
		upper << endl;
		upper.close();
		cout << "\nThe upper-case quote has been saved to upper_quotes.txt";
		
	}else if(choice == "lower"){
		ofstream lower;
		lower.open("lower_quotes.txt", ios::app);
		for(int i = 0; i < quote_word_limit; i++){
			lower << four_words_quote[i] << " ";
		}
		lower << endl;
		lower.close();
		cout << "\nThe lower-case quote has been saved to lower_quotes.txt";
	}
}