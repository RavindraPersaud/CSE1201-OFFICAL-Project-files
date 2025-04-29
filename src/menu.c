/*
menu_functions.c

Handles menu information and directs the user's actions to the requested functions across the program.

*/

#include <stdio.h>
#include "../include/menu_functions.h"

int delete_rec_by_id();
void load_messages();


/*
user_choice
Retrieve the user's choice.
Checks the value scanf() returns. Since we use %d, scanf should return a value of 1 if the user entered an integer.

If the user did not enter an integer (choice != 1), it will convert the user's choice into a number.
The chosen number must be larger than any number int choice could possibly equal throughout the system.
For now, 30 is larger than any choice value needed by the program.

That chosen number is then returned, and the respective menu handles giving the error message.

Clears the input buffer to discard any invalid input.
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
main_menu
Display the main menu and prompt the user for their choice.
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
search_menu
Return what method the user wants to search by.
*/
void search_menu() {
    printf("Do you want to search by:\n");
    printf("1. Title\n");
    printf("2. ID\n");
    printf("3. Phrase\n\n");
    printf("4. Exit to Main Menu\n");

}


/*
delete_message
Menu operations for deleting a message.
Allows the user to view all messages before deleting, 
then choose whether to delete a message or return to main menu.
*/
void delete_menu() {
    int view_messages_choice, delete_choice;
    int display_delete_message_menu = 1;
    
    while (display_delete_message_menu == 1){

         /* 
        Ask if the user wants to view all IDs before deleting a message and get their response.
        */
        printf("Show all messages before choosing what to delete?\n\n");
        printf("1. Yes\n");
        printf("2. No\n");
        view_messages_choice = user_choice();

        if (view_messages_choice == 1) {
            // Placeholder for displaying all message IDs
            printf("Displaying all message IDs...\n");
            load_messages();
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

     /*
    Ask user if they want to delete a message or go back to the main menu.
    */
    while(display_delete_message_menu == 1){
        printf("What would you like to do?\n\n");
        printf("1. Delete message (requires ID)\n");
        printf("2. Exit to menu\n");
        delete_choice = user_choice();

        //Activate delete message function. Doesn't  break from loop to allow multiple deletions.
        if (delete_choice == 1) {
            // Placeholder for deleting a message
            printf("Enter the ID of the message to delete: ");
            delete_rec_by_id();
            printf("Message deleted.\n");
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
end_of_menu
Function that prints at the end of menus to indicate the previous menu has been closed.
*/
void end_of_menu(){
    printf("--------------------------------------------------------------------------------\n\n");
}




