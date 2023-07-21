#include<iostream>
using namespace std;

// Function to allocate memory for a 2D dynamic array
int** createDynamicArray(int rows, int columns) {
    int** array = new int* [rows];
    for (int i = 0; i < rows; i++) {
        array[i] = new int[columns];
    }
    return array;
}

// Function to deallocate memory of a 2D dynamic array
void deallocateDynamicArray(int** array, int rows) {
    for (int i = 0; i < rows; i++) {
        delete[] array[i];
    }
    delete[] array;
}

// Function to display the 2D dynamic array
void displayArray(int** array, int rows, int columns) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            cout << array[i][j] << " ";
        }
        cout << endl;
    }
}

// Function to delete a row from a 2D dynamic array
int** deleteRow(int** array, int& rows, int columns, int rowIndex) {
    int** newArray = createDynamicArray(rows - 1, columns);
    int newRow = 0;
    for (int i = 0; i < rows; i++) {
        if (i != rowIndex) {
            for (int j = 0; j < columns; j++) {
                newArray[newRow][j] = array[i][j];
            }
            newRow++;
        }
    }
    deallocateDynamicArray(array, rows);
    rows--;
    return newArray;
}

// Function to delete a column from a 2D dynamic array
int** deleteColumn(int** array, int rows, int& columns, int columnIndex) {
    int** newArray = createDynamicArray(rows, columns - 1);
    for (int i = 0; i < rows; i++) {
        int newCol = 0;
        for (int j = 0; j < columns; j++) {
            if (j != columnIndex) {
                newArray[i][newCol] = array[i][j];
                newCol++;
            }
        }
    }
    deallocateDynamicArray(array, rows);
    columns--;
    return newArray;
}

int main() {
    int rows, columns;
    cout << "Enter the number of rows: ";
    cin >> rows;
    cout << "Enter the number of columns: ";
    cin >> columns;

    // Create the initial 2D dynamic array
    int** dynamicArray = createDynamicArray(rows, columns);

    // Input values into the array
    cout << "Enter the elements of the array:" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            cin >> dynamicArray[i][j];
        }
    }

    // Display the original array
    cout << "Original Array:" << endl;
    displayArray(dynamicArray, rows, columns);

    // Delete a row
    int rowIndex;
    cout << "Enter the row index to delete: ";
    cin >> rowIndex;
    if (rowIndex >= 0 && rowIndex < rows) {
        dynamicArray = deleteRow(dynamicArray, rows, columns, rowIndex);
        cout << "Array after deleting row:" << endl;
        displayArray(dynamicArray, rows, columns);
    }
    else {
        cout << "Invalid row index." << endl;
    }

    // Delete a column
    int columnIndex;
    cout << "Enter the column index to delete: ";
    cin >> columnIndex;
    if (columnIndex >= 0 && columnIndex < columns) {
        dynamicArray = deleteColumn(dynamicArray, rows, columns, columnIndex);
        cout << "Array after deleting column:" << endl;
        displayArray(dynamicArray, rows, columns);
    }
    else {
        cout << "Invalid column index." << endl;
    }

    // Deallocate memory
    deallocateDynamicArray(dynamicArray, rows);

    return 0;
}
