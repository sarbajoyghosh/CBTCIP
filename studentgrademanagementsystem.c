#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 100
#define MAX_NAME_LENGTH 50
#define MAX_SUBJECTS 10

// Structure to store student information

typedef struct {
    char name[MAX_NAME_LENGTH];
    int scores[MAX_SUBJECTS];
    float average;
    int highest;
    int lowest;
} Student;
// Function to calculate statistics (average, highest, lowest scores) for a student
void calculateStatistics(Student *student, int numSubjects) {
    int total = 0;
    student->highest = student->scores[0];
    student->lowest = student->scores[0];

    for (int i = 0; i < numSubjects; i++) {
        total += student->scores[i];
        if (student->scores[i] > student->highest) {
            student->highest = student->scores[i];
        }
        if (student->scores[i] < student->lowest) {
            student->lowest = student->scores[i];
        }
    }

    student->average = (float) total / numSubjects;
}

void inputStudentInfo(Student *student, int numSubjects) {
    printf("Enter student name: ");
    scanf("%s", student->name);

    for (int i = 0; i < numSubjects; i++) {
        printf("Enter score for subject %d: ", i + 1);
        scanf("%d", &student->scores[i]);
    }
    // Calculate statistics for the student
    calculateStatistics(student, numSubjects);
}
// Function to display student information (name, scores, statistics)
void displayStudentInfo(Student *student, int numSubjects) {
    printf("Student Name: %s\n", student->name);
    printf("Scores: ");
    for (int i = 0; i < numSubjects; i++) {
        printf("%d ", student->scores[i]);
    }
    printf("\n");
    printf("Average Score: %.2f\n", student->average);
    printf("Highest Score: %d\n", student->highest);
    printf("Lowest Score: %d\n", student->lowest);
}

int main() {
    int numStudents, numSubjects;
     // Input number of students
    printf("Enter number of students: ");
    scanf("%d", &numStudents);

    if (numStudents > MAX_STUDENTS) {
        printf("Maximum number of students is %d\n", MAX_STUDENTS);
        return 1;
    }
     // Input number of subjects
    printf("Enter number of subjects: ");
    scanf("%d", &numSubjects);

    if (numSubjects > MAX_SUBJECTS) {
        printf("Maximum number of subjects is %d\n", MAX_SUBJECTS);
        return 1;
    }

    Student students[MAX_STUDENTS];
    // Input information for each student
    for (int i = 0; i < numStudents; i++) {
        printf("Enter information for student %d:\n", i + 1);
        inputStudentInfo(&students[i], numSubjects);
    }
     // Display performance summary for each student
    printf("\nStudent Performance Summary:\n");
    for (int i = 0; i < numStudents; i++) {
        printf("\nStudent %d:\n", i + 1);
        displayStudentInfo(&students[i], numSubjects);
    }

    return 0;
}
