#include<iostream>
using namespace std;
int palindrome(int number) {
	int check = number;
	int div, reverseyear = 0;
	while (number != 0) {
		div = number % 10;
		reverseyear = (reverseyear * 10) + div;
		number = number / 10;
	}
	if (reverseyear == check) {
		return 1;
	}
	else
		return 0;
}
int main() {
	int year;
	cout << "Enter the year you want to check : " << endl;
	cin >> year;
	if (palindrome(year) == 1) {
		cout << "The Year is palindrome" << endl;
	}
	else {
		cout << "The Year is not palindrome" << endl;
	}
	return 0;
}