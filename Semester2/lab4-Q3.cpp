#include <iostream>
using namespace std;
void sorting(char[], int);
int main() {
    int const size = 50;
    char line[size] = {};
    cin.getline(line, 50);
    sorting(line, size);
    cout << "The Line After the Sorting \n";
    for (int i = 0; i < 50; i++) {
        cout << line[i];
    }
    return 0;
}
void sorting(char line[], int size) {
    int i = 0;
    int j = size - 1;
    while (i < j) {
        if (line[i] >= 'a' && line[i] <= 'z') {
            i++;
        }
        else if (line[j] >= 'A' && line[j] <= 'Z') {
            j--;
        }
        else {
           char temp = line[i];
            line[i] = line[j];
            line[j] = temp;
            i++;
            j--;
        }
    }
}
