#include<iostream>
#include<fstream>
using namespace std;
//All the prototypes
double* dynamic_array(int size);
void displayInformation(double*, int, int);
void getArrayElements(double*, int);
int calculateAverage(double*, int);
//Create Dynamic Array
double* dynamic_array(int size) {
	double *arr = new double[size];
	return arr;
}
//Take input from user in Array
void getArrayElements(double* index, int size) {

	for (int i = 0; i < size; i++) {
		cout << "Enter sale of day " << i + 1 << " : ";
		cin >> *(index + i);
	}
}
//Dispaly the Array
void displayInformation(double* index, int size,int avg) {
	for (int i = 0; i < size; i++) {
		cout << "Sale of day 1 is : $" << *(index + i) << endl;
	}
	cout << endl<<"Average is :: " << avg;
}
//Calculate avg
int calculateAverage(double* array, int size) {
	int average = 0, total = 0;
	for (int i = 0; i < size; i++) {
		total += *(array + i);
	}
	average = total / size;
	return average;
}

//Mian function
int main() {
	//make a variable for size and take it from user
	int array_size = 0;
	cout << "How many days of sale do you want to process ?" << endl;
	cin >> array_size;

	//Call the function to make a dynamic array
	double* first_index = dynamic_array(array_size);

	//Call the function to take input in dynamic array

	getArrayElements(first_index, array_size);

	//Call the function for Average
	int salary_avg=calculateAverage(first_index, array_size);

	//Dispaly Array Elements
	displayInformation(first_index,array_size,salary_avg);

	delete first_index;
	return 0;
}