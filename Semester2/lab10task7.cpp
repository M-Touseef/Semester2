#include <iostream>
using namespace std;
void display_Histogram(int*);
//Main Function
int main() {
    const int size = 10;
    int arr[size];
    cout << "Enter 10 numbers : \n";
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }
	//Call the function
	display_Histogram(arr);
	//free the Memory
	delete[]arr;
}
//Call the function
void display_Histogram(int* arr) {
	//Use for proper display on console
	cout << "Number\tHistogram\n";
    for (int i = 0; i <10; i++) {
        cout << *(arr + i) << "\t";
        for (int j = 0; j < *(arr+i); j++) {
            cout << "*";
        }
		cout << "\n";
    }
}