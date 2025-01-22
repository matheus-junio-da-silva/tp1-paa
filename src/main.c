#include <stdio.h>
#include <stdlib.h>
#include "../headers/maze.h"
#include "../headers/student.h"


int main() {
    int option;
    char filename[100];
    Student student;

    do {
        printf("MAZE PROGRAM: Menu Options:\n");
        printf("1) Load new data file.\n");
        printf("2) Process and display the result.\n");
        printf("3) Exit the program.\n");
        printf("Enter a number: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                printf("Please enter the filename:\n");
                scanf("%s", filename);
                load_file(filename, &student);
                printf("File loaded successfully!\n");
                break;

            case 2:
                if (!maze) {
                    printf("Please load a data file first!\n");
                } else {
                    load_file(filename, &student);  // Reset the maze
                    backtrack_count = 0;
                    total_moves = 0; 
                    found_exit = false;
                    recursive_calls = 0;
                    max_recursion_level = 0;

                    move_student(&student, 0);

                    if (!found_exit) {
                        printf("The student moved %d times and realized that the maze has no exit.\n",
                               total_moves);
                    }

#if ANALYSIS
                    printf("Total recursive calls: %d\n", recursive_calls);
                    printf("Maximum recursion level: %d\n", max_recursion_level);
                    printf("Backtracking steps: %d\n", backtrack_count);
#endif
                }
                break;

            default:
                printf("Exiting the program.\n");
                free_memory();
                exit(0);
        }
    } while (1);

    return 0;
}
