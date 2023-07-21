#include <iostream>
#include <fstream>
using namespace std;
int checkvowels(char*, int);
int main() {
    ifstream file("vowels.txt");
    if (!file.is_open() ){
        cout << "File did not found" << endl;
    }
    else {
        char line[100];
            int totalvowels = 0;
            while (!file.eof()) {
                file.getline(line, 100, ' ');
                totalvowels =totalvowels+checkvowels(line, sizeof(line));
            }
        cout << "Vowels are : " << totalvowels << endl;
            file.close();
    }
    return 0;
}
int checkvowels(char* line, int size) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (line[i] == 'a' || line[i] == 'e' || line[i] == 'i' || line[i] == 'o' || line[i] == 'u') {
            count++;
        }
        else if (line[i] == '\0') {
            break;
        }
    }
    return count;
}
