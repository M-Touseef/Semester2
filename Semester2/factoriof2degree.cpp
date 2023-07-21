#include<iostream>
using namespace std;
void factorization(int b,int c,int&u,int&v,bool&isfactorsable) {

}
int main() {
	int coeffofx, constantterm, u, v;
	bool isPolynomialFactorable;
	cout << "Enter the coefficent of x" << endl;
	cin >> coeffofx;
	cout << "Enter the constant term" << endl;
	cin >> constantterm;
	factorization(coeffofx,constantterm,u,v, isPolynomialFactorable);
	if (isPolynomialFactorable) {
		cout << "x^2 ";

	}
}