#include<iostream>
using namespace std;
//Main Function
int main() {
	int size;
	cout << "Enter the size of the Array : ";
	cin >> size;
	cout << "Entered " << size << " integers numbers" << endl;
	int* arr = NULL;
	arr = new int[size];
	//Take input from users
	for (int i = 0; i < size; i++) {
		cin >> *(arr + i);
	}
	int sum = 0;
	//Calculate the sum
	for (int i = 0; i < size; i++) {
		sum += *(arr + i);
	}
	cout << "Total Sum : " << sum;
	//free the space
	delete[]arr;
	return 0;
}