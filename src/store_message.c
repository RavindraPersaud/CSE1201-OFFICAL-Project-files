/*
This file stores structs called records to a file.
*/
#include <stdio.h>    
#include <stdlib.h>   
#include <string.h>   
#include "../include/helper_functions.h"

// Function prototypes
int user_choice();
char* encrypt(char *message, char *key);
void store_message();
void redact();

// Struct for each record


/*
 * Store Message Function
 * Creates structs containing ID, Title and Message, then
 * stores them in a .dat file
 * User can choose to encrypt or censor message if needed
 */
void store_message() {
    //file pointer
    FILE *fptr;
    int run = 1;
    int choice;

    while (run == 1) {
        Record rec;
        int run1 = 1;
        int last_id = 0; 
        //Stres message and key
        char message[MAX_MESSAGE_SIZE];
        char key[MAX_KEY_SIZE];

        // Find the last ID
        fptr = fopen("../data/message_storage.dat", "rb");
        if (fptr != NULL) {
            //Goes to the last struct
            fseek(fptr, -(long)sizeof(Record), SEEK_END);  
            if (fread(&rec, sizeof(Record), 1, fptr) == 1) {
                //gets the id of last struct
                last_id = rec.ID;
            }
            fclose(fptr);
        }
        
        //increments id by 1
        rec.ID = last_id + 1;

        printf("Enter Title: ");
        scanf(" %50[^\n]", rec.title);
        //removes trailing spaces in title
        int len = strlen(rec.title);
        while (len > 0 && rec.title[len - 1] == ' ') {
            rec.title[--len] = '\0'; 
        }
        //gets message
        printf("Enter Message: ");
        scanf(" %288[^\n]", message);

        //asks users what they want to do with their message
        printf("\nDo you want to:\n1.Encrypt File\n2.Censor Message\n3.Store Normally\n");
        choice = user_choice();
        while(run1){
            //prompts for key and encrypts
            if(choice == 1){
                printf("Enter Key: ");
                scanf("%s", key);
                //clears buffer
                while (getchar() != '\n'); 
                //calls encrypt function
                char *encrypted = encrypt(message, key);
                strncpy(rec.message, encrypted, sizeof(rec.message));
                rec.message[sizeof(rec.message) - 1] = '\0';
                //free pointer
                free(encrypted); 
                rec.is_encrypted = 1;
                break;
            }
            else if(choice == 2){
                printf("\nCensoring message:\n");
                //copies message into rec.message then adds a EOL char at the end
                strncpy(rec.message, message, sizeof(rec.message));
                rec.message[sizeof(rec.message) - 1] = '\0';
            
                int c;
                //clears input buffer
                while ((c = getchar()) != '\n' && c != EOF); 
                //calls redact function to censor message
                redact(rec.message);
                rec.is_encrypted = 0;
                break;
            }
            else if(choice == 3){
                strncpy(rec.message, message, sizeof(rec.message));
                rec.message[sizeof(rec.message) - 1] = '\0';
                rec.is_encrypted = 0;
                break;
            }else{
                printf("Invalid input");
            }

        }
        

        // Write the full struct to file
        fptr = fopen("../data/message_storage.dat", "ab");
        if (fptr == NULL) {
            printf("Error opening file\n");
            return;
        }
        //writes struct to file
        fwrite(&rec, sizeof(Record), 1, fptr);
        fclose(fptr);
        
        printf("\n0. Exit to main menu.\n");
        printf("1. Add another record.\n");
        printf("Choice:");
        scanf("%d", &run);
        while ((getchar()) != '\n'); // Clear input buffer
    }
}




