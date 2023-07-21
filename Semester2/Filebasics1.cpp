#include <iostream>
//libaray use for file is fstream
#include <fstream>
using namespace std;
int main() {
	//fstream to create a file.name data and type txt
	ofstream file("data.txt",ios::in);
	if (file.is_open()) {
		file << "All is good" << endl;
		file.close();
		cout << "File is sucessfully created";
	}
	else
	{
		cout << "File does not create sucessfully";
	}
	return 0;
}