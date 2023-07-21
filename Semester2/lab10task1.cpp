#include <iostream>
using namespace std;
void findFact(int*, int*);
//Main Function
int main()
{
    int number, factorial;
    cout << "Enter the number to find factorial of : ";
    cin >> number;
   //Call the function
    findFact(&number, &factorial);
    cout << "The factorial of " << number << " is: " << factorial << endl;
    return 0;
}
//Call the function for factorial
void findFact(int* number, int*factor)
{
    *factor = 1;
    for (int i = 1; i <= *number; i++) {
        *factor *= i;
    }
}