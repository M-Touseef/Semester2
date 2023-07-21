#include<iostream>
#include<fstream>
using namespace std;
int main() {
	//use proper ios flag and error handling
	fstream file("address.txt", ios::out);
	if (file.is_open()) {
		// Write 5 lines 
		file << "Ali:Johar Town ,Lahore :030012345678\n";
		file << "Ahmad:Wapda Town,Lahore : 03012345678\n";
		file << "Muhammad Ali:Abcdef,Lahore : 03559876541\n";
		file << "Ahmad Hassan: Allama Iqbal Town,Lahore : 03213456789\n";
		file << "Justin : Raiwand,Lahore : 03101234567\n";
		file.close();
		cout << "File created successfully" << endl;
	}
	else {
		cout << "Failed to create file!" << endl;
	}
	//Serach the contact
	file.open("address.txt",ios::in);
	if (!file.is_open()) {
		cout << "Failed to open the file!" << endl;
	}
	else {
		char name[20] = { }, address[30] = { }, number[11] = { };
		while (!file.eof())
		{
			file.getline(name,50, ':');
			
			file.getline(address,100, ':');
			for (int i = 0; i < 11; i++)
			{
				file >> number[i];
			}
			if (number[0] == '0' && number[1] == '3' && number[2] == '0' && number[3] == '0')
			{
				cout << name << ": " << address<< ": ";
				for (int j = 0; j < 11; j++) {
					cout << number[j];
				}
				cout << endl;
			}
		}
		file.close();

	}
	return 0;
}