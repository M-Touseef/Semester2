#include<iostream>
#include<fstream>
using namespace std;
//All the prototypes
int* dynamic_array(int size);
void display_array(int* index, int size);
void input_array(int* index, int size);
void square_array(int* index, int size);
//Create Dynamic Array
int* dynamic_array(int size) {
	int* arr = new int[size];
	return arr;
}
//Take input from user in Array
void input_array(int* index, int size) {
	cout << "Enter array elements : " << endl;
	for (int i = 0; i < size; i++) {
		cin>> *(index + i);
	}
}
//Dispaly the Array
void display_array(int* index, int size) {
	cout << "Updated data :";
	for (int i = 0; i < size; i++) {
		cout << *(index + i) << " ";
	}
}
//Make function to upgrade the value of array
void square_array(int* index, int size) {
	for (int i = 0; i < size; i++) {
		*(index + i) = *(index + i) * *(index + i);
	}
}
//Mian functionj
int main() {
	//make a variable for size and take it from user
	int array_size= 0;
	cout << "Enter the size of the Array" << endl;
	cin >> array_size;

	//Call the function to make a dynamic array
	int* first_index = dynamic_array(array_size);

	//Call the function to take input in dynamic array

	input_array(first_index, array_size);
	//Call the function to upgrade value in dynamic array

	square_array(first_index, array_size);
	//Call the function for display

	display_array(first_index, array_size);
	delete first_index;
	return 0;
}