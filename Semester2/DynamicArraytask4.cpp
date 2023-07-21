#include <iostream>
#include <fstream>
using namespace std;
const int MAX_ROWS = 10;
const int MAX_COLS = 10;

void readdata(const char*, int matrix[][10], int&, int&);
void findelements(const int matrix[][10], int, int, int&, int&);
//Main Function
int main() {
    int matrix[MAX_ROWS][MAX_COLS];
    int numRows, numCols;
    //Call the function to read a Data
    readdata("M1.txt", matrix, numRows, numCols);

    int minimum, maximum;
    findelements(matrix, numRows, numCols, minimum, maximum);

    cout << "Minimum element: " << minimum << endl;
    cout << "Maximum element: " << maximum << endl;

    return 0;
}
//Read Data
void readdata(const char* filename, int matrix[][10], int& numRows, int& numCols) {
    ifstream inputFile(filename);
    if (!inputFile.is_open()) {
        cout << "Failed to open the file: " << filename << endl;
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
//find Elements
void findelements(const int matrix[][10], int rows, int columns, int& minimum, int& maximum) {
    minimum = matrix[0][0];
    maximum = matrix[0][0];

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j <columns; j++) {
            if (matrix[i][j] < minimum)
                minimum = matrix[i][j];

            if (matrix[i][j] > maximum)
                maximum = matrix[i][j];
        }
    }
}

