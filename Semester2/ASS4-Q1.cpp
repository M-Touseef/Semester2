#include <iostream>
#include <fstream>
using namespace std;

//Prototypes of Functions
int count(char* text);
void findlengths(char* text, int* word_lengths, int );

// Count the Words
int count(char* text) {
    int count = 0;
    bool check= false;

    while (*text != '\0') {
        if (*text == ' ' || *text == '\n' || *text == '\t') {
            check = false;
        }
        else if (!check) {
            check = true;
            count++;
        }

        text++;
    }
    return count;
}
// Function to find the length of each word
void findlengths(char* text, int* word_lengths, int numwords) {
    int word_index = 0;
    int length = 0;

    while (*text != '\0') {
        if (*text == ' ' || *text == '\n' || *text == '\t') {
            if (length > 0) {
                *(word_lengths + word_index) = length;
                length = 0;
                word_index++;
            }
        }
        else {
            length++;
        }
        text++;
    }
    // Save the length
    if (length > 0) {
        *(word_lengths + word_index) = length;
    }
}
//Main Function
int main() {
    //Use proper IOS flag and error handling
    fstream file("text.txt",ios::in);
    if (!file.is_open()) {
       cout << "Failed to open the file\n";
       
    }
    else {

        const int max_length = 100;
        char* text = new char[max_length];
        file.getline(text, max_length);
        int numwords = count(text);

        // array dynamically to store the word lengths
        int* word_lengths = new int[numwords];

        // Find the length of word & save them in the array
        findlengths(text, word_lengths, numwords);

        cout << "Original text: " << text <<endl;
        cout << "Array of Lengths: ";
        for (int i = 0; i < numwords; i++) {
            cout << *(word_lengths + i) << " ";
        }
        cout << endl;
        //Close the file
        file.close();

        // Clean the dynamically memory
        delete[] text;
        delete[] word_lengths;
    }
    return 0;
}
