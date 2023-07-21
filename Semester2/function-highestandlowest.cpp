#include<iostream>
using namespace std;
int higher(int, int, int);
int lowest(int, int, int);
int main() {
	int num1, num2, num3;
	cout << "Enter the Marks " << endl;
	cin >> num1 >> num2 >> num3;
	cout << "Highest marks is " << higher(num1, num2, num3) << endl;
	cout << "Lowest marks is " << lowest(num1, num2, num3) << endl;

	return 0;
}
int higher(int x, int y, int z) {
	if (x > y && x > z) {
		return x;
	}
	else if (y > x && y > z) {
		return y;
	}
	else if (z > x && z > y) {
		return z;
	}
}
int lowest(int x, int y, int z) {
	if (x < y && x < z) {
		return x;
	}
	else if (y < x && y < z) {
		return y;
	}
	else if (z < x && z < y) {
		return z;
	}
}