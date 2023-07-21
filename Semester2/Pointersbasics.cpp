#include<iostream>
using namespace std;
int main() {
	int a = 5;
	int*ptr1 = NULL;
	ptr1 = &a;
	cout << ptr1 << endl;
	cout << &a << endl;
	//display variale
	cout << *ptr1 << endl;
	cout << a;
	return 0;
}