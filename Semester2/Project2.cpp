#include <iostream>
#include<fstream>
using namespace std;
//Prototypes of the functions
void preparequiz(int, int, char[][100], char[][4][100], char[]);
void takequiz(int, int, int[], char[][100], char[][4][100], char[], char[][5]);
void displayResults(int, int, int[], char[][5], char[][100], char[]);
float calculateper(int, char[], char[]);
void savefile(char questions[][100], char choices[][4][100], char answers[]);
//File
void savefile(char questions[][100], char choices[][4][100], char answers[]) {
    ofstream file("questions.txt");
    if (file.is_open()) {
        for (int i = 0; i <5; i++) {
            file << "Question " << (i + 1) << ": " << questions[i] << "?" << endl;
            for (int j = 0; j <4; j++) {
                file << (j + 1) << ") " << choices[i][j] << "." << endl;
            }
            file << "Correct Answer: " << answers[i] << endl << endl;
        }
        cout << "Questions saved to file" << endl;
    }
    else {
        cout << "File did not open sucessfully " << endl;
    }
    file.close();
}

//Function to make a quiz
void preparequiz(int questionsno, int choicesno, char questions[][100], char choices[][4][100], char answers[])
{
    cout << "Enter the questions and choices:\n";

    for (int i = 0; i < questionsno; i++)
    {
        cout << "Question " << i + 1 << ": ";
        cin.getline(questions[i], 100, '?');

        for (int j = 0; j < choicesno; j++)
        {
            cout << "Choice " << j + 1 << ": ";
            cin.getline(choices[i][j], 100, '.');
        }

        cout << "Correct Answer: ";
        cin >> answers[i];
        cin.ignore();
        cout << endl;
    }
    savefile(questions, choices, answers);
}
//Function to take the quiz
void takequiz(int studentsno, int questionsno, int studentIds[], char questions[][100], char choices[][4][100], char answers[], char studentAnswers[][5])
{
    cout << "Enter the quiz responses for each student:\n";
    for (int i = 0; i < studentsno; i++)
    {
        cout << "Student ID: ";
        cin >> studentIds[i];
        cin.ignore();

        for (int j = 0; j < questionsno; j++)
        {
            cout << "Question " << j + 1 << ": ";
            cin >> studentAnswers[i][j];
            cin.ignore();
        }
    }
}

float calculateper(int questionsno, char stdanswer[], char solution[])
{
    int score = 0;
    for (int i = 0; i < questionsno; i++)
    {
        if (stdanswer[i] == solution[i])
        {
            score++;
        }
    }
    int percenatge;
    percenatge = (static_cast<float>(score) / questionsno) * 100;
    return percenatge;
}

void displayResults(int numStudents, int questionno, int studentIds[], char studentAnswers[][5], char questions[][100], char answers[])
{
    cout << "Students answers:\n";
    cout << "Student ID ";
    for (int i = 0; i < questionno; i++)
    {
        cout << "Q" << i + 1 << " ";
    }
    cout << endl;

    for (int i = 0; i < numStudents; i++)
    {
        cout << studentIds[i] << " ";
        for (int j = 0; j < questionno; j++)
        {
            cout << studentAnswers[i][j] << " ";
        }
        cout << endl;
    }

    cout << endl << "Exam Report :" << endl;
    cout << "Answer key " << endl;
    cout << "Question ";
    for (int i = 0; i < questionno; i++)
    {
        cout << i + 1 << " ";
    }
    cout << endl;
    cout << "Answer    ";
    for (int i = 0; i < questionno; i++)
    {
        cout << answers[i] << " ";
    }
    cout << endl;
    cout << "Student Scores :";
    cout << endl;
    cout << "ID  Score(%) ";
    cout << endl;
    for (int i = 0; i < numStudents; i++)
    {
        float percentage = calculateper(questionno, studentAnswers[i], answers);
        cout << studentIds[i] << "   " << percentage << endl;
    }

    cout << endl << "Questions Missed : " << endl;
    int missedCounts[5] = { 0 };
    for (int i = 0; i < numStudents; i++)
    {
        for (int j = 0; j < questionno; j++)
        {
            if (studentAnswers[i][j] != answers[j])
            {
                missedCounts[j]++;
            }
        }
    }

    cout << "Questions ";
    for (int i = 0; i < questionno; i++)
    {
        cout << i + 1 << " ";
    }
    cout << endl;
    cout << "Missed by  ";
    for (int i = 0; i < questionno; i++)
    {
        cout << missedCounts[i] << " ";
    }
    cout << endl;
}
//Main Function
int main()
{
    int const questionno = 5;

    int const choicesno = 4;

    int const  numStudents = 5;

    char questions[questionno][100];
    char choices[questionno][4][100];
    char answers[questionno];
    char studentAnswers[numStudents][5];
    int studentIds[numStudents];

    preparequiz(questionno, choicesno, questions, choices, answers);
    takequiz(numStudents, questionno, studentIds, questions, choices, answers, studentAnswers);
    displayResults(numStudents, questionno, studentIds, studentAnswers, questions, answers);

    return 0;
}


