#include <iostream>
using namespace std;

int main(){
	
	int seats[5][5];
	//use rand to randomly occupy a seat
	//if rand() return 0 then free otherwise occupied
	for(int i = 0; i < 5; i++){
		for(int j = 0; j < 5; j++){
			seats[i][j] = 0 + rand() % (1 - 0 + 1);
		}
	}
	//displaying seats to the user
	cout << "\t\tSeats Matrix\n\n";
	cout << "   0  1  2  3  4\n";
	for(int i = 0; i < 5; i++){
		cout << i << "  ";
		for(int j = 0; j < 5; j++){
			cout <<	seats[i][j] << "  ";
		}
		cout << endl;
	}
	//counting available seats
	int avail_seats = 0;
	for(int i = 0; i < 5; i++){
		for(int j = 0; j < 5; j++){
			if (seats[i][j] == 1){
				avail_seats++;
			}
		}
	}
	cout << "\nSeats labelled 0 are occupied but 1 are free to book";
	//aviable seat
	cout << "\nTotal available seats = " << avail_seats;
	int total_seats_to_book;
	
	//total seats to book
	cout << "\nHow many seats you want to book: ";
	cin >> total_seats_to_book;
	cout << "\nTo book a seat entering it\'s row and column number: \n";
	
	//converting int arr to char arr so that user can enter type of occupany which is char
	char char_seats[5][5];
	for(int i = 0; i < 5; i++){
		for(int j = 0; j < 5; j++){
			char_seats[i][j] = seats[i][j] + '0';
		}
	}	
	//storing data from user to new array of char type
	for(int i = 0; i < total_seats_to_book; i++){
		//booking seat dimentions
		int row, col;
		cout << "Row: ";
		cin >> row;
		cout << "Col: ";
		cin >> col;
		//char to store type of member who will be occuping the seat
		char seat_type;
		cout << "Who will be occuping this seat (F for Finance, M for Marketing and E for Engineering): ";
		cin >> seat_type;
		if(char_seats[row][col] == '1'){
			char_seats[row][col] = seat_type;
		}else{
			cout << "\nYou have selected occupied seat, please again program again and try again ";
			break;
		}
	}	
	//displaying new char types
	cout << "\n\t\tAfter Booking\n\n";
	cout << "   1  2  3  4  5\n";
	for(int i = 0; i < 5; i++){
		cout << i + 1 << "  ";
		for(int j = 0; j < 5; j++){
			cout <<	char_seats[i][j] << "  ";
		}
		cout << endl;
	}	
	//counting each professional
	int fin_total = 0, mark_total = 0, eng_total = 0;
	for(int i = 0; i < 5; i++){
		for(int j = 0; j < 5; j++){
			if(char_seats[i][j] == 'F'){
				fin_total++;
			}else if(char_seats[i][j] == 'M'){
				mark_total++;
			}else if(char_seats[i][j] == 'E'){
				eng_total++;
			}
		}
	}
	cout << "\nTotal: 25";
	cout << "\nFinance department: " << fin_total;
	cout << "\nMarketing department: " << mark_total; 
	cout << "\nEngineering department: "<< eng_total;
}