#include <iostream>
#include <fstream>

using namespace std;
//Use global variable
const int MAX_ROWS = 10;
const int MAX_COLS = 10;
//Prototypes of the function
void display(int[][10], int, int);
void readMatrixFromFile(const char*, int matrix[][MAX_COLS], int&, int&);
void sumMatrices(const int matrix1[][10], const int matrix2[][10], int result[MAX_ROWS][10],int, int);
//Main function
int main() {
    // Matrix 1
    int matrix1[MAX_ROWS][MAX_COLS];
    int numRows1, numCols1;
    // Matrix 2
    int matrix2[MAX_ROWS][MAX_COLS];
    int numRows2, numCols2;
    //Read Data
    readMatrixFromFile("M1.txt", matrix1, numRows1, numCols1);
    readMatrixFromFile("M2.txt", matrix2, numRows2, numCols2);
    //check the order of Matrix
    if (numRows1 != numRows2 || numCols1 != numCols2) {
        cout << "The matrices have different dimensions" << endl;
        return 1;
    }

    int result[MAX_ROWS][MAX_COLS];
    sumMatrices(matrix1, matrix2, result, numRows1, numCols1);

    display(result, numRows1, numCols1);

    return 0;
}
//Read a file
void readMatrixFromFile(const char* filename, int matrix[MAX_ROWS][MAX_COLS], int& numRows, int& numCols) {

    ifstream inputFile(filename);
    if (!inputFile.is_open()) {
        cout << "Failed to open the file : " << filename << endl;
        return;
    }
    numRows = 0;
    numCols = 0;
    int value;
    while (inputFile >> value) {
        matrix[numRows][numCols] = value;
        numCols++;
        char a;
        inputFile >> a;
        if (a == '\n') {
            numRows++;
            numCols = 0;
        }
    }

    inputFile.close();
}
//Display Function
void display_col(int array[][3], int rows, int columns) {
    for (int i = 0; i < columns; i++) {
        for (int j = 0; j < rows; j++) {
            cout << array[j][i] << " ";
        }
        cout << endl;
    }
}
//Sum
void sumMatrices(const int matrix1[][MAX_COLS], const int matrix2[MAX_ROWS][MAX_COLS], int result[MAX_ROWS][MAX_COLS],
    int numRows, int numCols) {
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numCols; j++) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
}
