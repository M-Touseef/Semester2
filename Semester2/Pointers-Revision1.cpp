#include<iostream>
using namespace std;
/*
* Pointers are variable that store the adddress of the other variable
* Different datatypes we have different pointers
* int a , int*ptr=&a; char c; char*ptr;
*/
int main() {
	int a;
	cin >> a;
	int* ptr = NULL;
	ptr = &a;
	//ptr and &a  and &ptr give the address of the value
	cout << &ptr;
	// replace the value like *ptr=9;
	return 0;
}