#include <stdio.h>
#include <string.h>
#include <stdlib.h>


#define MAX_LEN 1024
#define PASS "your_password_here"


typedef struct {
    char id[MAX_LEN];
    char title[MAX_LEN];
    char content[MAX_LEN];
    int isEncrypted;
    char decryptedMessage[MAX_LEN];
} Message;

extern Message *messages;
extern int totalMessages;
extern int messageCapacity;


void edit_message() {
    
    int editIndex;
    printf("\nEnter the message index of the message you want to edit: ");
    scanf("%d", &editIndex);
    getchar(); // consume newline character

    if (editIndex < 0 || editIndex >= totalMessages) {
        printf("Invalid index entered.\n");
        return;
    }

    Message *msg = &messages[editIndex];

    if (msg->isEncrypted) {
        char pass[MAX_LEN];
        printf("This message is encrypted. Please enter the password to decrypt it: ");
        fgets(pass, MAX_LEN, stdin);
        pass[strcspn(pass, "\n")] = 0;
        
        if (strcmp(pass, PASS) != 0) {
    printf("Incorrect password. You do not have access to edit this message.\n");
    return;
}

//This block of code will display the message, ask the user for the modified version and then update it
    printf("Please see the Decrypted Message below: %s\n", msg->decryptedMessage);
    printf("Enter the new information to be added: ");
    
    char newInfo[MAX_LEN];
    fgets(newInfo, MAX_LEN, stdin);
    newInfo[strcspn(newInfo, "\n")] = 0;
    strcpy(msg->decryptedMessage, newInfo);
    printf("Your message was updated!:)");
    
//This will do the same as above but for the plain text messages
    
} else {
    printf("Please see your message below: %s\n", msg->content);
    printf("Enter the new information to be added: ");
    
    char newInfo[MAX_LEN];
    fgets(newInfo, MAX_LEN, stdin);
    newInfo[strcspn(newInfo, "\n")] = 0;
    strcpy(msg->content, newInfo);
    printf("Your message was updated!:)");
    
    
    }

}

