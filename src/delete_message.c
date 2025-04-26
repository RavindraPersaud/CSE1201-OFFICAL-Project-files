/* 
delete_message.c
----------------------------
Offers a user-friendly interface for message removal.
enables users to remove messages by ID or title and examine all message IDs. 
This module connects menu interactions with the backend file functions 
defined in storage.c.
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Struct for each record
typedef struct {
    int ID;
    char title[50];
    char message[288];
} Record;


/*
delete_rec_by_id
--------------------------------
Deletes a record from "records.dat" by its unique ID.
Steps: 
1.Opens temporary file to store all records except the one with the given ID
2.Writes all records except the on with the given ID to the temperary file
3.Deletes old file containing the needed to be deleted record
4.Renames temperary file to old file's name
5.confirmation message
Returns 0 on successful deletion, 1 on failure.
*/
int delete_rec_by_id(int id){

    FILE *fptr = fopen("records.dat", "rb");
   
    FILE *temp = fopen("temp.dat", "wb");

    if (fptr == NULL || temp == NULL){
        printf("Error opening files.\n");
        return 1;
    }
    
    Record rec;
   
    while (fread(&rec, sizeof(Record), 1, fptr)){
        if (rec.ID != id) {
            fwrite(&rec, sizeof(Record), 1, temp);
        }
    }

    fclose(fptr);
    fclose(temp);
    
    remove("records.dat");
    
    rename("temp.dat", "records.dat");

    printf("Record with ID %d was removed.\n", id);
    return 0;
}


/*
delete_rec_by_title
--------------------------
Deletes a record from "records.dat" by matching the title.
Steps:
1.Opens file in "read binary" mode
2.Opens temporary file to store all records except the one with the given title.
3.Writes all records except the on with the given title to the temporary file.
4.Deletes old file containing the needed to be deleted record.
5.Renames temperary file to old file's name.
6.Confirmation message.
Iterates through all Record.title in the .dat file and deletes them.
Returns 0 on successful deletion, 1 on failure.
*/
int delete_rec_by_title(char title[]){
    FILE *fptr = fopen("records.dat", "rb");

    FILE *temp = fopen("temp.dat", "wb");

    if (fptr == NULL || temp == NULL){
        printf("Error opening files.\n");
        return 1;
    }
    Record rec;
    
    while (fread(&rec, sizeof(Record), 1, fptr)){
        if (strcmp(rec.title, title) != 0){
            fwrite(&rec, sizeof(Record), 1, temp);
        }
    }

    fclose(fptr);
    fclose(temp);
    
    remove("records.dat");
   
    rename("temp.dat", "records.dat");

    printf("Record with Title %s removed.\n", title);
    return 0;
}

