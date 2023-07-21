#include<iostream>
#include<fstream>

using namespace std;

int main() {
	char lenght[10];
	fstream file;
	file.open("Name1.txt", ios::in);
	if (!file.is_open()) {
		cout << "Failed to open a file " << endl;
	}
	else {
		int i = 0;
		while (!file.eof()) {
			file.getline(lenght, 10);
			i++;
		}
		cout << i;
		int** arr = new int* [i];
	}
	return 0;
}