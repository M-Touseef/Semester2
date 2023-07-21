#include<iostream>
#include<fstream>
using namespace std;
//All the prototypes
int* dynamic_array(int size);
void display_array(int* index, int size);
void input_array(int* index, int size);
void Pos_Neg(int* myarray, int size);
//Create Dynamic Array
int* dynamic_array(int size) {
	int* arr = new int[size];
	return arr;
}
//Take input from user in Array
void input_array(int* index, int size) {

	for (int i = 0; i < size; i++) {
		cout << "Enter value number " << i + 1 << " : ";
		cin >> *(index + i);
	}
}
//Dispaly the Array
void display_array(int* index, int size) {
	for (int i = 0; i < size; i++) {
		cout << *(index + i) << " ";
	}
}
//Use function to split the Array
void Pos_Neg(int* myarray, int size) {
	//declare the two new arrays
	int pos_size = 0, neg_size = 0;
	int* pos_arr = new int[pos_size];
	int* neg_arr = new int[neg_size];
	//Run the loop for check
	for (int i = 0; i < size; i++) {
		if (*(myarray + i) > 0) {

			*(pos_arr + pos_size) = *(myarray + i);
			pos_size++;
		}
		if (*(myarray + i) < 0) {
			*(neg_arr + neg_size) = *(myarray + i);
			neg_size++;

		}
	}
	//DISSPLAY POSITIVE &NEGATIVE ARRAY
	cout << "Positive array is: ";
	display_array(pos_arr, pos_size);
	cout <<endl<< "Negative array is : ";
	display_array(neg_arr, neg_size);
	//free the space
	delete[]pos_arr;
	delete[]neg_arr;

}

//Mian function
int main() {
	//make a variable for size and take it from user
	int array_size = 0;
	cout << "Enter the size of the Array" << endl;
	cin >> array_size;

	//Call the function to make a dynamic array
	int* first_index = dynamic_array(array_size);

	//Call the function to take input in dynamic array

	input_array(first_index, array_size);
	//Call the function to split the Array
	Pos_Neg(first_index, array_size);

	delete first_index;
	return 0;
}