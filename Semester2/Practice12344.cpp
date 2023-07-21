#include <iostream>
#include <fstream>

using namespace std;

int main() {
    char type;
    string name;
    int id;
    int age;
    int phone;

    cout << "Enter patient type (indoor/outdoor): ";
    cin >> type;

    if (type == 'i') {
        cout << "Enter patient name: ";
        cin >> name;
        cout << "Enter patient ID card number: ";
        cin >> id;
        cout << "Enter patient age: ";
        cin >> age;
        cout << "Enter patient phone number: ";
        cin >> phone;

        ofstream outfile("inpatient.txt", ios::app);
        outfile << name << " " << id << " " << age << " " << phone << endl;
        outfile.close();
    }
    else if (type == 'o') {
        cout << "Enter patient name: ";
        cin >> name;
        cout << "Enter patient ID card number: ";
        cin >> id;
        cout << "Enter patient age: ";
        cin >> age;
        cout << "Enter patient phone number: ";
        cin >> phone;

        ofstream outfile("outpatient.txt", ios::app);
        outfile << name << " " << id << " " << age << " " << phone << endl;
        outfile.close();
    }
    else {
        cout << "Invalid patient type." << endl;
    }

    return 0;
}
