#include<iostream>
#include<fstream>
using namespace std;
int read(fstream& file) {
	int total = 0, i = 0, number = 0;
	float average = 0;
	file.open("average.txt", ios::in);
	if (!file.is_open()) {
		cout << "File did not open sucessfully!\n";
	}
	else {
		while (!file.eof()) {
			file >> number;
			cout << number << " ";
			total = total + number;
			i++;
		}
		average = total / i;
		cout << "\nThe average of the data is : " << average << endl;
	}
	return average;
}
int main() {
	fstream file;
	fstream file2;
	file2.open("newfile.txt", ios::out);
	if (!file2.is_open()) {
		cout << "newfile did not open sucessfully\n";
	}
	else {
		if (read(file) > 0) {
			cout << "below average\n";
			file2 << "below average";
		}
		else if (read(file) == 4 && read(file) < 6) {
			cout << "on average\n";
			file2 << "on average\n";
		}
		else {
			cout << "above average\n";
			file2 << "above average\n";
		}
	}
	return 0;
}