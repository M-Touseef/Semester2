#include <iostream>
using namespace std;
//Prototypes
void displayMatrix(int**, int, int);
int** calculate(int**, int**, int, int);
int** inputMatrix(int, int);
void deallocateMatrix(int**, int);
//Main Function
int main() {
    int rows, colums;
    cout << "Enter the number of rows : ";
    cin >> rows;
    cout << "Enter the number of columns : ";
    cin >> colums;
    //call the function
    cout << "Enter the elements of the first matrix : " <<endl;
    int** matrix1 = inputMatrix(rows, colums); 
    cout << "Enter the elements of the second matrix : " <<endl;
    int** matrix2 = inputMatrix(rows, colums);
    int** dotProduct = calculate(matrix1, matrix2, rows, colums);
    //mutiple the Matixes
    cout << "product matrix:" <<endl;
    displayMatrix(dotProduct, rows, colums);
    //Free the Dynamic Memory
    deallocateMatrix(matrix1, rows);
    deallocateMatrix(matrix2, rows);
    deallocateMatrix(dotProduct, rows);

    return 0;
}
//multiple the Matrix
int** calculate(int** matrix1, int** matrix2, int rows, int colums) {
    int** Product = new int* [rows];
    for (int i = 0; i < rows; ++i) {
        Product[i] = new int[colums];
        for (int j = 0; j < colums; ++j) {
            Product[i][j] = 0;
            for (int k = 0; k < colums; ++k) {
                Product[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
    return Product;
}
//deallocate the memory
void deallocateMatrix(int** matrix, int rows) {
    for (int i = 0; i < rows; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;
}
//Input from user
int** inputMatrix(int rows, int colums) {
    int** matrix = new int* [rows];
    for (int i = 0; i < rows; ++i) {
        matrix[i] = new int[colums];
        for (int j = 0; j < colums; ++j) {
            cout << "Enter element at position (" << i + 1 << ", " << j + 1 << "): ";
            cin >> matrix[i][j];
        }
    }
    return matrix;
}
//Display Function
void displayMatrix(int** matrix, int rows, int colums) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < colums; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}
