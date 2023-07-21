/*#include<iostream>
#include<fstream>
using namespace std;
int main() {
    // Use character arrays
    char name[50], address[100], number[11];
    // Open the file with ios flags
    fstream file("address.txt", ios::out);
    if (!file.is_open()) {
        cout << "Failed to open the file!" << endl;
    }
    else {
        for (int i = 0; i < 5; i++) {
            cout << "Enter student " << i + 1 << " name: ";
            // Read name
            cin.getline(name, 50, ':');
            cout << "Enter student " << i + 1 << " address: ";
            // Read address
            cin.getline(address, 100, ':');
            cout << "Enter student " << i + 1 << " phone number: ";
            // Read phone number
            cin.getline(number, 11);
            cin.ignore();
            file << name << ":" << address << ":" << number << endl;

        }

        // Close the file
        file.close();
    }

    // Open the file again for reading and error handling
    file.open("address.txt", ios::in);
    if (!file.is_open()) {
        cout << "Failed to open the file!" << endl;
    }
    else {
        // Read the file and display student data whose phone number starts with 0300
        int i = 0;
        while (i<5) {
            file.getline(name, 50, '\n');
            cin.ignore(

            );
            file.getline(address, 100, '\n');
            file.getline(number, 11);
            i++;
            // Check if the phone number
            if (number[0] == '0' && number[1] == '3' && number[2] == '0' && number[3] == '0') {
                cout << "Name: " << name << " Address: " << address << " Phone number: " << number << endl;
            }
        }

        // Close the file
        file.close();
    }

    return 0;
}
*/