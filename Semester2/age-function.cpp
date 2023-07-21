#include<iostream>
using namespace std;
int cal_birth(int x);
//main function
int main() {
	int birth_year;
	cout << "Enter your Birthday Year" << endl;
	cin >> birth_year;
	cout << "Your Current age is ";
	cout << cal_birth(birth_year);

}
//make function to calculate the age
int cal_birth(int x) {
	int current_year = 2023;
	int current_age = 0;
	current_age = current_year - x;
	return current_age;
}