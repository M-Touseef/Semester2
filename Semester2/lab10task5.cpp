#include<iostream>
using namespace std;
int main() {
	int size;
	cout << "Enter the size of the Array :";
	cin >> size;
	cout << "Enter the Array" << endl;
	int* arr = NULL;
	arr = new int[size];
	for (int i = 0; i < size; i++) {
		cin >> *(arr + i);
	}
	int largest_element = 0;
	for (int i = 0; i < size; i++) {
		if (largest_element < *(arr + i)) {
			largest_element = *(arr + i);
		}
	}
	cout << "Largest Element : " << largest_element;
	delete[]arr;
	return 0;
}