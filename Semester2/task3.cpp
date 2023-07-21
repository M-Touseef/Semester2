#include<iostream>
#include<fstream>
using namespace std;
int read(fstream& fout);
int main() {
	fstream file;
	fstream fin;
	fin.open("newfile.txt", ios::out);
	if (!fin.is_open()) {

		cout << "newfile did not open sucessfully" << endl;
	}
	else {
		int result = read(file);
		if (result > 0 && result < 4) {
			fin << "below average" << endl;
		}
		else if (result == 4 && result < 6) {
			fin << "on average" << endl;
		}
		else {
			fin << "above average" << endl;
		}
	}
	return 0;
}
int read(fstream& fout) {
	int total = 0;
	float average = 0;
	int i = 0;
	int number = 0;
	fout.open("average.txt");
	if (!fout.is_open()) {
		cout << "File did not open sucessfully!" << endl;
	}
	else {
		while (!fout.eof()) {
			fout >> number;
			cout << number << " ";
			total = total + number;
			i++;
		}
		average = total / i;
		cout << "The average of the data is : " << average << endl;
	}
	return average;
}
