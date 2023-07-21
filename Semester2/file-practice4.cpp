#include<iostream>
#include<fstream>
using namespace std;
int main() {
	fstream file;
	file.open("sample data.txt", ios::in);
		if (!file.is_open()) {
			cout << "Failed to open the file!";
		}
		else {
			cout << "Name" << "   " << "Age" << "   " << "CGPA";
			fstream file1;
			fstream file2;
			fstream file3;
			file1.open("name.txt", ios::out);
			file2.open("age.txt", ios::out);
			file3.open("cgpa.txt", ios::out);
			char name[25] = {};
			int age = 0;
			float cgpa = 0;
			char waste = 0;
			while (!file.eof()) {
				file.getline(name,25, '@');
				file1 << name;
				
				file >> age;
				file2 << age;
				
				file >> waste;
				file >> cgpa;
				file3 << cgpa;
				cout << name<<"  "<< age << " " << cgpa;
			}

		}
		return 0;
}