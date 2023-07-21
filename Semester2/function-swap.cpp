#include<iostream>
using namespace std;
//header of swapping function
void swap(int& n1, int& n2);
int main() {
	int num_1, num_2;
	cout << "Enter the value of num_1 " << endl;
	cin >> num_1;
	cout << "Enter the value of num_2 " << endl;
	cin >>num_2;
	//use function for swapping
	swap(num_1,num_2);
	cout << "num_1 = " << num_1 << endl;
	cout << "num_2 = " << num_2 << endl;
	return 0;
}
//swaping function
void swap(int& n1, int& n2) {
	int temp;
	temp = n1;
	n1 = n2;
	n2 = temp;
}