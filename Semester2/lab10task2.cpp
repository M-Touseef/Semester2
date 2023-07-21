#include <iostream>
using namespace std;
int Lenght_calculate(char* str);
//Main Function
int main() {
    const int size=50;
    char str[50];
    cout << "Enter string : ";
    cin.getline(str,50);
    //Call the function
    int length = Lenght_calculate(str);
    cout << "The size of array " << str << " is : " << length << endl;
    return 0;
}
//Lenght calculate Function
int Lenght_calculate(char* str) {
    int length = 0;
    while (*str != '\0') {
        length++;
        str++;
    }
    return length;
}