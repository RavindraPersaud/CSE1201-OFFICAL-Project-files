#include <stdio.h>
#include "../include/menu_functions.h"
//menu.c

//modify

void store_message();

//load messages.c
int load_messages();


int main(){
    printf("WELCOME TO OUR NOTES PROGRAM!\nSee README.md for help.\n\n");
    int main_menu_choice;
    do {
        //Get the user's choice for which function they want to use. 
        
        main_menu();
        main_menu_choice = user_choice();
        end_of_menu(); 


        // Process the choice
        switch (main_menu_choice) {
            //Take user to store message menu
            case 0:
                printf("Storing a new note/message.\n\n");
                store_message();
                end_of_menu();
                break;

            //Print all messages to the screen
            case 1:
                printf("Viewing all notes/messages\n\n");
                load_messages();
                end_of_menu();
                break;

            //Bring up the menu to choose search options and direct user to requested method
            case 2: {
                int show_search_menu = 1;

                int search_type; 
                while (show_search_menu == 1){
                    search_menu();
                    search_type = user_choice();


                    if (search_type == 1) {
                        printf("Searching by Title.\n");
                        //search function by title 
                        end_of_menu();

                    }
                    
                    else if (search_type == 2) {
                        printf("Searching by ID.\n");
                        //search function by id
                        end_of_menu();
                    } 
                    
                    else if (search_type == 3) {
                        printf("Search by phrase\n");
                        //search function by phrase.
                        end_of_menu();
                    } 
                    
                    else if (search_type == 4){
                        printf("Returning to main menu...\n");
                        end_of_menu();
                        break;          
                    }

                    else {
                        printf("Invalid search type.\n");
                        end_of_menu();
                    }
                   
                }
                //return to main menu
                break;
           }

            //Display modify menu
            case 3:
                printf("Modifying a previously stored note.\n");
                end_of_menu();
                break;


            //Display deletion menu 
            case 4:
                delete_message();  
                end_of_menu();
                break;

            //exit program
            case 5:
                printf("Exiting program...\n");
                end_of_menu();
                return 0;

            default:
                printf("Invalid input! Enter any number from 0 to 5.\n");
                end_of_menu();
        }

    }
    while (main_menu_choice != 5);     
    return 0;
}
