#include <iostream>
#include <string>
using namespace std;
//use header file of regards function
void print(string&name);
//main function
int main() {
    string name;
    cout << "Please Enter Your Name : " << endl;
   cin >> name;
   //call the function
    print(name);
    return 0;
}
void print(string& name) {
     cout << "Regards , " <<endl;
   cout << name <<endl;
}

