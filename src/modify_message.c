#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct {
    int ID;
    int is_encrypted;
    char title[50];
    char message[288];
} Record;
void modify();

void modify(){
    int id;
    int found = 0;
    printf("Enter Message ID:");
    scanf("%d", &id);

    FILE *fptr = fopen("../data/message_storage.dat", "rb");

    if (fptr == NULL) {
        printf("Error opening file.\n");
        return;
    }

    Record rec;

    while (fread(&rec, sizeof(Record), 1, fptr)) {
        if (rec.ID == id) {
            printf("ID: %d\n", rec.ID);
            printf("Title: %s\n", rec.title);
            printf("Message: %s\n", rec.message);
            printf("Encrypted: %d\n\n", rec.is_encrypted);

            printf("Modify message, this message will overwrite the previous:\n");
    
            getchar();  // consume leftover newline from previous scanf
            fgets(rec.message, sizeof(rec.message), stdin);
            rec.message[strcspn(rec.message, "\n")] = 0; // remove newline at end if present

            // Now open the file to modify it
            FILE *fptr = fopen("../data/message_storage.dat", "rb+"); // open for read/write
            if (fptr == NULL) {
                printf("Error opening file for modification.\n");
                return;
            }

            Record temp;
            while (fread(&temp, sizeof(Record), 1, fptr)) {
                if (temp.ID == rec.ID) {
                    fseek(fptr, -(long int)sizeof(Record), SEEK_CUR);
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
