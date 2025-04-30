/*
helper_functions.c:
Stores helper functions and constants reused throughout multiple .c files in the project.
*/

#include <stdio.h>
#include "../include/helper_functions.h"


/*
user_choice:
Retrieves and validates the user's menu input. (what)
If the input is not an integer, assigns a default error code to be handled by the menu logic. (why)

Returns:
- int: the user's menu choice, or 7 if invalid input is entered.
*/
int user_choice() {
    int choice;

    printf("Enter your choice: ");

    if (scanf("%d", &choice) != 1) {
        choice = 7;

        // Clear the input buffer to discard invalid characters
        while (getchar() != '\n');
    }

    return choice;
}
