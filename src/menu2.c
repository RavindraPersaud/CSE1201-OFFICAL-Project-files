/*
menu_functions.c:
Handles menu information and directing the user's actions to the requested functions across program
*/
#include <stdio.h>

void end_of_menu();
int delete_rec_by_title();
int delete_rec_by_id();
void load_messages();
/*
Retrieve the user's choice.
Checks the value scanf returns. Since we use %d, scanf should return a value of 1 if the user entered an integer.
If the user did not enter an iteger, meaning choice !=1, it will convert the user's choice into a number.
Then it would clear the input buffer and discard any invalid input.
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


//Display the main menu and prompt the user for thier choice

int main_menu() {
    printf("0. Store a new note/message\n");
    printf("1. View all notes and messages.\n");
    printf("2. Search for note/message.\n");
    printf("3. Modify a previously stored note\n");
    printf("4. Delete a note/message\n");
    printf("5. Exit program\n\n");
}

//Return what method the user wants to search by
void search_menu() {
    printf("Do you want to search by:\n");
    printf("1. Title\n");
    printf("2. ID\n");
    printf("3. Phrase\n\n");
    printf("4. Exit to Main Menu\n");

}


// Menu operations for deleting a message
void delete_message() {
    int view_messages_choice, delete_choice;
    int display_delete_message_menu = 1;
    
    while (display_delete_message_menu == 1){
        // Ask if the user wants to view all IDs before deleting a message and get their response.
        printf("Show all messages before choosing what to delete?\n\n");
        printf("1. Yes\n");
        printf("2. No\n");
        printf("Enter your choice: ");
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

    //Ask user if they want to delete message/go back to main menu
    while(display_delete_message_menu == 1){
        printf("What would you like to do?\n\n");
        printf("1. Delete message (requires ID)\n");
        printf("2. Exit to menu\n");
        printf("Enter your choice: ");
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


//Function that prints at the end of menus to let you know the previous menu has been closed
void end_of_menu(){
    printf("--------------------------------------------------------------------------------\n\n");
}





