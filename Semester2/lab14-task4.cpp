#include<iostream>
#include<fstream>
using namespace std;
//Function 
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
    readdatafromfile(dynamicmatrix, columns, rows);
    // Display the Array
    cout << "The MATRIX read from the File" << endl;
    displayMatrix(dynamicmatrix, rows, columns);

    // Read the new column from the second file
    ifstream file2;
    file2.open("new_column.txt");
    if (!file2.is_open()) {
        cout << "Second file failed to open" << endl;
    }
    else {
        int* newColumn = new int[rows];
        for (int i = 0; i < rows; i++) {
            file2 >> newColumn[i];
        }
        // Insert the new column at the end of the matrix
        int** newMatrix = new int* [rows];
        for (int i = 0; i < rows; i++) {
            newMatrix[i] = new int[columns + 1];
            for (int j = 0; j < columns; j++) {
                newMatrix[i][j] = dynamicmatrix[i][j];
            }
            newMatrix[i][columns] = newColumn[i];
        }
        // Deallocate the old matrix
        deallocate_memory(dynamicmatrix, rows);
        // Update the matrix and columns
        dynamicmatrix = newMatrix;
        columns++;
        delete[] newColumn;
    }
    file2.close();


    // Display the Matrix After inserting the new column
    cout << "Matrix After Inserting the New Column: " << endl;
    displayMatrix(dynamicmatrix, rows, columns);

    // Deallocate the Matrix
    deallocate_memory(dynamicmatrix, rows);

    return 0;
}
