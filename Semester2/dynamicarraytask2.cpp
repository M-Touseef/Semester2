#include <iostream>
#include <fstream>

using namespace std;
//Prototypes
int readdata(int[][3], int rows, int columns);
void display_col(int[][3], int, int);

int main() {
	int const rows = 2, columns = 3;
	int array[rows][columns];
	int check = readdata(array, rows, columns);
	if (check == 0) {
		display_col(array, rows, columns);

	}
	else {
		cout << "File did not open sucessfully" << endl;
	}
	return 0;
}
//read the data from the file
int readdata(int array[][3], int rows, int columns) {
	fstream file;
	file.open("M1.txt", ios::in);
	if (!file.is_open()) {
		return 1;
	}
	else {
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < columns; j++) {
				file >> array[i][j];
			}
		}
		return 0;
	}
}
//Display Function
void display_col(int array[][3], int rows, int columns) {
	for (int i = 0; i<columns; i++) {
		for (int j =0; j < rows; j++) {
			cout << array[j][i] << " ";
		}
		cout << endl;
	}
}
