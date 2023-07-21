#include<iostream>
using namespace std;
int factorial_cal(int number) {
	int factorial = 1;
	for (int i = 1; i <= number; i++) {
		factorial = factorial * i;
	}
	return factorial;
}
//Main Function
int main() {
	int number = 0;
	cout << "Enter the number whose factorial you want" << endl;
	cin >> number;
	cout << "The factorial of the " << number << " is : " << factorial_cal(number) << endl;
}