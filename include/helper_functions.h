#ifndef HELPER_H
#define HELPER_H

//constants to be used in other files to allow for easy redefinition and consistency
#define MAX_TITLE_SIZE 50
#define MAX_MESSAGE_SIZE 288

/*
struct used by .c files whose functions need to access data from the .dat file storing information on the messages.
*/
typedef struct {
    int ID;
    int is_encrypted;
    char title[MAX_TITLE_SIZE];
    char message[MAX_MESSAGE_SIZE];
} Record;


int user_choice();


#endif