#include<iostream>
using namespace std;
int positive_integer(int number) {
	if (number > 0) {
		return 1;
	}
	else {
		return 0;
	}
}
int main() {
	int const size = 10;
	int array[size] = {};
	int count = 0;
	cout << "Enter the number to store in Array" << endl;
	for (int i = 0; i < size; i++) {
		cin >> array[i];
		int number = array[i];
		if (positive_integer(number) == 1) {
			count++;
		}
	}
	cout << "Total positive number enter by user : " << count << endl;
	return 0;
}