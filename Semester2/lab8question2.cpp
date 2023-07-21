#include <iostream>
#include <fstream>
using namespace std;
void frequency(int arr[], int size);
//Main Function
int main()
{
	fstream file;
	file.open("Integer Data.txt",ios::in);
	if (!file.is_open()) {
		cout << "File did not open sucessfully !" << endl;
	}
	else {
		int array[100] = {};
		int size = 0;
		file >> size;
		for (int i = 0; i != ' '; i++)
			file >> array[i];
		frequency(array, size);
	}
	
	return 0;
}
void frequency(int arr[], int size)
{
	bool check[100] = { false };
	int count = 1, counter = 0;
	for (int i = 0; i < size; i++)
	{
		if (check[i])
			continue;
		count = 1;
		for (int j = i + 1; j < size; j++)
			if (arr[i] == arr[j])
			{
				count++;
				check[j] = true;
			}
		if (count > counter)
			counter = count;
	}
	cout << "The Most Occurring number is : " << counter << endl;
}