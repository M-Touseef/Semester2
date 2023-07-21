#include <iostream>
#include <fstream>
using namespace std;

int main() {
    char name[10];
    float circle_radius, circle_area;
    fstream file;
    file.open("Circle.txt",ios::out|ios::in);
    if (!file.is_open()) {
        cout << "File did not Create" << endl;
    }
    else {
        file << " Circle1 , 5" << endl;
        file << "Circle2 , 10" << endl;
        file << "Circle3 , 4" << endl;
        file.close();
    }
    //Calculate the Data
   
    file.open("Circle.txt");
    if (!file.is_open()) {
        cout << "Unable to open the file where Data of the Circle is Saved\n";
    }
    else {
        ofstream file2;
        file2.open("Circle_area.txt");
        if (!file2.is_open()) {
            cout << "Failed to open the file where data is stored after the Calculation\n";
        }
        else {
            int i = 0;
            file2 << "After Calculating area :" << endl;
            while (!file.eof())
            {
                file.ignore();
                file.getline(name, 10, ',');
                file >> circle_radius;
                circle_area =3.1428 * circle_radius * circle_radius;
                file2 << name << ", " <<circle_radius << " : " << circle_area << endl;
                i++;
            }
            cout << "Data is sucessfully store in Circle_area Txt \n";
            file2.close();
        }
        file.close();
    }
    return 0;
}