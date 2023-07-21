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
        // First 2 digits in the file tell us about the array size
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
//Deallocate the Memory
void deallocate_memory(int** array, int rows) {
    for (int i = 0; i < rows; i++) {
        delete[] array[i];
    }
    delete[] array;
}
//Delete the Row
void delete_row(int**& array, int rows, int columns) {
    int index;
    cout << "Row index to delete : ";
    cin >> index;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            if (i == index) {
                array[i][j] = 0;
            }
        }
    }
}
//Delete the Column
void delete_column(int**& array, int rows, int columns) {
    int index;
    cout << "Column index to delete : ";
    cin >> index;
    for (int j = 0; j <columns; j++) {
        for (int i = 0; i <rows; i++) {
            if (j == index) {
                array[i][j] = 0;
            }
        }
    }
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
    //take user choice
    int choice = 0;
    //Use While LOOP
    while (choice != 99) {
        cout << "Enter the  1  delete row : " << endl
            << "Enter the  2  delete column : " << endl
            <<"Enter 3 to exits the program : "<<endl
            << "Enter Your Choice : ";
        cin >> choice;
        if (choice == 1) {
            delete_row(dynamicmatrix, rows, columns);
        }
        else if (choice == 2) {
            delete_column(dynamicmatrix, rows, columns);
        }
        else {
            choice = 99;
        }
    }
    //Display the Matrix After the Change
    cout << "Matrix After Delete the Row : " << endl;
    displayMatrix(dynamicmatrix, rows, columns);
    //Deallocate the Matrix
    deallocate_memory(dynamicmatrix, rows);

    return 0;
}