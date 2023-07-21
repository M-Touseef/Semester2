#include <iostream>
#include <fstream>
using namespace std;

// Global Constants
const int total_questions = 5;
const int answer_choices = 4;
const int total_student = 5;
// Function Prototypes
void displayAnswerKey(const char*);
void displayStudentScores(const int*);
void displayQuestionMissedCount(const int*);
void calculateStudentScores(const char*, const char**, const char**, int*);
void displayResults(const char**, const char*, const char**, int*);
//Fuinctions Prototypes
void question_solution(char*, char**, char&);
void create_questions(char**, char***, char*);
void student_answers(const char**, const char***, char**);
void saveQuestionsToFile(const char**, const char***, const char*);

// Function Definitions
void displayAnswerKey(const char* answers) {
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

void displayStudentScores(const int* studentScores) {
    cout << "Student Scores:" << endl;
    cout << "ID    Score(%)" << endl;

    for (int i = 0; i < total_student; i++) {
        cout << (i + 1) << "     " << studentScores[i] << endl;
    }
}

void displayQuestionMissedCount(const int* missedCount) {
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

void calculateStudentScores(const char* answers, const char** studentAnswers, const char** studentIDs, int* studentScores) {
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

void displayResults(const char** questions, const char* answers, const char** studentAnswers, int* studentScores) {
    cout << "--- Exam Report ---" << endl;

    displayAnswerKey(answers);
    displayStudentScores(studentScores);

    int missedCount[total_questions] = { 0 };
    for (int i = 0; i < total_student; i++) {
        for (int j = 0; j < total_questions; j++) {
            if (studentAnswers[i][j] != answers[j]) {
                missedCount[j]++;
            }
        }
    }
    displayQuestionMissedCount(missedCount);
}

void question_solution(char* question, char** choices, char& answer) {
    cout << "Question: ";
    cin.getline(question, 100, '?');
    cin.ignore();
    cout << "Choices: " << endl;
    for (int i = 0; i < answer_choices; i++) {
        cout << (i + 1) << ") ";
        cin.getline(choices[i], 50);
    }
    cout << "Enter the correct answer (a, b, c, or d): ";
    cin >> answer;
    cin.ignore();
}

void create_questions(char** questions, char*** choices, char* answers) {
    for (int i = 0; i < total_questions; i++) {
        cout << "Question " << (i + 1) << endl;
        question_solution(questions[i], choices[i], answers[i]);
        cout << endl;
    }
}

void student_answers(const char** questions, const char*** choices, char** studentAnswers) {
    for (int i = 0; i < total_student; i++) {
        cout << "Student " << (i + 1) << " answers: " << endl;
        for (int j = 0; j < total_questions; j++) {
            cout << "Question " << (j + 1) << ": " << questions[j] << endl;
            cout << "Choices: " << endl;
            for (int k = 0; k < answer_choices; k++) {
                cout << (k + 1) << ") " << choices[j][k] << endl;
            }
            cout << "Enter your answer (a, b, c, or d): ";
            cin >> studentAnswers[i][j];
            cin.ignore();
        }
        cout << endl;
    }
}

void saveQuestionsToFile(const char** questions, const char*** choices, const char* answers) {
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

int main() {
    char** questions = new char* [total_questions];
    char*** choices = new char** [total_questions];
    char* answers = new char[total_questions];
    char** studentAnswers = new char* [total_student];
    int* studentScores = new int[total_student];

    for (int i = 0; i < total_questions; i++) {
        questions[i] = new char[100];
        choices[i] = new char* [answer_choices];
        for (int j = 0; j < answer_choices; j++) {
            choices[i][j] = new char[50];
        }
    }

    for (int i = 0; i < total_student; i++) {
        studentAnswers[i] = new char[total_questions];
    }

    create_questions(questions, choices, answers);
    student_answers((const char**)questions, (const char***)choices, studentAnswers);

    calculateStudentScores(answers, (const char**)studentAnswers, nullptr, studentScores);
    displayResults((const char**)questions, answers, (const char**)studentAnswers, studentScores);

    saveQuestionsToFile((const char**)questions, (const char***)choices, answers);

    for (int i = 0; i < total_questions; i++) {
        delete[] questions[i];
        for (int j = 0; j < answer_choices; j++) {
            delete[] choices[i][j];
        }
        delete[] choices[i];
    }
    delete[] questions;
    delete[] choices;
    delete[] answers;

    for (int i = 0; i < total_student; i++) {
        delete[] studentAnswers[i];
    }
    delete[] studentAnswers;
    delete[] studentScores;

    return 0;
}
