#include<iostream>
#include<fstream>
using namespace std;
void write(fstream& file, int empcode[], int size) {
	file.open("Employee_Data.txt", ios::out);
	if (!file.is_open()) {
		cout << "File does not open sucessfully!" << endl;
	}
	else {
		cout << "Enter the Value to Store in Array(empCode)\n";
		for (int i = 0; i < size; i++) {
			cin >> empcode[i];
			file << empcode[i] << endl;
		}
	}
}
void read(fstream&, int empcode[], int size) {

	cout << "Read the File and Store it in empCode(Array)" << endl;

	fstream file;
	//error handling and use ios flag
	file.open("Employee_Data.txt", ios::in);
	if (!file.is_open()) {
		cout << "File does not open !\n";
	}
	else {
		for (int i = 0; i < size; i++) {
			file >> empcode[i];
			cout << empcode[i] << " ";
		}
		cout << "\nFile is sucessfully read and store in Array(empCode)" << endl;
	}
}
int find(fstream&, int array[], int x) {
	int number = 0, index = 99;
	cout << "Enter the number you want to search" << endl;
	cin >> number;
	for (int i = 0; i < x; i++) {
		if (array[i] == number) {
			index = i;
		}
	}
	return index;
}
int main() {
	int const size = 10;
	int empCode[size] = {};
	int result;
	fstream file;
	write(file, empCode, size);
	cout << "The End of the Function 1" << endl;
	read(file, empCode, size);
	cout << "The End of the Function 2" << endl;
	result = find(file, empCode, size);
	if (result == 99) {
		cout << "Number does not found\n";
	}
	else {
		cout << "The index of the number is : " << result << endl;
	}
	file.close();
	return 0;

}
