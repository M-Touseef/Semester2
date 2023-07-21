#include <iostream>
#include <fstream>
using namespace std;

// Global Constants
const int total_questions = 5;
const int answer_choices = 4;
const int total_student = 5;


// Function Prototypes
void display_key(char answers[]);
void display_scores(int studentIDs[], int studentScores[]);
void display_missedquestions(int missedCount[]);
void calculate_scores(char answers[], char studentAnswers[][total_questions], int studentScores[]);
void display_results(char questions[][100], char answers[], char studentAnswers[][total_questions], int studentIDs[]);
void create_quiz(char questions[][100], char choices[][answer_choices][50], char answers[]);
void savefile(char questions[][100], char choices[][answer_choices][50], char answers[]);
void take_quiz(char questions[][100], char choices[][answer_choices][50], char studentAnswers[][total_questions], int studentIDs[]);



// Function to display the answer key
void display_key(char answers[]) {
    cout << "Answer key" << endl;
    cout << "Question ";
    for (int i = 0; i < total_questions; i++) {
        cout << (i + 1) << " ";
    }
    cout << endl;

    cout << "Answer    ";
    for (int i = 0; i < total_questions; i++) {
        cout << answers[i] << " ";
    }
    cout << endl;
}

// Function to display student scores
void display_scores(int studentIDs[], int studentScores[]) {
    cout << "Student Scores:" << endl;
    cout << "ID    Score(%)" << endl;

    for (int i = 0; i < total_student; i++) {
        cout << studentIDs[i] << "     " << studentScores[i] << endl;
    }
}

// Function to display the count of missed questions
void display_missedquestions(int missedCount[]) {
    cout << "Questions ";
    for (int i = 0; i < total_questions; i++) {
        cout << (i + 1) << " ";
    }
    cout << endl;

    cout << "Missed by  ";
    for (int i = 0; i < total_questions; i++) {
        cout << missedCount[i] << " ";
    }
    cout << endl;
}

// Function to calculate student scores
void calculate_scores(char answers[], char studentAnswers[][total_questions], int studentScores[]) {
    for (int i = 0; i < total_student; i++) {
        int score = 0;
        for (int j = 0; j < total_questions; j++) {
            if (studentAnswers[i][j] == answers[j]) {
                score++;
            }
        }
        studentScores[i] = static_cast<float>(score) / total_questions * 100;
    }
}

// Function to display the results
void display_results(char questions[][100], char answers[], char studentAnswers[][total_questions], int studentIDs[]) {
    cout << "--- Exam Report ---" << endl;

    display_key(answers);

    int studentScores[total_student];
    calculate_scores(answers, studentAnswers, studentScores);
    display_scores(studentIDs, studentScores);

    int missedCount[total_questions] = { 0 };
    for (int i = 0; i < total_student; i++) {
        for (int j = 0; j < total_questions; j++) {
            if (studentAnswers[i][j] != answers[j]) {
                missedCount[j]++;
            }
        }
    }
    display_missedquestions(missedCount);
}
// Function to save questions and choices to a file
void savefile(char questions[][100], char choices[][answer_choices][50], char answers[]) {
    ofstream file("questions.txt");
    if (file.is_open()) {
        for (int i = 0; i < total_questions; i++) {
            file << "Question " << (i + 1) << ": " << questions[i] << "?" << endl;
            for (int j = 0; j < answer_choices; j++) {
                file << (j + 1) << ") " << choices[i][j] << "." << endl;
            }
            file << "Correct Answer: " << answers[i] << endl << endl;
        }
        file.close();
        cout << "Questions saved to file successfully." << endl;
    }
    else {
        cout << "Unable to open the file." << endl;
    }
}
// Function to create questions and choices
void create_quiz(char questions[][100], char choices[][answer_choices][50], char answers[]) {
    cout << "Enter the questions and choices: " << endl;
    for (int i = 0; i < total_questions; i++) {
        cout << "Question " << (i + 1) << ": ";
        cin.getline(questions[i], 100, '?');
        cout << "Choices: " << endl;
        for (int j = 0; j < answer_choices; j++) {
            cout << (j + 1) << ") ";
            cin.getline(choices[i][j], 50, '.');
            cin.ignore();
        }
        cout << "Correct answer (1-" << answer_choices << "): ";
        cin >> answers[i];
        cin.ignore();
        cout << endl;
    }
    //Call the function to save the Data in the file
    savefile(questions, choices, answers);
}
// Function to take the quiz
void take_quiz(char questions[][100], char choices[][answer_choices][50], char studentAnswers[][total_questions], int studentIDs[]) {
    cout << "--- Quiz ---" << endl;
    for (int i = 0; i < total_student; i++) {
        cout << "Enter Student ID: ";
        cin >> studentIDs[i];
        cin.ignore();
        //Take answers
        cout << "Answer the questions (Enter the option number): " << endl;
        for (int j = 0; j < total_questions; j++) {
            cout << "\n" << questions[j] << "?" << endl;
            for (int k = 0; k < answer_choices; k++) {
                cout << (k + 1) << ") " << choices[j][k] << "." << endl;
            }
            //Input Validation and Take the option in INT as requirements
            int answer;
            bool isValid = false;
            while (!isValid) {
                cout << "Your answer (1-" << answer_choices << "): ";
                cin >> answer;
                cin.ignore();
                if (answer >= 1 && answer <= answer_choices) {
                    isValid = true;
                }
                else {
                    cout << "Invalid input! Please enter a number between 1 and " << answer_choices << "." << endl;
                }
            }
            studentAnswers[i][j] = 'A' + (answer - 1);
        }
        cout << endl;
    }
}
// Function to grade the exam
void gradeExam() {
    //Intilize the Arrays
    char questions[total_questions][100];
    char choices[total_questions][answer_choices][50];
    char answers[total_questions];
    char studentAnswers[total_student][total_questions];
    int studentIDs[total_student];
    //Call the functions
    create_quiz(questions, choices, answers);
    take_quiz(questions, choices, studentAnswers, studentIDs);
    display_results(questions, answers, studentAnswers, studentIDs);
}
//Main Function
int main() {
    gradeExam();
    return 0;
}

