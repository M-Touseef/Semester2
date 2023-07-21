#include <iostream>
using namespace std;

// Function to allocate memory for a 2D dynamic char array
char** createDynamicCharArray(int rows, int columns) {
    char** array = new char* [rows];
    for (int i = 0; i < rows; i++) {
        array[i] = new char[columns];
    }
    return array;
}

// Function to deallocate memory of a 2D dynamic char array
void deallocateDynamicCharArray(char** array, int rows) {
    for (int i = 0; i < rows; i++) {
        delete[] array[i];
    }
    delete[] array;
}

// Function to display the 2D dynamic char array
void displayCharArray(char** array, int rows, int columns) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            cout << array[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int rows, columns;
    cout << "Enter the number of rows: ";
    cin >> rows;
    cout << "Enter the number of columns: ";
    cin >> columns;

    // Create the 2D dynamic char array
    char** dynamicArray = createDynamicCharArray(rows, columns);

    // Input values into the array
    cout << "Enter the elements of the array:" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            cin >> dynamicArray[i][j];
        }
    }

    // Display the array
    cout << "Array:" << endl;
    displayCharArray(dynamicArray, rows, columns);

    // Deallocate memory
    deallocateDynamicCharArray(dynamicArray, rows);

    return 0;
}

