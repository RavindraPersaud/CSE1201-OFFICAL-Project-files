//a C header file that provides functions for input and output operations, such as reading from and writing to files and the console.
#include <stdio.h>
//a C header file that provides functions for memory allocation, process control, conversions, and other utility operations.
#include <stdlib.h>
//a C header file that provides functions for manipulating C-style strings and memory blocks.
#include <string.h>

//Struct for each record
typedef struct {
    int ID;
    char title[50];
    char message[288];
} Record;


/*
Delete Record by ID Function
iterates through all Record.ID in the .dat file and deletes them
*/
int delete_rec_by_id(int id){
    //Opens file in "read binary" mode
    FILE *fptr = fopen("records.dat", "rb");

    //Opens temperary file to store all records except the one with the given ID
    FILE *temp = fopen("temp.dat", "wb");

    if (fptr == NULL || temp == NULL){
        printf("Error opening files.\n");
        return 1;
    }
    //placeholder record
    Record rec;

    //Writes all records except the on with the given ID to the temperary file
    while (fread(&rec, sizeof(Record), 1, fptr)){
        if (rec.ID != id) {
            fwrite(&rec, sizeof(Record), 1, temp);
        }
    }

    fclose(fptr);
    fclose(temp);

    //Deletes old file containing the needed to be deleted record
    remove("records.dat");

    //renames temperary file to old file's name
    rename("temp.dat", "records.dat");

    //confirmation message
    printf("Record with ID %d was removed.\n", id);
    return 0;
}


/*
Delete Record by Title Function
iterates through all Record.title in the .dat file and deletes them
*/
int delete_rec_by_title(char title[]){
    //Opens file in "read binary" mode
    FILE *fptr = fopen("records.dat", "rb");

    //Opens temperary file to store all records except the one with the given title
    FILE *temp = fopen("temp.dat", "wb");

    if (fptr == NULL || temp == NULL){
        printf("Error opening files.\n");
        return 1;
    }
    //placeholder rec
    Record rec;

    //Writes all records except the on with the given title to the temperary file
    while (fread(&rec, sizeof(Record), 1, fptr)){
        if (strcmp(rec.title, title) != 0){
            fwrite(&rec, sizeof(Record), 1, temp);
        }
    }

    fclose(fptr);
    fclose(temp);

    //Deletes old file containing the needed to be deleted record 
    remove("records.dat");

    //renames temperary file to old file's name
    rename("temp.dat", "records.dat");

    //confirmation message
    printf("Record with Title %s removed.\n", title);
    return 0;
}
