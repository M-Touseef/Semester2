#include <iostream>
#include <fstream>
using namespace std;
int main() {
	char name[50];
	char address[50];
	int phone_number = 0;
	ifstream fin;
	fin.open("address.txt", ios::in);
	for (int i = 0; i < 5; i++) {
		cout << "Enter the Name of the Student" << endl;
		fin >> phone_number;
	
	}
	fin.close();
}