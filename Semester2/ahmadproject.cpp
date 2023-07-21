#include <iostream>
#include <fstream>
using namespace std;

// Prototyping
void StoreQuestions(char**, char**, char*);
void QuizStart(char**, char**, char*, char**, int);
void EvaluateQuiz(char*, char**, int);

// Main Body
int main()
{
    // Entering number of Students For Quiz
    int numberofStudents;
    cout << "Enter the number of students: ";
    cin >> numberofStudents;
    cin.ignore();

    // Declaring Questions And Their Choices Using 2D
    char** questions = new char* [5];
    char** choices = new char* [20];
    for (int i = 0; i < 5; i++)
    {
        questions[i] = new char[100];
    }
    for (int i = 0; i < 20; i++)
    {
        choices[i] = new char[100];
    }

    // For Correct Answers use 1D
    char* answers = new char[5];

    // For Students Answers use 2D and Declare Size Using Character Pointer For Size
    char** studentAnswers = new char* [numberofStudents];
    for (int i = 0; i < numberofStudents; i++)
    {
        studentAnswers[i] = new char[5];
    }

    // Function Calling
    StoreQuestions(questions, choices, answers);
    QuizStart(questions, choices, answers, studentAnswers, numberofStudents);
    EvaluateQuiz(answers, studentAnswers, numberofStudents);

    // Now As Our Dynamic Work Has Been Done So Delete All The Arrays
    for (int i = 0; i < 5; i++)
    {
        delete[] questions[i];
    }
    for (int i = 0; i < 20; i++)
    {
        delete[] choices[i];
    }
    delete[] questions;
    delete[] choices;
    delete[] answers;
    for (int i = 0; i < numberofStudents; i++)
    {
        delete[] studentAnswers[i];
    }
    delete[] studentAnswers;

    return 0;
}

// Function That Stores Question,Answers,CorrectChoices in File
void StoreQuestions(char** questions, char** choices, char* answers)
{
    cout << "Enter the 5 questions and their choices:" << endl;

    // Open File For Writing Data In It
    ofstream file("question_answer.txt");
    if (!file.is_open())
    {
        cout << "NO FILE FOUND!" << endl;
    }
    else
    {
        for (int i = 0; i < 5; i++)
        {
            cout << "Question " << i + 1 << ": ";
            cin.getline(questions[i], 100, '?');
            file << questions[i] << "?\n";
            for (int j = 0; j < 4; j++)
            {
                cout << "Choice " << j + 1 << ") ";
                cin.getline(choices[i * 4 + j], 100, '.');
                file << choices[i * 4 + j] << ".\n";
            }
            cout << "Enter the correct answer (a-d): ";
            cin >> answers[i];
            file << answers[i] << "\n";
        }
        file.close();
    }
}

// Function For Starting The Quiz
void QuizStart(char** questions, char** choices, char* answers, char** studentAnswers, int numStudents)
{
    for (int i = 0; i < numStudents; i++)
    {
        cout << "Student " << i + 1 << "'s answers:" << endl;
        for (int j = 0; j < 5; j++)
        {
            cout << questions[j] << endl;
            for (int k = 0; k < 4; k++)
            {
                cout << k + 1 << ") " << choices[j * 4 + k] << endl;
            }
            cout << "Enter your choice (a-d): ";
            cin >> studentAnswers[i][j];
            cin.ignore();
        }
        cout << endl;
    }
}

void EvaluateQuiz(char* answers, char** studentAnswers, int numStudents)
{
    int numMissed[5] = { 0 };
    cout << "Exam Report:" << endl;
    cout << "Answer key" << endl;
    cout << "Question 1 2 3 4 5" << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << " " << answers[i] << "     ";
    }
    cout << endl;

    for (int i = 0; i < numStudents; i++)
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
                numMissed[j]++;
            }
        }
        cout << i + 1 << "     " << score << endl;
    }

    cout << "Questions Missed: ";
    for (int i = 0; i < 5; i++)
    {
        cout << numMissed[i] << " ";
    }
    cout << endl;
}
