#include<iostream>
#include<fstream>
using namespace std;
int main() {
	char data[200];
	char opinion[200];
	fstream file;
	file.open("University Data.txt");
	if (!file.is_open()) {
		cout << "File does not Found";
	}
	else {
		cout << "Reading the file" << endl;
		int i = 0;
		while (1)
		{

			file.getline(data, 200);
			cout << data << endl;
			i++;
			if (file.eof()) {
				break;
			}
		}
		file.close();

		file.open("University Data.txt", ios::app);
		cout << "Enter Your Opionion" << endl;
		cin.getline(opinion, 200);
		file << endl << opinion;


	}
	file.close();
	return 0;
}