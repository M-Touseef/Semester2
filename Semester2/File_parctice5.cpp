#include<iostream>
#include<fstream>
using namespace std;
int main() {
	fstream file;
	file.open("average.txt", ios::in);
	if (!file.is_open()) {
		cout << "File did not open sucessfully !" << endl;
	}
	else
	{
		double number = 0, i = 0, average = 0;
		double total = 0;
		while (!file.eof()) {
			file >> number;
			total = number + total;
			i++;
		}
		average = total / i;
		cout << average;
	}
	return 0;
}