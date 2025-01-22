#include <stdio.h>
#include <stdlib.h>
#include "../headers/maze.h"
#include "../headers/student.h"

// Global variables
int **maze; // 2D array to store the maze
int num_rows, num_cols, num_keys;  // Dimensions of the maze
int total_moves = 0; // Total number of moves made by the student
int recursive_calls = 0; // Total number of recursive calls made by the student
int max_recursion_level = 0; // Maximum recursion level reached by the student
bool found_exit = false; // Flag to indicate if the student found the exit
int backtrack_count = 0;

// Function to load the maze from a file
void load_file(char *filename, Student *student) { 
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Error opening the file!\n");
        exit(1);
    }

    // Read the dimensions of the maze and the number of keys
    fscanf(file, "%d %d %d", &num_rows, &num_cols, &num_keys);
    student->keys = num_keys;

    // Allocate memory for the maze
    maze = (int **)malloc(num_rows * sizeof(int *));
    for (int i = 0; i < num_rows; i++) {
        maze[i] = (int *)malloc(num_cols * sizeof(int));
    }

    // Read the maze from the file
    for (int i = 0; i < num_rows; i++) {
        for (int j = 0; j < num_cols; j++) {
            char cell;
            fscanf(file, " %c", &cell);
            maze[i][j] = cell - '0';
            if (maze[i][j] == 0) {
                student->row = i;
                student->col = j;
            }
        }
    }

    fclose(file);
}

// Function to check if a position is valid
bool valid_position(int row, int col, int keys) {
    return (row >= 0 && row < num_rows &&
            col >= 0 && col < num_cols &&
            (maze[row][col] == 1 || maze[row][col] == 0 ||
             (maze[row][col] == 3 && keys > 0)));
}

// Function to free the memory allocated for the maze
void free_memory() {
    for (int i = 0; i < num_rows; i++) {
        free(maze[i]);
    }
    free(maze);
}
