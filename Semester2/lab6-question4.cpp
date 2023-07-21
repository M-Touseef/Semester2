#include <iostream>
#include <fstream>
using namespace std;
int vowelscounter(char check) {
        if (check== 'a'||check== 'e'||check== 'i'||check== 'o'||check== 'u')
            {
            return 1;
        }
        else {
            return 0;
        }
}

int main() {
    fstream file;
    file.open("vowels.txt",ios::in);
    if (!file.is_open()) {
        cout << "File did not open sucessfully !" << endl;
    }
    else {
        char check;
        int vowels = 0;
        while (!file.eof()) {
            file >> check;
            vowels = vowelscounter(check) + vowels;
        }
        cout << "Vowels are : " << vowels << endl;

        file.close();
    }
    return 0;
}
