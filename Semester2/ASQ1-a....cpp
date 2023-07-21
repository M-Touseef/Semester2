#include <iostream>
#include <fstream>
using namespace std;
// creating an txt File and Writting Employee Codes in File
void writeEmpCodestoFile(fstream& file, int EmpCodes[], int size)
{
	file.open("EmployeeData", ios::out);
	for (int i = 0; i < size; i++)
	{
		file << EmpCodes << endl;
	}
	file.close();
}

// reading frome File and Storing Employee Codes in Array
void readEmpCodesfromFile(fstream& file, int EmpCodes[], int size)
{
	file.open("EmployeeData.txt", ios::in);
	for (int i = 0; i < size; i++)
	{
		file >> EmpCodes[i];
	}
	file.close();
}

// finding Employee Codes from Array returned by Function2 and return the index of Employee Code
int findEmpCodesfromFile(int EmpCodes[], int size, int code)
{
	for (int i = 0; i < size; i++)
	{
		if (EmpCodes[i] == code)
		{
			return i;
		}
		else
			return -99;
	}
}

// Main Body Of Code 
int main()
{
	int EmpCodes[] = { 222,223,241,233,254,211 };
	int size = sizeof(EmpCodes) / sizeof(EmpCodes[0]);
	fstream file;
	writeEmpCodestoFile(file, EmpCodes, size);
	int readEmpCodes[] = { size };
	readEmpCodesfromFile(file, readEmpCodes, size);
	int EmpCodeIndex = findEmpCodesfromFile(readEmpCodes, size, 254);
	cout << "The Employee Code 254 is at Index: " << EmpCodeIndex << endl;
	return 0;
}