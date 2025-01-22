#ifndef STUDENT_H
#define STUDENT_H

#define ANALYSIS 1 // Set to 1 to enable analysis mode, 0 to disable

// Data structure for the student
typedef struct {
    int row;
    int col;
    int keys;
} Student;

// Function declarations
void move_student(Student *student, int recursion_level);

#endif // STUDENT_H
