#include <iostream>
#include <fstream>
using namespace std;

// PROTOTYPING
void storeQuizData(char[][100], char[], char[][4][100]);
void startQuiz(char[][100], char[][4][100], char[], char[][5], int);
void LetsEvaluate(char[], char[][5], int);

// MAIN BODY
int main()
{
    // ENTER NUMBER OF STUDENTS FOR QUIZ
    int NoofStudents;
    cout << "Enter the number of students: ";
    cin >> NoofStudents;
    cin.ignore();

    // DECLARE QUESTIONS AND THEIR CHOICES
    char Questions[5][100];
    char choices[20][4][100];

    // For Correct Answers use 1D
    char answers[5];

    // For Students Answers use 2D and Declare Size Using Character Pointer For Size
    char studentAnswers[5][5];

    // Function Calling
    storeQuizData(Questions, answers, choices);
    startQuiz(Questions, choices, answers, studentAnswers, NoofStudents);
    LetsEvaluate(answers, studentAnswers, NoofStudents);
    return 0;
}

void storeQuizData(char Questions[][100], char answers[], char choices[][4][100])
{
    cout << "ENTER THE FIVE QUESTIONS WITH THEIR CHOICE OPTIONS" << endl;
    cout << "TERMINATE THE QUESTION BY PRESSING '?'." << endl;
    cout << "TERMINATE THE CHOICE BY PRESSING '.'." << endl;

    ofstream file;
    file.open("Quiz.txt");

    if (!file.is_open())
    {
        cout << "FILE NOT EXIST!!" << endl;
    }
    else
    {
        for (int i = 0; i < 5; i++)
        {
            cout << "Question " << i + 1 << ": ";
            cin.getline(Questions[i], 100, '?');
            file << Questions[i] << "?" << endl;

            for (int j = 0; j < 4; j++)
            {
                cout << "Choice " << j + 1 << ": ";
                cin.getline(choices[i][j], 100, '.');
                file << choices[i][j] << "." << endl;
            }

            cout << "Enter the correct answer choice [a-d] here: ";
            cin >> answers[i];
            file << answers[i] << endl;
            cin.ignore();
        }
        file.close();
    }
}

void startQuiz(char Questions[][100], char choices[][4][100], char answers[], char studentAnswers[][5], int NoofStudents)
{
    for (int i = 0; i < NoofStudents; i++)
    {
        cout << "STUDENT " << i + 1 << " ANSWERS: " << endl;
        for (int j = 0; j < 5; j++)
        {
            cout << Questions[j] << endl;
            for (int k = 0; k < 4; k++)
            {
                cout << k + 1 << ") " << choices[j][k] << endl;
            }
            cout << "PLEASE ENTER YOUR CHOICE CAREFULLY [a-d]: ";
            cin >> studentAnswers[i][j];
            cin.ignore();
        }
        cout << endl;
    }
}

void LetsEvaluate(char answers[], char studentAnswers[][5], int NoofStudents)
{
    int falseAns[5] = { 0 };
    cout << "HERE IS THE REPORT OF EXAM " << endl;
    cout << "THE CORRECT ANSWERS KEY " << endl;
    cout << "Question 1 2 3 4 5 " << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << " " << answers[i] << "     ";
    }
    cout << endl;

    for (int i = 0; i < NoofStudents; i++)
    {
        int score = 0;
        cout << "Student " << i + 1 << " Scores:" << endl;
        cout << "ID    Score(%)" << endl;
        for (int j = 0; j < 5; j++)
        {
            if (studentAnswers[i][j] == answers[j])
            {
                score += 20;
            }
            else
            {
                falseAns[j]++;
            }
        }
        cout << i + 1 << "     " << score << endl;
    }

    cout << "HERE ARE THE NUMBER OF WRONG ANSWERS GIVEN: ";
    for (int i = 0; i < 5; i++)
    {
        cout << falseAns[i] << " ";
    }
    cout << endl;
}
