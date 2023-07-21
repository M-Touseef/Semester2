#include<iostream>
#include<fstream>
using namespace std;
int main() {
	int integer;
	int count = 0;
	fstream file;
	file.open("Integer.txt", ios::in);
	if (!file.is_open()) {
		cout << "File does not Found";
	}
	else {
		cout << "Reading the file" << endl;
		while (1)
		{
			file >> integer;
			count++;
			if (file.eof()) {
				break;
			}
		}

		cout << count;

	}
	return 0;
}