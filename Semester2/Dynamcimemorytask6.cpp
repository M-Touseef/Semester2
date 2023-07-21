#include <iostream>

using namespace std;
//Prototypes of the Function
void inputMatrix(int** arr, int m, int n);
void displayMatrix(int** arr, int m, int n);
int sumMatrix(int** arr, int m, int n);
void displayRowSum(int** arr, int m, int n);
void displayColumnSum(int** arr, int m, int n);
int** createTranspose(int** arr, int m, int n);
int getLeftDiagonalSum(int** arr, int m, int n);
int getRightDiagonalSum(int** arr, int m, int n);
//Main Function
int main() {
    //Get input from user of the Array size
    int m, n;
    cout << "Enter the size of the matrix (m x n): ";
    cin >> m >> n;
    //Create 2D Dynamic Array
    int** arr = new int* [m];
    for (int i = 0; i < m; i++) {
        arr[i] = new int[n];
    }
    //DO-While  LOOP
    int choice;
    do {
        cout << "\nMenu:" << endl;
        cout << "1. To input elements into matrix of size " << m << " x " << n << endl;
        cout << "2. To display elements of matrix of size " << m << " x " << n << endl;
        cout << "3. Sum of all elements of matrix of size " << m << " x " << n << endl;
        cout << "4. To display row-wise sum of matrix of size " << m << " x " << n << endl;
        cout << "5. To display column-wise sum of matrix of size " << m << " x " << n << endl;
        cout << "6. To create transpose of matrix B of size " << n << " x " << m << endl;
        cout << "7. To display left diagonal sum" << endl;
        cout << "8. To display right diagonal sum" << endl;
        cout << "9. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            inputMatrix(arr, m, n);
            break;
        case 2:
            displayMatrix(arr, m, n);
            break;
        case 3:
            cout << "Sum of all elements: " << sumMatrix(arr, m, n) << endl;
            break;
        case 4:
            displayRowSum(arr, m, n);
            break;
        case 5:
            displayColumnSum(arr, m, n);
            break;
        case 6: {
            int** transpose = createTranspose(arr, m, n);
            cout << "Transpose of matrix B (" << n << " x " << m << "):" << endl;
            displayMatrix(transpose, n, m);
            for (int i = 0; i < n; i++) {
                delete[] transpose[i];
            }
            delete[] transpose;
            break;
        }
        case 7:
            cout << "Left diagonal sum: " << getLeftDiagonalSum(arr, m, n) << endl;
            break;
        case 8:
            cout << "Right diagonal sum: " << getRightDiagonalSum(arr, m, n) << endl;
            break;
        case 9:
            cout << "Exiting program..." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 9);

    for (int i = 0; i < m; i++) {
        delete[] arr[i];
    }
    delete[] arr;

    return 0;
}

void inputMatrix(int** arr, int m, int n) {
    cout << "Enter the elements of the matrix:" << endl;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }
}

void displayMatrix(int** arr, int m, int n) {
    cout << "Matrix:" << endl;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}
//Sum 
int sumMatrix(int** arr, int m, int n) {
    int sum = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            sum += arr[i][j];
        }
    }
    return sum;
}
//row wise Sum
void displayRowSum(int** arr, int m, int n) {
    cout << "Row-wise sum:" << endl;
    for (int i = 0; i < m; i++) {
        int rowSum = 0;
        for (int j = 0; j < n; j++) {
            rowSum += arr[i][j];
        }
        cout << "Sum of row " << i + 1 << ": " << rowSum << endl;
    }
}
//Columns wise sum
void displayColumnSum(int** arr, int m, int n) {
    cout << "Column-wise sum:" << endl;
    for (int j = 0; j < n; j++) {
        int colSum = 0;
        for (int i = 0; i < m; i++) {
            colSum += arr[i][j];
        }
        cout << "Sum of column " << j + 1 << ": " << colSum << endl;
    }
}
//Transpose
int** createTranspose(int** arr, int m, int n) {
    int** transpose = new int* [n];
    for (int i = 0; i < n; i++) {
        transpose[i] = new int[m];
        for (int j = 0; j < m; j++) {
            transpose[i][j] = arr[j][i];
        }
    }
    return transpose;
}
//Diagonal Sum
int getLeftDiagonalSum(int** arr, int m, int n) {
    int diagonalSum = 0;
    int minDim = min(m, n);
    for (int i = 0; i < minDim; i++) {
        diagonalSum += arr[i][i];
    }
    return diagonalSum;
}
//Diagonal Sum 2 
int getRightDiagonalSum(int** arr, int m, int n) {
    int diagonalSum = 0;
    int minDim = min(m, n);
    for (int i = 0; i < minDim; i++) {
        diagonalSum += arr[i][n - i - 1];
    }
    return diagonalSum;
}
