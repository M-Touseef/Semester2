#include<iostream>
#include<fstream>
using namespace std;
int main() {
	int arr[10] = {};
	ifstream file;
	file.open("marks.txt");
	for (int i = 0; i < 10; i++) {
		cin >> arr[i];
		file >> arr[i];
	}
	fstream file1;
	file1.open("updatemarks.txt");
	for (int i = 0; i < 10; i++) {
		arr[i] = arr[i] - 5;
		file >> arr[i];
		cout << arr[i] << " ";
	}
	return 0;
}