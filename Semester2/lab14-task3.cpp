#include<iostream>
#include<fstream>
using namespace std;

void readdatafromfile(int**& dynamicArray, int& columns, int& rows) {
    // Open the file to read Data
    ifstream file;
    file.open("input.txt");
    if (!file.is_open()) {
        cout << "File failed to open" << endl;
    }
    else {
        // First line in the file tells us about the array size
        file >> rows >> columns;
        // Allocate the 2D Array
        dynamicArray = new int* [rows];
        for (int i = 0; i < rows; i++) {
            dynamicArray[i] = new int[columns];
        }
        // Read the data from the file into the array
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                file >> dynamicArray[i][j];
            }
        }
    }
    file.close();
}

// Display the function
void displayMatrix(int** matrix, int rows, int columns) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

// Insert a new row at the end of the matrix
void insertRow(int**& matrix, int& rows, int columns, int* newRow) {
    // Create a new matrix with increased rows
    int** newMatrix = new int* [rows + 1];
    for (int i = 0; i < rows + 1; i++) {
        newMatrix[i] = new int[columns];
    }

    // Copy the existing matrix to the new matrix
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            newMatrix[i][j] = matrix[i][j];
        }
    }

    // Copy the new row to the last row of the new matrix
    for (int j = 0; j < columns; j++) {
        newMatrix[rows][j] = newRow[j];
    }

    // Deallocate the old matrix
    deallocate_memory(matrix, rows);

    // Update the matrix and rows
    matrix = newMatrix;
    rows++;
}

// Deallocate the Memory
void deallocate_memory(int** array, int rows) {
    for (int i = 0; i < rows; i++) {
        delete[] array[i];
    }
    delete[] array;
}

// Main Function
int main() {
    // Initialize the Variables
    int rows, columns;
    int** dynamicmatrix = nullptr;
    // Call the function to read the data
    readdatafromfile(dynamicmatrix, rows, columns);
    // Display the Array
    cout << "The MATRIX read from the File" << endl;
    displayMatrix(dynamicmatrix, rows, columns);

    // Read the new row from the second file
    ifstream file2;
    file2.open("new_row.txt");
    if (!file2.is_open()) {
        cout << "Second file failed to open" << endl;
    }
    else {
        int* newRow = new int[columns];
        for (int j = 0; j < columns; j++) {
            file2 >> newRow[j];
        }
        // Insert the new row at the end of the matrix
        insertRow(dynamicmatrix, rows, columns, newRow);
        delete[] newRow;
    }
    file2.close();

    // Display the Matrix After inserting the new row
    cout << "Matrix After Inserting the New Row: " << endl;
    displayMatrix(dynamicmatrix, rows, columns);

    // Deallocate the Matrix
    deallocate_memory(dynamicmatrix, rows);

    return 0;
}
