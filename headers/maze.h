#ifndef MAZE_H
#define MAZE_H

#include <stdbool.h>
#include "student.h" // Include the header file where Student is defined

// Global variables related to the maze
extern int **maze;
extern int num_rows, num_cols, num_keys;
extern int total_moves;
extern int recursive_calls;
extern int max_recursion_level;
extern bool found_exit;
extern int backtrack_count;

// Function declarations
void load_file(char *filename, Student *student);
bool valid_position(int row, int col, int keys);
void free_memory();

#endif // MAZE_H
