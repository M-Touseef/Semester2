#include <iostream>
#include <fstream>

using namespace std;
//Prototypes of the function

int getLength(char* str) {
    int length = 0;
    while (str[length] != '\0') {
        ++length;
    }
    return length;
}

void copyCharArray(char* dest, char* src) {
    int i = 0;
    while (src[i] != '\0') {
        dest[i] = src[i];
        ++i;
    }
    dest[i] = '\0';
}

void initializeArray(char**& array, int size) {
    array = new char* [size];
    for (int i = 0; i < size; ++i) {
        array[i] = nullptr;
    }
}

void deallocateArray(char**& array, int size) {
    for (int i = 0; i < size; ++i) {
        delete[] array[i];
    }
    delete[] array;
    array = nullptr;
}

void resizeArray(char**& array, int& size, int newSize) {
    char** temp;
    initializeArray(temp, newSize);

    for (int i = 0; i < size; ++i) {
        int nameLength = getLength(array[i]);
        temp[i] = new char[nameLength + 1];
        copyCharArray(temp[i], array[i]);
        delete[] array[i];
    }

    deallocateArray(array, size);
    array = temp;
    size = newSize;
}

void readNames(char**& names, int& numNames, int& size, std::ifstream& fin) {
    char name[100];
    while (fin >> name) {
        if (numNames == size) {
            int newSize = size * 2;
            resizeArray(names, size, newSize);
        }

        int nameLength = getLength(name);
        names[numNames] = new char[nameLength + 1];
        copyCharArray(names[numNames], name);
        ++numNames;
    }
}

void printNames(char** names, int numNames) {
    std::cout << "Names read from the file:" << std::endl;
    for (int i = 0; i < numNames; ++i) {
        std::cout << names[i] << std::endl;
    }
}

void readNamesFromFile(char* filename) {
    std::ifstream fin(filename);

    if (!fin) {
        std::cout << "Failed to open the file." << std::endl;
        return;
    }

    int numNames = 0;
    int size = 5;

    char** names;
    initializeArray(names, size);

    readNames(names, numNames, size, fin);

    fin.close();

    printNames(names, numNames);

    deallocateArray(names, size);
}

int main() {
    char filename[] = "names.txt";
    readNamesFromFile(filename);
    return 0;
}

