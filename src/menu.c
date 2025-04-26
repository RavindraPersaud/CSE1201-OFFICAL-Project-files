/*
menu_functions.h:
blah blah blah blah purpose
*/
#include <stdio.h>


// Main Menu Function
// Function declarations
void main_menu();
int main_menu_choice();
int get_search_type();
void delete_message();

// Main menu loop function


// Function to display the main menu
void main_menu() {
    printf("\nWelcome, what would you like to do today?:\n");
    printf("0. Open Help Document\n");
    printf("1. View all notes/messages\n");
    printf("2. Search for and view a note/message\n");
    printf("3. Delete a note/message\n");
    printf("4. Store a new note/message\n");
    printf("5. Search notes/messages by word\n");
    printf("6. Modify a previously stored note\n");
    printf("7. Exit program\n");
    printf("---------------------------\n");
}

// Function to get the user's main menu choice
int main_menu_choice() {
    int choice;
    printf("Enter your choice: ");
    scanf("%d", &choice);
    return choice;
}

// Function to get the search type
int get_search_type() {
    int type;
    printf("Do you want to search by:\n");
    printf("1. Title\n");
    printf("2. ID\n");
    printf("Enter your choice: ");
    scanf("%d", &type);
    return type;
}

// Function to handle deleting a message
void delete_message() {
    int show_ids, delete_choice;

    // Ask if the user wants to view all IDs
    printf("Do you want to see all message IDs required to delete?\n");
    printf("1. Yes\n");
    printf("2. No\n");
    printf("Enter your choice: ");
    scanf("%d", &show_ids);

    if (show_ids == 1) {
        // Placeholder for displaying all message IDs
        printf("Displaying all message IDs...\n");
    }

    // Ask if the user wants to delete a message or exit
    printf("What would you like to do?\n");
    printf("1. Delete message (requires ID)\n");
    printf("2. Exit to menu\n");
    printf("Enter your choice: ");
    scanf("%d", &delete_choice);

    if (delete_choice == 1) {
        // Placeholder for deleting a message
        int message_id;
        printf("Enter the ID of the message to delete: ");
        scanf("%d", &message_id);
        printf("Message with ID %d deleted.\n", message_id);
    } else if (delete_choice == 2) {
        printf("Returning to main menu.\n");
    } else {
        printf("Invalid choice! Returning to main menu.\n");
    }
}

