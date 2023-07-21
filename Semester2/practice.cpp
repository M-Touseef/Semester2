#include<iostream>
#include<fstream>
using namespace std;

int main()
{
    char name[50], address[100], number[100];
    fstream file("address.txt", ios::out);

    for (int i = 0; i < 5; i++)
    {
        cout << "Enter student name: ";
        cin.getline(name, 50, ':');
        file << name;
        cout << "Enter student address: ";
        cin.getline(address, 100, ':');
        file << address;
        cout << "Enter student phone number: ";
        cin.getline(number, 100);
        file << number;
    }
    file.close();
}