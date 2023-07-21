#include <iostream>
using namespace std;
int main() {
    int Labs_num,toatl_students = 0;
    cout << "Enter the total number of labs in the university : ";
    cin >> Labs_num;
    //use Dynamic Arrays
    int* student_num = new int[Labs_num];

    cout << "Enter the number of students in Lab  \n";

    for (int i = 0; i < Labs_num; i++) {
        //use address of the variables
        cin >>*(student_num+i);
    }

    for (int i = 0; i < Labs_num; i++) {
        //use address of the variables
        toatl_students += *(student_num + i);
    }
    int average = static_cast<int>(toatl_students) / Labs_num;
    cout << "The average number of students in a lab is " << average;
    delete[] student_num;
    return 0;
}
