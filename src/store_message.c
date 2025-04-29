#include <stdio.h>    
#include <stdlib.h>   
#include <string.h>   


// Function prototypes
int user_choice();
char* encrypt(char *message, char *key);
void store_message();

// Struct for each record
typedef struct {
    int ID;
    int is_encrypted;
    char title[50];
    char message[288];
} Record;


/*
 * Store Message Function
 * Creates structs containing ID, Title and Message, then
 * stores them in a .dat file
 */
void store_message() {
    FILE *fptr;
    int run = 1;
    int choice;

    while (run == 1) {
        Record rec;
        int run1 = 1;
        int last_id = 0; 
        char message[288];
        char key[50];

        // Find the last ID
        fptr = fopen("../data/message_storage.dat", "rb");
        if (fptr != NULL) {
            fseek(fptr, -(long)sizeof(Record), SEEK_END); //Goes to the last struct 
            if (fread(&rec, sizeof(Record), 1, fptr) == 1) {
                last_id = rec.ID;//gets the id of last struct
            }
            fclose(fptr);
        }
        

        rec.ID = last_id + 1;

        printf("Enter Title: ");
        scanf(" %50[^\n]", rec.title);

        printf("Enter Message: ");
        scanf(" %288[^\n]", message);

        printf("Do you want to:\n1.Encrypt File\n2.Censor Message\n3.Store Normally\n");
        choice = user_choice();
        while(run1){
            if(choice == 1){
                printf("Enter Key: ");
                scanf("%s", key);

                char *encrypted = encrypt(message, key);
                strncpy(rec.message, encrypted, sizeof(rec.message));
                rec.message[sizeof(rec.message) - 1] = '\0';
                free(encrypted); // free memory allocated in encrypt
                rec.is_encrypted = 1;
                break;
            }
            else if(choice == 2){
                printf("Censoring message:\n");
                strncpy(rec.message, message, sizeof(rec.message));
                rec.message[sizeof(rec.message) - 1] = '\0';
            
                int c;
                while ((c = getchar()) != '\n' && c != EOF); 
            
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

        fwrite(&rec, sizeof(Record), 1, fptr);
        fclose(fptr);

        printf("0. Exit to main menu.\n");
        printf("1. Add another record.\n");
        scanf("%d", &run);
        while ((getchar()) != '\n'); // Clear input buffer
    }
}

