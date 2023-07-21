#include<iostream>
using namespace std;
double conversion = 2.53;
const int Inches_feets = 12;
//We can also use this values instead of the global Variabkle
const int Centimeters_Meters = 100;
void show() {
	cout << "Enter\n";
	cout << " 1 : To convert from feets and inches to meters and centimeters\n";
	cout << " 2 : To convert from meters and centimeters to feets and inches\n";
	cout << " 99 : to quit the program---\n";
}
void feetandinchestometersandcentimeters(int feets, int inches, int& meters, int& centimeters) {
	//Convert all values in Inches
	inches = feets * 12 + inches;
	//use static type so do not get value in float
	centimeters = static_cast<int>(inches * conversion);
	//we can use 100 intead of Centimeters
	meters = centimeters / Centimeters_Meters;
	centimeters = centimeters % Centimeters_Meters;

}
void metersandcentimeterstofeetandinches(int meters, int centimeters, int& feets, int& inches) {
	centimeters = meters * Centimeters_Meters + centimeters;
	inches = static_cast<int>(centimeters / conversion);
	//use 12 instead of inches_feets
	feets = inches / Inches_feets;
	inches = inches % Inches_feets;
}
int main() {
	int feets, inches, meters, centimeters, choice;
	do {
		show();
		cin >> choice;
		switch (choice) {
		case 1:
			cout << "Enters feets and inches" << endl;
			cin >> feets >> inches;
			feetandinchestometersandcentimeters(feets, inches, meters, centimeters);
			cout << feets << " Feets " << inches << " Inches = "
				<< meters << " Meters " << centimeters << " Centimeters " << endl;
			break;
		case 2:
			cout << "Enters Meters and Centimeters" << endl;
			cin >> meters >>centimeters;
			metersandcentimeterstofeetandinches(meters, centimeters,feets, inches);
			cout <<meters << " Meters " << centimeters << " Centimeters = "
				<< feets << " Feets " << inches << " Inches " << endl;
			break;
		case 99:
			break;
		default:
			cout << "Invalid Input" << endl;
		}
	
	} 
	while (choice!=99);
	return 0;
}