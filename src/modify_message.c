#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/helper_functions.h"

//function prototypes
char* ask_decrypt();
char* encrypt();
void modify();
int user_choice();
/*
Modify Message function
=========================
This function prompts the user to enter the id of the message they want modify
then prompts the user for the message they would like to modify it with and then
the function overwrites the previous message with the newer one.
It also prompts the user to decrypt the message if it was encrypted and also 
asks the user if they woild like to encrypt it again after input.
*/
void modify(){
    int id;
    int found = 0;
    printf("Enter Message ID:");
    scanf("%d", &id);

    FILE *fptr = fopen("../data/message_storage.dat", "rb+");

    if (fptr == NULL) {
        printf("Error opening file.\n");
        return;
    }

    Record rec;
    //reads through all structs in dat file
    while (fread(&rec, sizeof(Record), 1, fptr)) {
        //checls for given id
        if (rec.ID == id) {
            printf("ID: %d\n", rec.ID);
            printf("Title: %s\n", rec.title);
            printf("Message: %s\n", rec.message);
            printf("Encrypted: %d\n\n", rec.is_encrypted);
            //if the message is encrypted then it asks the user to decrypt it
            if(rec.is_encrypted == 1){
                printf("%s",ask_decrypt(rec));
            }

            //Asks the user to modify the message
            printf("\nModify message, this message will overwrite the previous:\n");
            //clears input buffer
            getchar();  
            //gets user input
            fgets(rec.message, sizeof(rec.message), stdin);
            //replace \n with end of line char
            rec.message[strcspn(rec.message, "\n")] = '\0'; 
            
            //Key array
            char key[MAX_KEY_SIZE];

            //Asks the user if the want to encrypt their message
            printf("Would you like to encrypt?:\n1.Yes\n2.No\n");
            int choice = user_choice();
            if (choice == 1){
                printf("Enter Key: ");
                scanf("%s", key);
                for (int i = 0; key[i] != '\0'; i++) {
                    key[i] = tolower(key[i]);
                }
                char *encrypted = encrypt(rec.message, key);
                strncpy(rec.message, encrypted, sizeof(rec.message));
                rec.message[sizeof(rec.message) - 1] = '\0';
                free(encrypted); 
                rec.is_encrypted = 1;
            } else {
                rec.is_encrypted = 0;
            }
            //move the file pointer back to the previous record
            fseek(fptr, -(long int)sizeof(Record), SEEK_CUR);
            //over writes old rec with new one
            fwrite(&rec, sizeof(Record), 1, fptr);
            printf("\nMessage updated successfully.\n");
            //updates found to 1
            found = 1;
            break;
        }
    }
    //checks if the record was found or not.
    if (!found){
        printf("Message not Found\n");
    }

    fclose(fptr);
}
