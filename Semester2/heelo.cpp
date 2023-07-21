#include<iostream>
#include<fstream>
using namespace std;
int main() {
    ofstream file("address.txt");
    if (file.is_open()) {
        file << "Alyan: Khayaban-e-Jinnah, UCP: 030012345678" << endl;
        file << "John: Main Street, UOL: 03211234567" << endl;
        file << "Sarah: Liberty Road, PU: 03451234567" << endl;
        file << "Michael: Canal Bank, NUST: 03121234567" << endl;
        file << "Emma: Model Town, FAST: 03331234567" << endl;

        file.close();
        cout << "File created successfully!" << endl;
    }
    else {
        cout << "Failed to create file!" << endl;
    }
    file.close();
    ifstream fin;
    fin.open("address.txt");
    char name[20] = { }, address[30] = {  }, number[11] = {  };
    while (!fin.eof())
    {
        fin.ignore();
        fin.getline(name,50, ':');
        fin.ignore();
        fin.getline(address,50, ':');
        for (int i = 0; i < 11; i++)
        {
            fin >> number[i];
        }
        if (number[0] == '0' && number[1] == '3' && number[2] == '0' && number[3] == '0')
        {
            cout << name << ": " << address<< ": ";
            for (int j = 0; j < 11; j++) {
                cout << number[j];
            }
            cout << endl;
        }
    }
    fin.close();
    return 0;

}
