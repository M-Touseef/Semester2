#include<iostream>
#include<fstream>
using namespace std;
void readdata(int* array, int& size);
void display(int* array, int size);
int max_value(int* array, int size);
void update_data(int* array, int size, int maxx);



int main() {
	int size = 0;
	int* array = new int[size];
	readdata(array, size);
	cout << "Data : ";
	display(array, size);
	int maximum = max_value(array, size);
	update_data(array, size, maximum);
	cout << "Update data : ";
	display(array, size);
	return 0;
}
//open the file and read the data
void readdata(int* array, int& size) {
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
	for (int i = 0; i < size; i++) {
		cout << *(array + i) << " ";
	}
	cout << endl;
}
//Find max value
int max_value(int* array, int size) {
	int max = 0;
	for (int i = 0; i < size; i++)
	{
		if (*(array + i) > max) {
			max = *(array + i);
		}
	}
	cout << "Max Value is : " << max << endl;
	return max;
}
//update the Data
void update_data(int* array, int size, int maxx) {
	for (int i = 0; i < size; i++) {
		*(array + i) = maxx - *(array + i);
	}
}