#include<iostream>
#include<fstream>
using namespace std;
int main() {
	fstream file;
	file.open("integer.txt",ios::in);
		if (!file.is_open()) {
			cout << "File did not open sucessfully\n";
		}
		else {
			int count = 0;
			int number = 0;
			while (!file.eof()) {
				file>>number;
				count++;
			}
			cout << "The Total Number of the Entries is " << count;
		}
		return 0;
}