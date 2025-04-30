#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/helper_functions.h"

char* ask_decrypt();
char* encrypt();
void modify();
int user_choice();

void modify(){
    int id;
    int found = 0;
    //asks for a stores id
    printf("Enter Message ID:");
    scanf("%d", &id);

    FILE *fptr = fopen("../data/message_storage.dat", "rb");

    if (fptr == NULL) {
        printf("Error opening file.\n");
        return;
    }

    Record rec;
    
    while (fread(&rec, sizeof(Record), 1, fptr)) {
        //finds and print the struct with the matching id
        if (rec.ID == id) {
            printf("ID: %d\n", rec.ID);
            printf("Title: %s\n", rec.title);
            printf("Message: %s\n", rec.message);
            printf("Encrypted: %d\n\n", rec.is_encrypted);
            //if the message is encrypted it asks the user if they want to decrypt it
            if(rec.is_encrypted == 1){
                printf("%s",ask_decrypt(rec));
            }

            printf("Modify message, this message will overwrite the previous:\n");
            //gets rid of left behind newlines
            getchar();  
            //gets new message from user and stores it in rec.message
            fgets(rec.message, sizeof(rec.message), stdin);
            rec.message[strcspn(rec.message, "\n")] = 0; 
            //asks user if they would like to encrypt again
            while(1){
                char key[50];
                printf("Would you like to encrypt again?:\n1.Yes\n2.No\n");
                int choice = user_choice();
                if (choice == 1){
                    printf("Enter Key: ");
                    scanf("%s", key);
                    //calls encryption and copies it to rec.message
                    char *encrypted = encrypt(rec.message, key);
                    strncpy(rec.message, encrypted, sizeof(rec.message));
                    rec.message[sizeof(rec.message) - 1] = '\0';
                    // free memory allocated in encrypt
                    free(encrypted); 
                    rec.is_encrypted = 1;
                    break;
                }
                else if(choice == 2){
                    break;
                }
            }

            // Now open the file to modify it
            FILE *fptr = fopen("../data/message_storage.dat", "rb+"); 
            if (fptr == NULL) {
                printf("Error opening file for modification.\n");
                return;
            }
            //temp rect used to modify file
            Record temp;
            while (fread(&temp, sizeof(Record), 1, fptr)) {
                if (temp.ID == rec.ID) {
                    //This moves the file pointer back by one record so it will be at the start of the record that needs to overwrite.
                    //This is beacuse the fread in line 80 moves the record forward by 1 so it will be 1 record pass the one we wnat to over write
                    fseek(fptr, -(long int)sizeof(Record), SEEK_CUR);
                    //overwriting what was in old rec
                    fwrite(&rec, sizeof(Record), 1, fptr);

                    printf("\nMessage updated successfully.\n");
                    break;
                }
            }

            fclose(fptr);
            found = 1;
        }
    }
    if (!found){
        printf("Message not Found");
    }

    fclose(fptr);

    
}

