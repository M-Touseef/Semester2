#include <iostream>

void printArray(int** arr, int numRows) {
    for (int i = 0; i < numRows; ++i) {
        int j = 0;
        while (arr[i][j] != 0) {
            std::cout << arr[i][j] << "\t";
            ++j;
        }
        std::cout << std::endl;
    }
}

void shiftElementsRight(int** arr, int row, int col) {
    int j = 0;
    while (arr[row][j] != 0) {
        ++j;
    }

    for (int i = j; i > col; --i) {
        arr[row][i] = arr[row][i - 1];
    }
}

void shiftElementsLeft(int** arr, int row, int col) {
    int j = 0;
    while (arr[row][j] != 0) {
        ++j;
    }

    for (int i = col; i < j - 1; ++i) {
        arr[row][i] = arr[row][i + 1];
    }
}

void insertNumber(int** arr, int& numRows, int row, int number) {
    if (row >= 0 && row < numRows) {
        int col = 0;
        while (arr[row][col] != 0) {
            ++col;
        }

        shiftElementsRight(arr, row, col);
        arr[row][col] = number;
    }
    else {
        std::cout << "Invalid row!" << std::endl;
    }
}

void removeNumber(int** arr, int& numRows, int row) {
    if (row >= 0 && row < numRows) {
        int col = 0;
        while (arr[row][col] != 0) {
            ++col;
        }

        if (col == 0) {
            std::cout << "Row is already empty!" << std::endl;
        }
        else {
            shiftElementsLeft(arr, row, col - 1);
            arr[row][col - 1] = 0;

            if (col == 1) {
                // If the row becomes empty, shift the rows up
                for (int i = row; i < numRows - 1; ++i) {
                    arr[i] = arr[i + 1];
                }
                --numRows;
            }
        }
    }
    else {
        std::cout << "Invalid row!" << std::endl;
    }
}

int main() {
    int** arr = nullptr;
    int numRows = 0;

    char option;
    int row, number;

    while (std::cin >> option) {
        if (option == 'a') {
            std::cin >> row >> number;

            // Resize the array
            int** temp = new int* [numRows + 1];
            for (int i = 0; i < numRows; ++i) {
                temp[i] = arr[i];
            }
            delete[] arr;
            arr = temp;

            arr[numRows] = new int[100];
            insertNumber(arr, numRows, row, number);
            ++numRows;
        }
        else if (option == 'r') {
            std::cin >> row;
            removeNumber(arr, numRows, row);
        }
        else {
            std::cout << "Invalid option!" << std::endl;
            continue;
        }

        printArray(arr, numRows);
        std::cout << std::endl;
    }

    // Cleanup
    for (int i = 0; i < numRows; ++i) {
        delete[] arr[i];
    }
    delete[] arr;

    return 0;
}
