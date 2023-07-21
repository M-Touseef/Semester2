#include <iostream>

const int MAX_STUDENTS = 100;
const int MAX_COURSES = 5;
const int MAX_SECTIONS = 5;
const int MAX_CODE_LENGTH = 10;

int numStudents = 0;
int numCourses = 0;
int numSections = 0;

int studentIDs[MAX_STUDENTS];
int enrolledCourses[MAX_STUDENTS][MAX_COURSES];
char sections[MAX_STUDENTS][MAX_COURSES];

char courseCodes[MAX_COURSES][MAX_CODE_LENGTH];
int courseCreditHours[MAX_COURSES];

void enrollStudent() {
    if (numStudents >= MAX_STUDENTS) {
        std::cout << "Error: Maximum number of students reached." << std::endl;
        return;
    }

    int studentID;
    std::cout << "Enter student ID: ";
    std::cin >> studentID;

    bool isEnrolled = false;
    for (int i = 0; i < numStudents; i++) {
        if (studentIDs[i] == studentID) {
            isEnrolled = true;
            break;
        }
    }

    if (isEnrolled) {
        std::cout << "Error: Student already enrolled." << std::endl;
        return;
    }

    studentIDs[numStudents] = studentID;

    std::cout << "Available courses:" << std::endl;
    for (int i = 0; i < numCourses; i++) {
        std::cout << i + 1 << ". " << courseCodes[i] << " (" << courseCreditHours[i] << " credit hours)" << std::endl;
    }

    int courseIndex;
    std::cout << "Enter the course index to enroll: ";
    std::cin >> courseIndex;

    if (courseIndex < 1 || courseIndex > numCourses) {
        std::cout << "Error: Invalid course index." << std::endl;
        return;
    }

    if (enrolledCourses[numStudents][courseIndex - 1] != 0) {
        std::cout << "Error: Student already enrolled in the selected course." << std::endl;
        return;
    }

    enrolledCourses[numStudents][courseIndex - 1] = 1;

    std::cout << "Enter the section (A, B, C, D, E): ";
    std::cin >> sections[numStudents][courseIndex - 1];

    numStudents++;

    std::cout << "Student enrolled successfully." << std::endl;
}

void dropCourse() {
    if (numStudents == 0) {
        std::cout << "Error: No students enrolled." << std::endl;
        return;
    }

    int studentID;
    std::cout << "Enter student ID: ";
    std::cin >> studentID;

    int studentIndex = -1;
    for (int i = 0; i < numStudents; i++) {
        if (studentIDs[i] == studentID) {
            studentIndex = i;
            break;
        }
    }

    if (studentIndex == -1) {
        std::cout << "Error: Student not found." << std::endl;
        return;
    }

    std::cout << "Enrolled courses for student " << studentID << ":" << std::endl;
    bool hasEnrolledCourses = false;
    for (int i = 0; i < numCourses; i++) {
        if (enrolledCourses[studentIndex][i] == 1) {
            hasEnrolledCourses = true;
            std::cout << courseCodes[i] << " (" << courseCreditHours[i] << " credit hours)" << std::endl;
        }
    }

    if (!hasEnrolledCourses) {
        std::cout << "No courses enrolled for the student." << std::endl;
        return;
    }

    int courseIndex;
    std::cout << "Enter the course index to drop: ";
    std::cin >> courseIndex;

    if (courseIndex < 1 || courseIndex > numCourses) {
        std::cout << "Error: Invalid course index." << std::endl;
        return;
    }

    if (enrolledCourses[studentIndex][courseIndex - 1] != 1) {
        std::cout << "Error: Student not enrolled in the selected course." << std::endl;
        return;
    }

    enrolledCourses[studentIndex][courseIndex - 1] = 0;
    sections[studentIndex][courseIndex - 1] = '\0';

    std::cout << "Course dropped successfully." << std::endl;
}

void listEnrolledCourses() {
    if (numStudents == 0) {
        std::cout << "Error: No students enrolled." << std::endl;
        return;
    }

    int studentID;
    std::cout << "Enter student ID: ";
    std::cin >> studentID;

    int studentIndex = -1;
    for (int i = 0; i < numStudents; i++) {
        if (studentIDs[i] == studentID) {
            studentIndex = i;
            break;
        }
    }

    if (studentIndex == -1) {
        std::cout << "Error: Student not found." << std::endl;
        return;
    }

    std::cout << "Enrolled courses for student " << studentID << ":" << std::endl;
    bool hasEnrolledCourses = false;
    for (int i = 0; i < numCourses; i++) {
        if (enrolledCourses[studentIndex][i] == 1) {
            hasEnrolledCourses = true;
            std::cout << courseCodes[i] << " (" << courseCreditHours[i] << " credit hours, Section " << sections[studentIndex][i] << ")" << std::endl;
        }
    }

    if (!hasEnrolledCourses) {
        std::cout << "No courses enrolled for the student." << std::endl;
    }
}

