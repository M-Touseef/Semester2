#include<iostream>
#include<fstream>
using namespace std;
int readfile(int array[]) {
	fstream file;
	int i = 0;
	file.open("Integer Data.txt", ios::in);
	if (!file.is_open()) {
		cout << "Failed to open a file" << endl;
	}
	else {
		int number = 0;
		cout << "File start to read";
		while (file.eof()) {
		
			array[i] = number;
			i++;
			cout <<array[i] << " ";
		}
	}
	return i;
}
int main() {
	int array[20] = {};
	int size = 0;
	readfile(array);
	return 0;
}
