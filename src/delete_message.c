/* 
delete_message.c
----------------------------
enables users to remove messages by ID or examine all message IDs. 
This module connects menu interactions with the backend file functions 
defined in storage.c.
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/helper_functions.h"



/*
delete_rec_by_id
--------------------------------
Deletes a record from "records.dat" by its unique ID.
Steps: 
1.Opens temporary file to store all records except the one with the given ID
2.Writes all records except the on with the given ID to the temperary file
3.Deletes old file containing the needed to be deleted record
4.Renames temperary file to old file's name

*/
int delete_rec_by_id(){

    int id;
    scanf("%d", &id);

    FILE *fptr = fopen("../data/message_storage.dat", "rb");
   
    FILE *temp = fopen("../data/temp.dat", "wb");

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
    
    remove("../data/message_storage.dat");
    
    rename("../data/temp.dat", "../data/message_storage.dat");

    return 0;
}





