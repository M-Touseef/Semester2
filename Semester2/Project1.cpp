#include <iostream>
using namespace std;
// use of global variable
const int NUM_QUESTIONS = 5;
const int NUM_CHOICES = 4;
const int NUM_STUDENTS = 5;
//Protoyypes of the function
void initialize_question(char [][100], char [][100], char []);
void takeQuiz(char questions[][100], char choices[][100], char answers[], char studentAnswers[][NUM_QUESTIONS], int numStudents,int []);
void gradeQuiz(char answers[], char studentAnswers[][NUM_QUESTIONS], int numStudents, int student_ID_No[]);

// Function to take the quiz
void takeQuiz(char questions[][100], char choices[][100], char answers[], char studentAnswers[][NUM_QUESTIONS], int numStudents,int student_ID_No[]) {
    for (int i = 0; i < numStudents; i++) {
        cout << "Student " << i + 1 << "'s answers :" << endl;
        cout << "Enter Your ID Number : ";
        cin >> student_ID_No[i];
        for (int j = 0; j < NUM_QUESTIONS; j++) {
            cout << questions[j] << endl;
            for (int k = 0; k < NUM_CHOICES; k++) {
                cout << k + 1 << ") " << choices[j * NUM_CHOICES + k] << endl;
            }
            cout << "Enter your choice (a-d): ";
            cin >> studentAnswers[i][j];
            cin.ignore();
        }
        cout << endl;
    }
}
// Function to grade the quiz and display results
void gradeQuiz(char answers[], char studentAnswers[][NUM_QUESTIONS], int numStudents,int student_ID_No[]) {
    int numMissed[NUM_QUESTIONS] = { 0 };
    cout << "Exam Report :" << endl;
    cout << "Answer key " << endl;
    cout << "Question ";
    for (int i = 0; i < NUM_QUESTIONS; i++) {
        cout << i + 1 << " ";
    }
    cout << endl;
    for (int i = 0; i < NUM_QUESTIONS; i++) {
        cout << " " << answers[i] << "     ";
    }
    cout << endl;

    cout << "Student Scores:" << endl;
    cout << "ID    Score(%)" << endl;

    for (int i = 0; i < numStudents; i++) {
        int score = 0;
        cout << i + 1 << "     ";
        for (int j = 0; j < NUM_QUESTIONS; j++) {
            if (studentAnswers[i][j] == answers[j]) {
                score += 20;
            }
            else {
                numMissed[j]++;
            }
        }
        cout << student_ID_No[i] << " ";
        cout << score << endl;
    }

    cout << "Questions Missed: ";
    for (int i = 0; i < NUM_QUESTIONS; i++) {
        cout << numMissed[i] << " ";
    }
    cout << endl;
}

int main() {

    //Delare the Arrays wuth the lehp of Global variable
    char questions[NUM_QUESTIONS][100];
    char choices[NUM_QUESTIONS * NUM_CHOICES][100];
    char answers[NUM_QUESTIONS];
    char studentAnswers[NUM_STUDENTS][NUM_QUESTIONS];
    int student_ID_No[NUM_STUDENTS];
    //Call the function to intialoze the questions
    initialize_question(questions, choices, answers);
    //Start the quiz
    takeQuiz(questions, choices, answers, studentAnswers, NUM_STUDENTS,student_ID_No);
    //Result
    gradeQuiz(answers, studentAnswers, NUM_STUDENTS,student_ID_No);

    return 0;
}
// Function to initialize questions and answers
void initialize_question(char questions[][100], char choices[][100], char answers[]) {
    cout << "Enter the 5 questions and their choices:" << endl;
    for (int i = 0; i < NUM_QUESTIONS; i++) {
        cout << "Question " << i + 1 << ": ";
        cin.getline(questions[i], 100, '?');
        cin.ignore();

        for (int j = 0; j < NUM_CHOICES; j++) {
            cout << "Choice " << j + 1 << ": ";
            cin.getline(choices[i * NUM_CHOICES + j], 100, '.');
            cin.ignore();
        }
        cout << "Enter the correct answer (a-d): ";
        cin >> answers[i];
        cin.ignore();
    }
}

