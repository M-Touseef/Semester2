#include<iostream>
using namespace std;
void perimeter(float lenght[], int num, float& result) {
	for (int i = 0; i < num; i++) {
		cout << "Enter the lenght of the " << i + 1 << " side" << endl;
		cin >> lenght[i];
		result = result + lenght[i];
	}
}
double area(float x, float y) {
	float ar = 0;
	cout << "Enter the Lenght of the Triangle" << endl;
	cin >> x;
	cout << "Enter the Width of the Triangle" << endl;
	cin >> y;
	ar = 0.5 * x * y;
	return ar;
}
int main() {
	const int size = 3;
	float size_array[size] = {};
	float triangle_perimeter = 0,lenght = 0,width = 0;

       // call the function Pass the value by reference triangle_perimeter
	perimeter(size_array, size, triangle_perimeter);
	cout << "Perimeter of the Triangle : " << triangle_perimeter << endl;

	//Call the function to calculate the area
	cout<<"The Area of the Triangle : "<<area(lenght, width);

	return 0;
}
