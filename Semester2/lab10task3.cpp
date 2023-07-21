#include<iostream>
using namespace std;
//Mian Function
int main() {
	int size;
	cout << "Enter the size of the Array : ";
	cin >> size;
	int* arr = NULL;
	arr = new int[size];
	cout << "Enter the Array" << endl;
	//Take input from user
	for (int i = 0; i < size; i++) {
		cin >> *(arr + i);
	}
	//Display the output
	cout << "Entered Element" << endl;
	for (int i = 0; i < size; i++) {
		cout << *(arr + i) << " ";
	}
	//Free the space
	delete[]arr;
	return 0;
}