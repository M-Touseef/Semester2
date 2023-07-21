
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
//Function tio copy a Data
void copy_data(int** old_array, int** new_array, int rows, int columns) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            new_array[i][j] = old_array[i][j];
        }
    }
}
//Row wise Sum
void row_sum(int**&array, int rows, int columns) {
    int totalrowssum;
    for (int i = 0; i < rows; i++) {
        totalrowssum = 0;
        for (int j = 0; j < columns; j++) {
            totalrowssum += array[i][j];
        }
        array[i][columns] = totalrowssum;
    }
}
//Column Wise Sum
void column_sum(int**& array, int rows, int columns) {
    int totalcolumns;
    for (int j = 0; j < columns; j++) {
        int totalcolumns = 0;
        for (int i = 0; i < rows; i++) {
            totalcolumns += array[i][j];
        }
        array[rows][j] = totalcolumns;
    }
}
//Deallocate the Memory
void deallocate_memory(int**array, int rows) {
    for (int i = 0; i < rows; i++) {
        delete[] array[i];
    }
    delete[] array;
}
//Write the Data into file
void write_file(int** matrix, int rows, int columns) {
    ofstream outputFile("updatedata.txt");

    if (outputFile.is_open()) {
        outputFile << rows << " " << columns << endl;

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                outputFile << matrix[i][j] << " ";
            }
            outputFile << endl;
        }

        outputFile.close();
    }
}

// Main Function
int main() {
    // Initialize the Variables
    int rows, columns;
    int** dynamicmatrix = nullptr;
    int** newdynamicarray = nullptr;
    // Call the function to read the data
    readdatafromfile(dynamicmatrix, rows, columns);
    // Display the Array
    cout << "The MATRIX read from the File" << endl;
    displayMatrix(dynamicmatrix, rows, columns);
    //Allocate the New 2D Dynamic Matrix
    int new_rows = rows + 1;
    int new_columns = columns + 1;
    newdynamicarray = new int* [new_rows];
    for (int i = 0; i < new_rows; i++) {
        newdynamicarray[i] = new int[new_columns];
    }
    //Call the function to Copy the Data
    copy_data(dynamicmatrix, newdynamicarray, rows, columns);
    //Call the function the sum the Rows
    row_sum(newdynamicarray, rows, columns);

    //Call the function the sum the Rows
    column_sum(newdynamicarray, rows, columns);
    newdynamicarray[rows][columns] = 0;
    cout << endl;
    cout << "The New Matrix " << endl;
    //Display the Matrix after perform the Tasks
    displayMatrix(newdynamicarray, new_rows, new_columns);

    //Write the new matrix in file
    write_file(newdynamicarray, new_rows, new_columns);

    //Deallocate the Memory
    deallocate_memory(dynamicmatrix, rows);
    deallocate_memory(newdynamicarray, new_rows);


    return 0;
}