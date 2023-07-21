#include <iostream>
using namespace std;

const int NUM_QUESTIONS = 5;
const int NUM_CHOICES = 4;
const int NUM_STUDENTS = 5;

void createQuestions(char questions[][100], char choices[][NUM_CHOICES][50], char answers[]) {
    cout << "Enter the questions and choices: " << endl;
    for (int i = 0; i < NUM_QUESTIONS; i++) {
        cout << "Question " << (i + 1) << ": ";
        cin.getline(questions[i], 100, '?');

        cout << "Choices: " << endl;
        for (int j = 0; j < NUM_CHOICES; j++) {
            cout << (j + 1) << ") ";
            cin.getline(choices[i][j], 50, '.');
            cin.ignore();
        }

        cout << "Correct answer (1-" << NUM_CHOICES << "): ";
        cin >> answers[i];
        cin.ignore();
    }
}

void takeQuiz(char questions[][100], char choices[][NUM_CHOICES][50], char answers[], char studentAnswers[][NUM_QUESTIONS], int studentIDs[]) {
    cout << "\n--- Quiz ---" << endl;
    for (int i = 0; i < NUM_STUDENTS; i++) {
        cout << "Enter Student ID: ";
        cin >> studentIDs[i];

        cout << "Answer the questions (A, B, C, or D): " << endl;
        for (int j = 0; j < NUM_QUESTIONS; j++) {
            cout << "\n" << questions[j] << "?" << endl;
            for (int k = 0; k < NUM_CHOICES; k++) {
                cout << (k + 1) << ") " << choices[j][k] << "." << endl;
            }
            cout << "Your answer (A, B, C, or D): ";
            cin >> studentAnswers[i][j];
            cin.ignore();
        }
        cout << endl;
    }
}

void displayResults(char questions[][100], char answers[], char studentAnswers[][NUM_QUESTIONS], int studentIDs[]) {
    cout << "--- Exam Report ---" << endl;

    cout << "Answer key" << endl;
    cout << "Question ";
    for (int i = 0; i < NUM_QUESTIONS; i++) {
        cout << (i + 1) << " ";
    }
    cout << endl;

    cout << "Answer    ";
    for (int i = 0; i < NUM_QUESTIONS; i++) {
        cout << answers[i] << " ";
    }
    cout << endl;

    cout << "Student Scores:" << endl;
    cout << "ID    Score(%)" << endl;

    int missedCount[NUM_QUESTIONS] = { 0 };

    for (int i = 0; i < NUM_STUDENTS; i++) {
        int score = 0;
        for (int j = 0; j < NUM_QUESTIONS; j++) {
            if (studentAnswers[i][j] == answers[j]) {
                score++;
            }
            else {
                missedCount[j]++;
            }
        }
        float percentage = static_cast<float>(score) / NUM_QUESTIONS * 100;
        cout << studentIDs[i] << "     " << percentage << endl;
    }

    cout << "Questions ";
    for (int i = 0; i < NUM_QUESTIONS; i++) {
        cout << (i + 1) << " ";
    }
    cout << endl;

    cout << "Missed by  ";
    for (int i = 0; i < NUM_QUESTIONS; i++) {
        cout << missedCount[i] << " ";
    }
    cout << endl;
}

void gradeExam() {
    char questions[NUM_QUESTIONS][100];
    char choices[NUM_QUESTIONS][NUM_CHOICES][50];
    char answers[NUM_QUESTIONS];
    char studentAnswers[NUM_STUDENTS][NUM_QUESTIONS];
    int studentIDs[NUM_STUDENTS];

    createQuestions(questions, choices, answers);
    takeQuiz(questions, choices, answers, studentAnswers, studentIDs);
    displayResults(questions, answers, studentAnswers, studentIDs);
}

int main() {
    gradeExam();
    return 0;
}
