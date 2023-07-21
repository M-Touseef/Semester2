// Calculator Using Functions 
#include <iostream>
using namespace std;
int addition(int a, int b);
int subtraction(int a, int b);
int multiplication(int a, int b);
int division(int a, int b);

int main()
{
	int a, b;
	int choice;
	cout << "Enter the two values: " << endl;
	cin >> a >> b;
	cout << "Enter the desired option: " << endl;
	cout << "1. For addition\n";
	cout << "2. For subtraction\n";
	cout << "3. For multiplication\n";
	cout << "4. For division\n";
	cout << "Enter Your Choice FOr Calculation: " << endl;
	cin >> choice;

	switch (choice)
	{
	case 1:
		cout << "The Sum Of Two Variables Is: " << addition(a, b)<< endl;
		break;
	case 2:
		cout << "The Subtraction Of Two Variables Is:" << subtraction(a, b) << endl;
		break;
	case 3:
		cout << "The Multiplication Of Two Variables Is: " << multiplication(a, b) << endl;
		break;
	case 4:
			cout << "The Division Of Two Variables Is: " << division(a, b) << endl;
		break;
	default:
		cout << "Invalid Choice!\n";

	}
	return 0;
}
int addition(int a, int b)
{
	int total = 0;
	total = a + b;
	return total;
}

int subtraction(int a, int b)
{
	int total;
	total = a - b;
	return total;
}

int multiplication(int a, int b)
{
	int total;
	total = a * b;
	return total;

}

int division(int a, int b)
{
	int total;
	total = a / b;
	return total;
}