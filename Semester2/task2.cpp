#include<iostream>
using namespace std;
int integercheck(int);
int main() {
	int const size = 10;
	int array[10] = {0};
	int count = 0;
	for (int i = 0; i < size; i++) {
		cin >> array[i];
	}
	for (int j = 0; j < size; j++) {
		int number = array[j];
		if (integercheck(number) == 1) {
			count++;
		}
	}
	cout << "Total positive number enter by user : " << count << endl;
	return 0;
}
int integercheck(int number) {
	if (number > 0) {
		return 1;
	}
	else {
		return 0;
	}
}