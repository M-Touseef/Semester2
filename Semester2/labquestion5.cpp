#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream File("name.txt");
    char name[100];
    int chara = 0;
    int space = 0;

    while (File.getline(name,100)) {
        for (int i = 0; name[i] != '\0'; i++) {
            chara++;
            if (name[i] == ' ') {
                space++;
            }
        }
    }

    cout << "Total characters: " << chara << endl;
    cout << "Total spaces: " << space << endl;

    File.close();
    return 0;
}
