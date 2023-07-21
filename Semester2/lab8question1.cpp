#include <iostream>
#include <fstream>
using namespace std;
const int num_categories= 4;
//Use function only for count 
void display() {
    cout << "Please Select One of the following options:" << endl
        << "1. Search the category with the maximum number of tickets sold." << endl
        << "2. Display only those categories whose total sales exceed 10,000." << endl
        << "3. Calculate total number of tickets sold. " << endl;
}
// Function to read data from file into arrays
void readdata(string categories[], int ticket_prices[], int tickets_sold[]) {
    fstream file("Data.txt",ios::in);
    if (!file.is_open()) {
        cout << "Failed to Read the file " << endl;
    }
    else {
        string category;
        int price, sold;
        char waste[200] = {};
        file.getline(waste, 200);
        for (int i = 0; i <num_categories ; i++) {
            file >> category >> price >> sold;
            categories[i] = category;
            ticket_prices[i] = price;
            tickets_sold[i] = sold;
        }
        cout << "File is read sucessfully!" << endl;
        file.close();
    }
}
// Function for maximum number of tickets sold
string Maximum(string categories[], int ticketsSold[]) {
    int max_sold = 0;
    string maxcategory;
    for (int i = 0; i < num_categories ; i++) {
        if (ticketsSold[i] > max_sold) {
            max_sold = ticketsSold[i];
            maxcategory = categories[i];
        }
    }
    return maxcategory;
}

// Function sales exceed 10,000
void Over10000(string categories[], int ticketPrices[], int ticketsSold[]) {
    cout << "Categories with sales over 10,000:" << endl;

    for (int i = 0; i <num_categories ; i++) {
        if (ticketPrices[i] * ticketsSold[i] > 10000) {
            cout << categories[i] << endl;
        }
    }
}
// Function to calculate total number of tickets sold
int Total_soldtickets(int ticketsSold[]) {
    int totalSold = 0;
    for (int i = 0; i <num_categories; i++) {
        totalSold += ticketsSold[i];
    }
    return totalSold;
}
// Main Function
int main() {
    string types[num_categories];
    int ticketPrices[num_categories];
    int ticketsSold[num_categories];
    readdata(types, ticketPrices, ticketsSold);

    int select;
    char choice = 'y';
    while (choice != 'n') {
        display();
        cout << "Enter your choice :";
        cin >> select;
        switch (select) {
        case 1:
            cout << "Category with maximum number of tickets sold: " << Maximum(types, ticketsSold) << endl;
            break;
        case 2:

            Over10000(types, ticketPrices, ticketsSold);
            break;
        case 3:
            cout << "Total number of tickets sold: " << Total_soldtickets(ticketsSold) << endl;
            break;
        default:
            cout << "Command Error" << endl;
        }
        cout << "Do you want to continue (y/n) :";
        cin >> choice;
    }
    return 0;
}
