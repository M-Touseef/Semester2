#include <iostream>
using namespace std;
void sortLowerUpperCase(char str[], int size) {
    char temp;
    for (int i = 0, j = size - 1; i < j;) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            i++;
        }
        else if (str[j] >= 'A' && str[j] <= 'Z') {
            j--;
        }
        else {
            temp = str[i];
            str[i] = str[j];
            str[j] = temp;
            i++;
            j--;
        }
    }
}
int main() {
    int const size = 50;
    char str[size] = {};
    cin.getline(str,50);
    sortLowerUpperCase(str,size);

    for (int i = 0; i < 50; i++) {
        cout<<str[i];
    }
    return 0;
}

