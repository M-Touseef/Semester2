#include<iostream>
using namespace std;
bool palindrome(int);
int main() {
	int year;
	cout << "Enter year: ";
	cin >> year;
	if (palindrome(year)) {
		cout << "It is palindrome" << endl;
	}
	else {
		cout << "It is not palindrome" << endl;
	}
	return 0;
}
bool palindrome(int year) {
	int verify = year;
	int reverseyear = 0;
	int step1;
	while (year != 0) {
		step1 = year % 10;
		reverseyear = (reverseyear * 10) + step1;
		year = year / 10;
	}
	if (reverseyear == verify) {
		return true;
	}
	else
	{
		return false;
	}
}
