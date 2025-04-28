/*
menu_functions.c:
Handles menu information and directing the user's actions to the requested functions across program
*/
#include <stdio.h>
#include "../include/menu_functions.h"



/*
Retrieve the user's choice.
Checks the value scanf() returns. Since we use %d, scanf should return a value of 1 if the user entered an integer.

If the user did not enter an iteger, meaning choice !=1, it will convert the user's choice into a number 
The chosen number must be larger than any number int choice; could possibley equal, throughout the whole system. For 
now, 30 is larger than any choice value needed by the program.

That chosen number is then returned and the respective menu user_choice() is in handles the giving error message.

Then clear the input buffer to discard any invalid input.
*/


int user_choice(){ 
    int choice;
    printf("Enter your choice: ");

    if (scanf("%d", &choice) != 1) {
        choice = 7;
        while (getchar() != '\n'); 
    }
    
    else {
        return choice;
    }

}


/*
main_menu:
Displays the main menu options to the user by printing them using `printf()`. 
This provides a clear list of available actions, allowing users to interact with the core functionalities of the program effectively.
*/

void main_menu() {
    printf("0. Store a new note/message\n");
    printf("1. View all notes and messages.\n");
    printf("2. Search for note/message.\n");
    printf("3. Modify a previously stored note\n");
    printf("4. Delete a note/message\n");
    printf("5. Exit program\n\n");
}

/*
search_menu:
Presents search options for finding notes or messages by criteria like Title, ID, or Phrase. 
It lists these methods using `printf()`, enabling users to locate specific information efficiently based on their preferences.
*/
void search_menu() {
    printf("Do you want to search by:\n");
    printf("1. Title\n");
    printf("2. ID\n");
    printf("3. Phrase\n\n");
    printf("4. Exit to Main Menu\n");

}


/*
delete_message:
Handles the process of deleting messages by prompting users to view all IDs before deletion, asking for confirmation and the message ID 
to delete. It uses placeholders for displaying and deleting messages, providing clear instructions to prevent accidental deletions 
and enabling effective management of stored messages.
*/
void delete_message() {
    int view_messages_choice, delete_choice;
    int display_delete_message_menu = 1;
    
    while (display_delete_message_menu == 1){
        // Asks if the user wants to view all IDs before deleting a message and get their response.
        printf("Show all messages before choosing what to delete?\n\n");
        printf("1. Yes\n");
        printf("2. No\n");
        printf("Enter your choice: ");
        view_messages_choice = user_choice();

        if (view_messages_choice == 1) {
            // Placeholder for displaying all message IDs.
            printf("Displaying all message IDs...\n");
            end_of_menu();
            break;
        }
        else if (view_messages_choice == 2 ){
            end_of_menu();
            break;

        }

        else{
            printf("Invalid input! Enter 1 or 2.\n");
            end_of_menu();
        }
    }

    //Asks the user if they want to delete a message or go back to main menu.
    while(display_delete_message_menu == 1){
        printf("What would you like to do?\n\n");
        printf("1. Delete message (requires ID)\n");
        printf("2. Exit to menu\n");
        printf("Enter your choice: ");
        delete_choice = user_choice();

        //Activates delete message function. Doesn't break from loop to allow multiple deletions.
        if (delete_choice == 1) {
            // Placeholder for deleting a message
            int message_id;
            printf("Enter the ID of the message to delete: ");
            scanf("%d", &message_id);
            printf("Message with ID %d deleted.\n", message_id);
            end_of_menu();
        }

        //Go back to main menu.
        else if (delete_choice == 2) {
            printf("Returning to main menu.\n");
            end_of_menu();
            break;

        } 

        //Invalid input
        else {
            printf("Invalid input. Choose number 1 or 2.\n");
            end_of_menu();
        }
    }
    return;
}


/*
end_of_menu:
Outputs a visual separator using `printf()` to indicate the end of a menu operation. 
This helps users recognize the completion of an action and enhances readability within the user interface.
*/
void end_of_menu(){
    printf("--------------------------------------------------------------------------------\n\n");
}


