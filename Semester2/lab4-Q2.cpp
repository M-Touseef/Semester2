#include<iostream>
using namespace std;
void display(int[], int);
int main() {
	const int size = 10;
	int marks[size] = {};
	cout << "Enter the marks of 10 student" << endl;
	for (int i = 0; i < size; i++) {
		cin >> marks[i];
	}
	//Call the function
	display(marks, size);
}
void display(int marks[], int size) {
	//use bubble sorting
	for (int i = 0; i < size; i++) {
		for (int j = i + 1; j < 10; j++) {
			if (marks[j] < marks[i]) {
				int temp = marks[i];
				marks[i] = marks[j];
				marks[j] = temp;
			}
		}
	}
	//cout the last highest index of the Array
	cout << "First, Second and Third position marks are: " << marks[size - 1] << "," << marks[size - 2] << "," << marks[size - 3];
}