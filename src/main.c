#include <stdio.h>
void main_menu();

//menu.c
int main_menu_choice();
int get_search_type();
void delete_message();
void run_main_menu();

int main(){
    run_main_menu();
}

// Main menu loop function
void run_main_menu() {
    int choice;

    do {
        // Display the menu
        main_menu();
        
        // Get the user's choice
        choice = main_menu_choice();

        // Process the choice
        switch (choice) {
            case 0:
                printf("See README.md in root file.\n\n");
                break;
            case 1:
                printf("Storing a new note/message.\n\n");
                break;
            case 2: {
                int search_type = get_search_type();
                if (search_type == 1) {
                    printf("Searching by Title.\n");
                } else if (search_type == 2) {
                    printf("Searching by ID.\n");
                } else {
                    printf("Invalid search type.\n");
                }
                break;
            }
            case 3:
                delete_message();  // Call the delete message flow
                break;
            case 4:
                printf("Storing a new note/message.\n");
                break;
            case 5:
                printf("Searching notes/messages by word.\n");
                break;
            case 6:
                printf("Modifying a previously stored note.\n");
                break;
            case 7:
                printf("Exiting program. Goodbye!\n");
                return;  // Exit the function (and the program)
            default:
                printf("Invalid choice! Try again.\n");
        }

    } while (choice != 7);
}