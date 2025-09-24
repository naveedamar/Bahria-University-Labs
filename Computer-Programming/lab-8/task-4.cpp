#include <iostream>
using namespace std;

void show_grid( char grid[3][3]){
	
	cout << "    0  1  2 \n";
	for(int i = 0; i < 3; i++){
		cout << i << "  ";
		for(int j = 0; j < 3; j++){
			cout <<	" " << grid[i][j] << " ";
		}
		cout << endl;
	}
	
}

// function only checks horizontally and vertically, can impliment diagonal but not have time as assignment deadline is almost finished
bool show_winner( char grid[3][3], char value){
	// counter to check if 3 consective value are same
	int count_hori = 0, count_verti = 0;
	
	//checking horizontally to see if value is same
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			if (grid[i][j] == value){
				count_hori++;
			}
			else if( grid[j][i] == value){
				count_verti++;
			}
		}
		//this means a line either hori or vertical is of same value, thus return true
		if(count_hori == 3 || count_verti == 3){
			return true;
		}
		
		//reseting bc if either was 3 functoin would have exited and that has not happend so making it 0 for next iteration
		count_hori = 0, count_verti = 0;
	}
	return false;
}


int main(){
	
	char grid[3][3];
	
	//assign '-' to the grid, bc will use it to compare afterwards
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			grid[i][j] = '-';
		}
	}
	
	cout << "Current Board\n\n";
	show_grid(grid);
	
	//variable for while to track moves, 9 bc arr is 3x3 
	int count = 0;
	int row, col; // to pass to assign function so that it can assign it to the grid
	while (count < 9){
		
		cout << "Player 0, Enter Your Move\n";
		cout << "Row: ";
		cin >> row;
		cout << "Col: ";
		cin >> col;
		grid[row][col] = '0';
		
		cout << endl;
		show_grid(grid);
		
		if(show_winner(grid, '0') == true){
			cout << "Player 0 won";
			break;
		}
		
		cout << "Player X, Enter Your Move\n";
		cout << "Row: ";
		cin >> row;
		cout << "Col: ";
		cin >> col;
		grid[row][col] = 'X';
		
		cout << endl;
		show_grid(grid);
		
		if(show_winner(grid, 'X') == true){
			cout << "Player 1 won";
			break;
		}
	}		
}