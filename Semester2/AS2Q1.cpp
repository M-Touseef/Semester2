#include<iostream>
#include<fstream>
using namespace std;
void CreateFile(fstream&file, int empcode[], int size)
{
	file.open("Employee_Data.txt", ios::out);
	if (!file.is_open()){
		cout << "Failed to create file." << endl;
	}
	else {
			for (int i = 0; i < size; i++) {
				cin >> empcode[i];
				file << empcode[i] << endl;
			}
			cout << "File created successfully." << endl;
	}
	file.close();
}
void read(fstream& file, int empcode[], int size) {
	file.open("Employee_Data.txt", ios::in);
	if (!file.is_open())
	{
		cout << "Failed to read file." << endl;
	}
	else {
		{
			for (int i = 0; i < size; i++) {
				file >> empcode[i];
			}
			cout << "File read successfully." << endl;
		}
		file.close();
	}
}
int findEmpCode(int empCodes[], int size, int searchEmpCode) {
	for (int i = 0; i < size; i++) {
		if (empCodes[i] == searchEmpCode) {
			return i;
		}
	}
	return -99;
}
int main() {
	int const size = 10;
	int empCode[10] = {0};
	int number;
	fstream file;
	CreateFile(file, empCode,size);
	read(file,empCode,size);
	cout << "Enter the Number for Search" << endl;
	cin >> number;
	int value_return = findEmpCode(empCode, size,number);
	if (value_return!= 99){
		cout << "The index of the number is " <<value_return<< endl;
	}
	else {
		cout << "Number did not find" << endl;
		
	}
	return 0;
}