#include<iostream>
#include<fstream>
using namespace std;
int main() {
	fstream file;
	file.open("marks.txt", ios::in);
		if (!file.is_open()) {
			cout << "File does not found";
		}
		else {
			fstream file_2;
			file_2.open("updatemarks.txt", ios::out);
				if (!file_2.is_open()) {
					cout << "The new file does not create successfully!";
				}
				else {
					while (!file.eof()) {
						char name[50] = {};
						int marks = 0;
						file.getline(name, 50, ':');
						file_2 << name;
						file >> marks;
						file_2 << marks + 5;
					}
					cout << "marks are successfully updated!" << endl;
				}
			
		}
		return 0;
}