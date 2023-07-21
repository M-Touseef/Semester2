#include<iostream>
using namespace std;
//header files of fuctions
int  calculator(int a, int b);
int sum(int a, int b);
int subtraction(int a, int b);
int multiplication(int a, int b);
int division(int a, int b);
//Main function
int main() {
	int num1, num2;
	cin >> num1 >> num2;
	//call function calculator
	cout << calculator(num1, num2);
}
int sum(int a, int b) {
	int total = 0;
	total = a + b;
	return total;
}
int subtraction(int a, int b) {
	int total = 0;
	total = a - b;
	return total;
}
int multiplication(int a, int b) {
	int total = 0;
	total = a * b;
	return total;
}
//use function for division
	int division(int a, int b) {
	int total = 0;
	total = a / b;
	return total;
}
	//use calculator  function to call multiple function
int  calculator(int x, int y) {
	char choice;
	int ans = 0;
	cout << "Enter the operator" << endl;
	//ask user about the operator
	cin >> choice;
	if (choice == '+') {
		ans = sum(x, y);
		return ans;
	}
	else	if (choice == '-') {
		ans = subtraction(x, y);
		return ans;
	}
	else if (choice == '*') {
		ans = multiplication(x, y);
		return ans;
	}
	else if (choice == '/') {
		ans = division(x, y);
		return ans;
	}
	else
		cout << "Operator is undefined";
}