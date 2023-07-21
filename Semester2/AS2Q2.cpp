#include<iostream>
using namespace std;
void calculatePerimeter(int sides[], int size,int&perimeter)
{
	for (int i = 0; i <size; i++)
	{
		cin >> sides[i];
		perimeter = sides[i] + perimeter;
	}
}
double calculatearea(float length, float width)
{
	cout << "Enter the Width and Lenght of Triangle" << endl;
	cin >> length >> width;
	double area = 0.5*length * width;
	return area;
}
int main()
{
	int const size = 3;
	int sides[size] = { 1, 2, 3 };
	float length =1;
	float width = 1;
	int perimeter = 0;
	calculatePerimeter(sides, size, perimeter);
	cout << "Perimeter of triangle with sides 1, 2, 3 is " <<perimeter<< endl;
	double area = calculatearea(length, width);
	cout << "Area of triangle " << area << endl;
	return 0;
}