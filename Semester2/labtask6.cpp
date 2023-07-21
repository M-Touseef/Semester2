#include<iostream>
#include<fstream>
using namespace std;
void readdata(int* array, int& size);
void display(int* array, int size);
void even_odd(int* myarray, int size);
//Main function
int main() {
	int size = 0;
	int* array = new int[size];
	readdata(array, size);
	cout << "Data : ";
	display(array, size);
	even_odd(array, size);
	
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
void even_odd(int* myarray, int size) {
	//declare the two new arrays
	int evensize = 0, odd_size = 0, num = 0;
	int* evenarr = new int[evensize];
	int* odd_arr = new int[odd_size];
	//Run the loop for check
	for (int i = 0; i < size; i++) {
		num = *(myarray + i);
		if (num% 2==0){

			*(evenarr + evensize) = *(myarray + i);
			evensize++;
		}
		else{
			*(odd_arr + odd_size) = *(myarray + i);
			odd_size++;

		}
	}
	//DISSPLAY POSITIVE &NEGATIVE ARRAY
	cout << "Positive array is: ";
	display(evenarr, evensize);
	cout << "Negative array is : ";
	display(odd_arr, odd_size);
	//free the space
	delete[]evenarr;
	delete[]odd_arr;

}

