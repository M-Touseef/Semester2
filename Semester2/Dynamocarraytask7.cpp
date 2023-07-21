#include <iostream>
#include <fstream>
using namespace std;
const int MAX_ROWS = 10;
const int MAX_COLS = 10;

//Prototypes of the function
void readDataFromFile(const char*, double [][10], int&, int&);
void displayData(const double [][10], int, int);
void calculateRowSum(const double data[][10], int, int);
void calculateColumnSum(const double [][10], int , int );
//main Function
int main() {
    const char* filename = "Data.txt";
    double data[MAX_ROWS][MAX_COLS];
    int numRows = 0, numCols = 0;
    // Read data from file
    readDataFromFile(filename, data, numRows, numCols);
    // Display the data
    cout << "Data from file :" << endl;
    displayData(data, numRows, numCols);
    // Calculate and display row-wise sum
    cout << endl;
    cout << "Sum row - wise: ";
    calculateRowSum(data, numRows, numCols);

    // Calculate and display column-wise sum
    cout << endl;
    cout << "Sum column-wise:";
    calculateColumnSum(data, numRows, numCols);

    return 0;
}

void readDataFromFile(const char* filename, double data[MAX_ROWS][MAX_COLS], int& numRows, int& numCols) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Error opening file: " << filename << endl;
        return;
    }

    char c;
    double value = 0.0;
    int col = 0;

    while (file.get(c)) {
        if (c == ' ' || c == '\t' || c == '\n') {
            if (col < MAX_COLS) {
                data[numRows][col++] = value;
                value = 0.0;
            }
            if (c == '\n') {
                numCols = max(numCols, col);
                numRows++;
                col = 0;
            }
        }
        else if (c >= '0' && c <= '9') {
            value = value * 10 + (c - '0');
        }
        else if (c == '.' && value > 0) {
            double decimal = 0.1;
            while (file.get(c)) {
                if (c >= '0' && c <= '9') {
                    value += (c - '0') * decimal;
                    decimal *= 0.1;
                }
                else {
                    if (col < MAX_COLS) {
                        data[numRows][col++] = value;
                        value = 0.0;
                    }
                    break;
                }
            }
        }

        if (col == MAX_COLS) {
            numCols = max(numCols, col);
            numRows++;
            col = 0;
        }
    }

    if (col < MAX_COLS && value > 0) {
        data[numRows][col++] = value;
    }

    numCols = max(numCols, col);
    numRows++;

    file.close();
}
//Display the Data
void displayData(const double data[10][10], int numRows, int numCols) {
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numCols; j++) {
            cout << data[i][j] << " ";
        }
        cout << endl;
    }
}
//sum of the rows
void calculateRowSum(const double data[10][10], int numRows, int numCols) {
    for (int i = 0; i < numRows; i++) {
        double sum = 0.0;
        for (int j = 0; j < numCols; j++) {
            sum += data[i][j];
        }
        cout << " " << sum << ",";
    }
    cout << endl;
}
//Columns sum
void calculateColumnSum(const double data[10][10], int numRows, int numCols) {
    for (int j = 0; j < numCols; j++) {
        double sum = 0.0;
        for (int i = 0; i < numRows; i++) {
            sum += data[i][j];
        }
        cout << " " << sum << ",";
    }
    cout << endl;
}
