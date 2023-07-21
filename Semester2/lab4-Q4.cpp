#include<iostream>
#include<fstream>
using namespace std;
void write(fstream&,int);
void read(fstream&, int[], int);
int main() {
	const int size = 10;
	int temp = 0;
	int number[size] = {};
	fstream file;
	//open file and use proper ios flag
	file.open("rollnumber.txt",ios::in);
	//File open error handling
	if (!file.is_open()) {
		cout << "file does not found" << endl;
	}
	else {
		fstream evenfile, oddfile;
		read(file, number, size);
		evenfile.open("even rollnumbers.txt",ios::out);
		oddfile.open("odd rollnumbers.txt",ios::out);
		for (int i = 0; i < size; i++) {
			if (number[i] % 2 == 0) {
				temp = number[i];
				write(evenfile, temp);
			}
			else if (number[i] % 2 == 1) {
				temp = number[i];
				write(oddfile, temp);
			}
		}
		cout << "Tasks is done Sucessfully!" << endl;
		file.close();
	}
}
void write(fstream&file, int num){
	//save data in the file which one is call
	file << num << endl;
}
void read(fstream& file, int data[], int size)
{
	//read the data from file into arr
	int i = 0;
	while (!file.eof())
	{
		file >> data[i];
		i++;
	}
}