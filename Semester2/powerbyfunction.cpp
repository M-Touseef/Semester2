#include<iostream>
using namespace std;
int power(int base, int exponent) {
	int x = base;
	for (int i = 1; i < exponent; i++) {
		x =base* x;
	}
	return x;
}
//Main Function
int main() {
	int base, exponent;
	cout << "Enter the base of the expression" << endl;
	cin >> base;
	cout << "Enter the exponent of the base" << endl;
	cin >>exponent;
	cout << "The result of the expression is : "<<power(base, exponent) << endl;
	return 0;
}