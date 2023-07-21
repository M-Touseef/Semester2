#include<iostream>
#include<fstream>

using namespace std;
int* regrow1D(int* oldarray, int s, int value);
void copyarray(int* new_array, int* old_array, int size);
void display(int* array, int size);

int main() {
	int size = 0;
	int* array = new int[1];
	ifstream file("Check.txt");
	int num;
	file >> num;
	array[0] = num;  // Corrected array index
	while (file >> num) {
		size++;
		array = regrow1D(array, size, num);
	}
	display(array, size);
	delete[] array;  // Free memory allocated by new[]
}

// Regrow Array
int* regrow1D(int* oldarray, int s, int value) {
	int* newarray = new int[s + 1];
	copyarray(newarray, oldarray, s);
	newarray[s] = value;
	delete[] oldarray;
	return newarray;
}

// Copy array
void copyarray(int* new_array, int* old_array, int size) {
	for (int i = 0; i < size; i++) {
		*(new_array + i) = *(old_array + i);
	}
}

// Display
void display(int* array, int size) {
	for (int i = 0; i < size; i++) {
		cout << array[i] << " ";  // Added a space after each element
	}
	cout << endl;  // Added a newline character at the end
}
