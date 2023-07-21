#include<iostream>
#include<fstream>
using namespace std;
void display(fstream& file);
void add(fstream& file);
int main() {
	fstream file;
	int choice;
	cout << "Press 1 to display employee data" << endl << "Press 2 to add new employee data" << endl;
	cin >> choice;
	if (choice == 1) {
		display(file);
	}
	else if (choice == 2) {
		add(file);
	}
	else
		cout << "Command does not Found";
	return 0;
}
void display(fstream& file) {
	//open the file with IOS flag
	file.open("employee.txt", ios::in);
	if (!file.is_open()) {
		cout << "File does not found" << endl;
	}
	else {
		char name[20] = {};
		char age[5] = {}; char id[5] = {}; char phone_number[11] = {};
		while (!file.eof()) {
			file.getline(name, 20, ' ');
			cout << name << " ";
			file.getline(age, 5, ' ');
			cout << age << " ";
			file.getline(id, 5, ' ');
			cout << id << " ";
			file.getline(phone_number, 11);
			cout << phone_number << endl;
		}
		file.close();
	}
}
void add(fstream& file) {
	//open file with proper ios flag & Error handling
	file.open("employee.txt", ios::app);
	if (!file.is_open()) {
		cout << "File does not found" << endl;
	}
	else {
		char name[20] = {};
		char age[5] = {}; char id[5] = {}; char phone_number[11] = {};
		cout << "Enter the Data" << endl;
		cout << "Enter the Name of the Employee" << endl;
		cin.ignore();
		cin.getline(name, 20);
		file << endl << name <<" ";
		cout << "Enter the Age of the Employee" << endl;
		cin.getline(age, 5);
		file << age << " ";
		cout << "Enter the ID of the Employee" << endl;
		cin.getline(id, 5);
		file << id << " ";
		cout << "Enter the Number of the Employee" << endl;
		cin.getline(phone_number, 11);
		file << phone_number << endl;
		file.close();
	}
}