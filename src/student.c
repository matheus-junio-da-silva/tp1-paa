#include <stdio.h>
#include "../headers/maze.h"
#include "../headers/student.h"

// Function to move the student in the maze
void move_student(Student *student, int recursion_level) {
#if ANALYSIS
    // Update the global variables for analysis
    recursive_calls++;
    if (recursion_level > max_recursion_level) {
        max_recursion_level = recursion_level;
    }
#endif

    // Check if the student reached the exit
    if (student->row == 0) {
        printf("Row: %d Column: %d\n", student->row, student->col);
        printf("The student moved %d times and reached column %d of the first row.\n",
               total_moves, student->col);
        found_exit = true;
        return;
    }

    // Check if the student is out of bounds
    int current_cell = maze[student->row][student->col];
    maze[student->row][student->col] = -1;
    total_moves++;

    printf("Row: %d Column: %d\n", student->row, student->col);

    int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    // Try to move in all directions
    for (int i = 0; i < 4; i++) {
        int new_row = student->row + directions[i][0];
        int new_col = student->col + directions[i][1];
        int available_keys = student->keys;

        if (valid_position(new_row, new_col, available_keys)) {
            if (maze[new_row][new_col] == 3) {
                available_keys--;
            }
            Student new_position = {new_row, new_col, available_keys};
            //printf("Moving to new position: Row: %d, Column: %d, Keys: %d\n", new_row, new_col, available_keys);
            move_student(&new_position, recursion_level + 1); // Recursive call
            if (found_exit) return;
        }
    }

    // Backtrack
    //printf("Backtracking from position: Row: %d, Column: %d\n", student->row, student->col);
    maze[student->row][student->col] = current_cell;
    total_moves--;

    #if ANALYSIS
    backtrack_count++;
    //printf("Backtrack count incremented: %d\n", backtrack_count);
    #endif
}
