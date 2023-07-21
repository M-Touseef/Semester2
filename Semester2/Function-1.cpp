#include<iostream>
using namespace std;
/*The first four properties form what we called heading of the function
 and the fifth property is called the body of the function
and these all properties caled definition of the function.*/

int higher(int, int);
//function type ,function name(parameters data types)

int main() {
	/*To use function we must know 4 things
	1. The name of the Function
	2. The parameters of the Function(if any)
	3. The Data Type of each function
	4. The data type of the value computed (that is,the value returned)
	by the fuction called type of the function
	5. The code required to accomplish the tasks
	*/
	int num_1, num_2, max;
	max = 0;
	cin >> num_1 >> num_2;
	max = higher(num_1, num_2);
	if(max!=0)
	cout << max << " is the maximum number\n";
	

	return 0;
}
//function type function name (formal parameters lists)
int higher(int x, int y) {
	//int x and int y are formal variable
	//first formal variable=first acutal variable and so on
	if (x != y) {
		if (x > y) {
			return x;
		}
		else
			return y;
		//return type of y is same as function type
	}
	else
		cout<<"Both numbers are equal\n";
	return 0;
}