#include <iostream>
#include <fstream>
using namespace std;

// Prototypes
void readdata(int*& array, int& size);
void display(int* array, int size);
void copy(const int* old_arr, int* new_arr, int , int );
int* shrink(int* old_arr, int , int );

// Main Function
int main() {
    int size = 0;
    int* arr = nullptr;
    readdata(arr, size);
    cout << "Data : ";
    display(arr, size);
    int delete_no = 3;
    //dynamic array to enter the number user want to delete
    int* delete_noarray = new int[delete_no];
    cout << "Enter the numbers you want to delete: ";
    for (int i = 0; i < delete_no; i++) {
        cin >> delete_noarray[i];
    }
    for (int i = 0; i < delete_no; i++) {
        arr = shrink(arr, size, delete_noarray[i]);
        size--;
    }

    cout << "Values of array after deletion: ";
    display(arr, size);
    //Clean up dynamic Memory
    delete[] arr;
    delete[] delete_noarray;

    return 0;
}
// Open the file and read the data
void readdata(int*& array, int& size) {
    ifstream file("integer.txt");
    if (!file.is_open()) {
        cout << "File did not open successfully" << endl;
    }
    else {
        int temp;
        while (file >> temp) {
            size++;
        }

        file.close();
        file.open("integer.txt");

        array = new int[size];
        for (int i = 0; i < size; i++) {
            file >> array[i];
        }
        file.close();
    }
}
// Copy elements from old_arr to new_arr 
void copy(const int* old_arr, int* new_arr, int size, int x) {
    int newarr_size = 0;
    for (int i = 0; i < size; i++) {
        if (old_arr[i] != x) {
            new_arr[newarr_size] = old_arr[i];
            newarr_size++;
        }
    }
}

// Shrink the array by excluding the specified value
int* shrink(int* old_arr, int size, int y) {
    int* new_arr = new int[size - 1];
    copy(old_arr, new_arr, size, y);
    delete[] old_arr;
    return new_arr;
}

// Display the array
void display(int* array, int size) {
    for (int i = 0; i < size; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
}


