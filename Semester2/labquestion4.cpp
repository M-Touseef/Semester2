#include<iostream>
#include<fstream>
#include<iomanip>
using namespace std;
int main()
{
	char waste;
	int age;
	float cgpa;
	char name[50];
	ifstream file;
	file.open("sample data.txt");
	if (file.is_open()) {
		ofstream file_age,file_cgpa,file_name;
		file_age.open("age.txt");
		file_cgpa.open("cgpa.txt");
		file_name.open("name.txt");
		cout << "Name";
		for (int i = 0; i < 6; i++)
		{
			file.ignore();
			file.getline(name, 50, '@');
			file >> age;
			file >> waste;
			file >> cgpa;
			file_name << name;
			file_age << age;
			file_cgpa<< cgpa;

			cout << name <<setw(10+i) << age << "  " << cgpa << endl;
		}
		file.close();
		file_age.close();
		file_cgpa.close();
		file_name.close();
	}
	else {
		cout << "File does not found";
	}
	return 0;
}
