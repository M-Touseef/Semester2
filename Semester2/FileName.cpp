#include<iostream>
#include <fstream>
using namespace std;
int main()
{
	ofstream fout1, fout2, fout3;
	ifstream fin;
	fin.open("sample data.txt");
	char name[200];
	float CGPA;
	int age;
	for (int i = 0; i < 5; i++) {
		fin >> age;
		fin >> CGPA;
		fin.ignore();
		fin.getline(name, 200);
		fout1 << age << endl;
		cout << age << " ";
		fout2 << CGPA << endl;
		cout << CGPA << " ";
		fout3 << name << endl;
		cout << name << " ";
	}
	fout1.close();
	fout2.close();
	fout3.close();


	return 0;
}