void updateCourseSection() {
    if (numStudents == 0) {
        std::cout << "Error: No students enrolled." << std::endl;
        return;
    }

    int studentID;
    std::cout << "Enter student ID: ";
    std::cin >> studentID;

    int studentIndex = -1;
    for (int i = 0; i < numStudents; i++) {
        if (studentIDs[i] == studentID) {
            studentIndex = i;
            break;
        }
    }

    if (studentIndex == -1) {
        std::cout << "Error: Student not found." << std::endl;
        return;
    }

    std::cout << "Enrolled courses for student " << studentID << ":" << std::endl;
    bool hasEnrolledCourses = false;
    for (int i = 0; i < numCourses; i++) {
        if (enrolledCourses[studentIndex][i] == 1) {
            hasEnrolledCourses = true;
            std::cout << i + 1 << ". " << courseCodes[i] << " (" << courseCreditHours[i] << " credit hours, Section " << sections[studentIndex][i] << ")" << std::endl;
        }
    }

    if (!hasEnrolledCourses) {
        std::cout << "No courses enrolled for the student." << std::endl;
        return;
    }

    int courseIndex;
    std::cout << "Enter the course index to update section: ";
    std::cin >> courseIndex;

    if (courseIndex < 1 || courseIndex > numCourses) {
        std::cout << "Error: Invalid course index." << std::endl;
        return;
    }

    if (enrolledCourses[studentIndex][courseIndex - 1] != 1) {
        std::cout << "Error: Student not enrolled in the selected course." << std::endl;
        return;
    }

    std::cout << "Enter the new section (A, B, C, D, E): ";
    std::cin >> sections[studentIndex][courseIndex - 1];

    std::cout << "Course section updated successfully." << std::endl;
}

void displayCourseEnrollmentCount() {
    if (numStudents == 0) {
        std::cout << "No students enrolled." << std::endl;
        return;
    }

    int courseIndex;
    std::cout << "Enter the course index: ";
    std::cin >> courseIndex;

    if (courseIndex < 1 || courseIndex > numCourses) {
        std::cout << "Error: Invalid course index." << std::endl;
        return;
    }

    int enrollmentCount = 0;
    for (int i = 0; i < numStudents; i++) {
        if (enrolledCourses[i][courseIndex - 1] == 1) {
            enrollmentCount++;
        }
    }

    std::cout << "Total number of students enrolling in course " << courseCodes[courseIndex - 1] << ": " << enrollmentCount << std::endl;
}

void displayUnenrolledCourses() {
    bool isCourseEnrolled[MAX_COURSES] = { false };

    for (int i = 0; i < numStudents; i++) {
        for (int j = 0; j < numCourses; j++) {
            if (enrolledCourses[i][j] == 1) {
                isCourseEnrolled[j] = true;
            }
        }
    }

    bool hasUnenrolledCourses = false;
    std::cout << "Unenrolled courses:" << std::endl;
    for (int i = 0; i < numCourses; i++) {
        if (!isCourseEnrolled[i]) {
            hasUnenrolledCourses = true;
            std::cout << courseCodes[i] << " (" << courseCreditHours[i] << " credit hours)" << std::endl;
        }
    }

    if (!hasUnenrolledCourses) {
        std::cout << "All courses are enrolled." << std::endl;
    }
}

void searchMinimumCoursesStudent() {
    if (numStudents == 0) {
        std::cout << "No students enrolled." << std::endl;
        return;
    }

    int minCourses = numCourses;
    int minCoursesStudentID = -1;

    for (int i = 0; i < numStudents; i++) {
        int enrolledCoursesCount = 0;
        for (int j = 0; j < numCourses; j++) {
            if (enrolledCourses[i][j] == 1) {
                enrolledCoursesCount++;
            }
        }

        if (enrolledCoursesCount < minCourses) {
            minCourses = enrolledCoursesCount;
            minCoursesStudentID = studentIDs[i];
        }
    }

    if (minCoursesStudentID == -1) {
        std::cout << "No students found." << std::endl;
    }
    else {
        std::cout << "Student with minimum number of courses: " << minCoursesStudentID << std::endl;
    }
}

int main() {
    // Course initialization
    numCourses = 5;

    // Course codes and credit hours
    char courseCode0[] = "CSCP1011";
    char courseCode1[] = "CSHU2833";
    char courseCode2[] = "CSCS2533";
    char courseCode3[] = "CSHU1893";
    char courseCode4[] = "CSSS1713";

    for (int i = 0; i < MAX_CODE_LENGTH; i++) {
        courseCodes[0][i] = courseCode0[i];
        courseCodes[1][i] = courseCode1[i];
        courseCodes[2][i] = courseCode2[i];
        courseCodes[3][i] = courseCode3[i];
        courseCodes[4][i] = courseCode4[i];
    }

    courseCreditHours[0] = 4;
    courseCreditHours[1] = 3;
    courseCreditHours[2] = 3;
    courseCreditHours[3] = 3;
    courseCreditHours[4] = 3;

    int choice;
    do {
        std::cout << "----- Menu -----" << std::endl;
        std::cout << "1. Enroll a student" << std::endl;
        std::cout << "2. Drop a course" << std::endl;
        std::cout << "3. List enrolled courses for a student" << std::endl;
        std::cout << "4. Update course section for a student" << std::endl;
        std::cout << "5. Display total number of students enrolling in a course" << std::endl;
        std::cout << "6. Display unenrolled courses" << std::endl;
        std::cout << "7. Search student with minimum number of courses" << std::endl;
        std::cout << "8. Exit" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            enrollStudent();
            break;
        case 2:
            dropCourse();
            break;
        case 3:
            listEnrolledCourses();
            break;
        case 4:
            updateCourseSection();
            break;
        case 5:
            displayCourseEnrollmentCount();
            break;
        case 6:
            displayUnenrolledCourses();
            break;
        case 7:
            searchMinimumCoursesStudent();
            break;
        case 8:
            std::cout << "Exiting program." << std::endl;
            break;
        default:
            std::cout << "Invalid choice. Please try again." << std::endl;
        }

        std::cout << std::endl;
    } while (choice != 8);

    return 0;
}