/*
main.c:
Main entry point for the notes program.
Displays the main menu and processes user input to store, view, search, modify, or delete messages.
*/

#include <stdio.h>
#include "../include/helper_functions.h"
#include "../include/menu_functions.h"
#include "../include/search_functions.h"

void modify();
int load_messages();
int store_message();

/*Function: main
----------------------------
Launches the Notes Program and Display the main menu and get user's choice until they choose to exit
Handle user's menu choice
 Main menu options:
0 – Store a new message (based on user selection)
1 – View all stored messages (displays a preview of the messages)
2 – Search for messages by title, ID, or content phrase
3 – Modify an existing message (decrypts if necessary before editing)
4 – Delete a message by ID or title
5 – Exit 
Each menu option calls a function defined in either the source(src) folders or th include folder. 
Program exits on option 5.

*/
int main() {
    printf("WELCOME TO OUR NOTES PROGRAM!\nSee README.md for help.\n\n");

    int main_menu_choice;

    do {
        
        main_menu();
        main_menu_choice = user_choice();
        end_of_menu();

       
        switch (main_menu_choice) {

            case 0:
                
                printf("Storing a new note/message.\n\n");
                store_message();
                end_of_menu();
                break;

            case 1:
               
                printf("Viewing all notes/messages\n\n");
                load_messages();
                end_of_menu();
                break;

            case 2: {
                
                int show_search_menu = 1;
                int search_type;
                
                while (show_search_menu == 1) {
                    search_menu();
                    search_type = user_choice();
                    end_of_menu();
                    
                    if (search_type == 1) {
                        printf("Searching by Title.\n");
                        search_by_title();
                        end_of_menu();
                    } 
                    
                    else if (search_type == 2) {
                        printf("Searching by ID.\n");
                        search_by_id();
                        end_of_menu();
                    } 
                    
                    else if (search_type == 3) {
                        printf("Search by phrase\n");
                        search_by_phrase();
                        end_of_menu();
                    } 
                    else if (search_type == 4) {
                        printf("Returning to main menu...\n");
                        end_of_menu();
                        break;
                    } 
                    else {
                        printf("Invalid search type.\n");
                        end_of_menu();
                    }
                }

                break;
            }

            case 3:
                
                printf("Modifying a previously stored note.\n");
                modify();
                end_of_menu();
                break;

            case 4:
                
                delete_menu();
                end_of_menu();
                break;

            case 5:
                
                printf("Exiting program...\n");
                end_of_menu();
                return 0;

            default:
                
                printf("Invalid input! Enter any number from 0 to 5.\n");
                end_of_menu();
        }

    } while (main_menu_choice != 5);

    return 0;
}
