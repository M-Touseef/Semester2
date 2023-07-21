#include<iostream>
using namespace std;
int main() {
	int rows, n;
	cin >> rows;
	int* lenght = new int[rows];
	int** dynamic_array = new int*[rows];

	for (int i = 0; i < rows; i++) {
		cout << "Enter the length of " <<i + 1 << " column ";
		cin >> n;
		lenght[i] = n;
		dynamic_array[i] = new int[rows];
	}
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < lenght[i]; j++) {
			cin>>dynamic_array[i][j];
		}
		cout << endl;
	}
	cout << "Display the value" << endl;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < lenght[i]; j++) {
			cout << dynamic_array[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}