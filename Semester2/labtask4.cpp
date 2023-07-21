#include<iostream>
#include<fstream>
using namespace std;
void readdata(int*array,int& size);
void display(int* array, int size);



int main() {
	int size = 0;
	int* array = new int[size];
		readdata(array, size);
		display(array, size);
	return 0;
}
//open the file and read the data
void readdata(int* array, int&size) {
	fstream file;
	file.open("data.txt", ios::in);
	if (!file.is_open()) {
		cout << "File did not open sucessfully" << endl;
	}
	else {
		int temp = 0;
		while (file >> temp) {
			*(array + size) = temp;
			size++;
		}
		
	}
}
//Display the Array
void display(int* array, int size) {
	cout << "Data of file is: " << endl;
	for (int i = 0; i < size; i++) {
		cout << *(array + i) << " ";
	}
}
