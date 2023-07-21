#include<iostream>
#include<fstream>
using namespace std;
int main() {
	fstream file;
	file.open("University Data.txt", ios::in | ios::out);
	if (!file.is_open()) {
		cout << "File does not found";
	}
	else
	{
		while (!file.eof()) {
			char data[200] = {};
			file.getline(data, 200);
			cout << data << endl;
		}
	}
	file.close();
	//2 part
	file.open("University Data.txt", ios::app);
	if (!file.is_open()) {
		cout << "File is not openned sucessfully!\n";
	}
	else {
		char opion[200] = {};
		file << "\nEnter Your Opinion\n";
		cout << "Enter Your Opinion\n";
		cin.getline(opion, 200);
		file << opion;
		file.close();
	}
	return 0;
}