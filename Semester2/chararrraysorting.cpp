#include <iostream>

void bubbleSort(char* charArray, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (charArray[j] > charArray[j + 1]) {
                // Swap characters
                char temp = charArray[j];
                charArray[j] = charArray[j + 1];
                charArray[j + 1] = temp;
            }
        }
    }
}

int main() {
    const int size = 10;
    char charArray[size] = { 'z', 'a', 'g', 'b', 'f', 'c', 'e', 'd', 'h', 'y' };

    bubbleSort(charArray, size);

    for (int i = 0; i < size; i++) {
        std::cout << charArray[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
