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
Store_Message Function
-------------------------
Creates structs containing ID,Title and message then
stores them in a .dat file
*/
int store_message(){
    //initializing file pointer
    FILE *fptr;
    int run = 1;

    //while loop that asks the user for ID,Title, Message then stores struct in dat file
    while(run == 1){
        //Placeholder struct
        Record rec;

        //This enter id part can be changed to a randomizer if needed
        printf("Enter ID:");
        scanf("%d", &rec.ID);
        printf("Enter Title:");
        scanf(" %[^\n]", rec.title);
        printf("Enter Message:");
        scanf(" %[^\n]", rec.message);
        //opening dat file in "append binary" mode 
        fptr = fopen("records.dat", "ab");

        //safe case 
        if (fptr == NULL) {
            printf("Error opening file\n");
            return 1;
        }

        //writes struct to dat file
        fwrite(&rec, sizeof(Record), 1, fptr);
        fclose(fptr);

        //asks the user if they want to add another recorder
        printf("Type 0 to exit, 1 to add another record: ");
        scanf("%d", &run);
        while ((getchar()) != '\n');

    }
    return 0;
}

