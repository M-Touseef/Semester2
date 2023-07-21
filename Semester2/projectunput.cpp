#include <iostream>
using namespace std;
//Global Variable
const int total_questions = 5;
const int answer_choices = 4;
const int total_student= 5;
//Prototypes of the function
void display(char [][100], char [], char [][total_questions]);
void student_answers(char [][100], char [][answer_choices][50], char [][total_questions]);
void question_solution(char [100], char [][50], char&);
void create_questions(char [][100], char choices[][answer_choices][50], char[]);

//Input the question and its choices one by one
void question_solution(char question[100], char choices[][50], char& answer) {
    cout << "Question: ";
    //Termination condition for question ( ? )
    cin.getline(question, 100, '?');
    cout << "Choices: " << endl;
    for (int i = 0; i < answer_choices; i++) {
        cout << (i + 1) << ") ";
        //Termination condition for choices ( . )
        cin.getline(choices[i], 50, '.');
        cin.ignore();
    }
    //save the answer through reference varaible
    cout << "Correct answer (1-" << answer_choices << "): ";
    cin >> answer;
    cin.ignore();
}
//Create the Quiz
void create_questions(char questions[][100], char choices[][answer_choices][50], char answers[]) {
    cout << "Enter the questions and choices: " << endl;
    for (int i = 0; i < total_questions; i++) {
        cout << "Question " << (i + 1) << ": ";
        question_solution(questions[i], choices[i], answers[i]);
    }
}
//Take the quiz of the student
void student_answers(char questions[][100], char choices[][answer_choices][50], char studentAnswers[][total_questions]) {
    cout << "\n--- Quiz ---" << endl;
    for (int i = 0; i < total_student; i++) {
        cout << "Enter Student ID: ";
        int studentID;
        cin >> studentID;
        cin.ignore();

        cout << "Answer the questions (A, B, C, or D): " << endl;
        for (int j = 0; j < total_questions; j++) {
            cout << "\n" << questions[j] << "?" << endl;
            for (int k = 0; k < answer_choices; k++) {
                cout << (k + 1) << ") " << choices[j][k] << "." << endl;
            }

            //Input Validation
            char answer;
            bool isValid = false;
            while (!isValid) {
                cout << "Your answer (A, B, C, or D): ";
                cin >> answer;
                cin.ignore();

                if (answer >= 'A' && answer <= 'A' + answer_choices - 1) {
                    isValid = true;
                }
                else {
                    cout << "Invalid input! Please enter A, B, C, or D." << endl;
                }
            }

            studentAnswers[i][j] = answer;
        }
        cout << endl;
    }
}
//Display and Calculate the Result
void display(char questions[][100], char answers[], char studentAnswers[][total_questions]) {
    cout << "--- Exam Report ---" << endl;

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

    cout << "Student Scores:" << endl;
    cout << "ID    Score(%)" << endl;

    int missedCount[total_questions] = { 0 };

    for (int i = 0; i < total_student; i++) {
        int score = 0;
        for (int j = 0; j < total_questions; j++) {
            if (studentAnswers[i][j] == answers[j]) {
                score++;
            }
            else {
                missedCount[j]++;
            }
        }
        float percentage = static_cast<float>(score) / total_questions * 100;
        cout << (i + 1) << "     " << percentage << endl;
    }

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
//Grade Function
void gradeexam() {
    char questions[total_questions][100];
    char choices[total_questions][answer_choices][50];
    char answers[total_questions];
    char studentAnswers[total_student][total_questions];
    //Call the function
    create_questions(questions, choices, answers);
    student_answers(questions, choices, studentAnswers);
    display(questions, answers, studentAnswers);
}
//Main Function
int main() {
    //Call the grade function to execute the code
    gradeexam();
    return 0;
}
