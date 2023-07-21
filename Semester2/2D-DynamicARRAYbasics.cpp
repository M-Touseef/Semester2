#include <iostream>

// Function to create a dynamic 2D array
int** createDynamicArray(int rows, int columns) {
    // Dynamically allocate memory for the 2D array
    int** dynamicArray = new int* [rows];
    for (int i = 0; i < rows; ++i) {
        dynamicArray[i] = new int[columns];
    }

    return dynamicArray;
}

// Function to deallocate memory for the dynamic 2D array
void deleteDynamicArray(int** dynamicArray, int rows) {
    for (int i = 0; i < rows; ++i) {
        delete[] dynamicArray[i];
    }
    delete[] dynamicArray;
}

int main() {
    int rows, columns;

    // Get the size of the 2D array from the user
    std::cout << "Enter the number of rows: ";
    std::cin >> rows;
    std::cout << "Enter the number of columns: ";
    std::cin >> columns;

    // Create the dynamic array
    int** dynamicArray = createDynamicArray(rows, columns);

    // Access and modify the elements of the dynamic array
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            dynamicArray[i][j] = i + j;  // Assign some values to the array
        }
    }

    // Print the elements of the dynamic array
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            std::cout << dynamicArray[i][j] << " ";
        }
        std::cout << std::endl;
    }

    // Deallocate the memory for the dynamic array
    deleteDynamicArray(dynamicArray, rows);

    return 0;
}