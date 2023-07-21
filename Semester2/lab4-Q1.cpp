#include<iostream>
using namespace std;
void display(int[], int);
int main() {
	const int array_size = 5;
	int marks[array_size] = {};
	cout << "Enter the marks of 5 student" << endl;
	//use loop for take input 
	for (int i = 0; i < array_size; i++) {
		cin >> marks[i];
	}
	display(marks, array_size);
}
void display(int marks[], int size) {
	for (int i = 0; i < size; i++) {
		cout << "Marks of the Students : " << i + 1 << marks[i] << endl;
	}
}