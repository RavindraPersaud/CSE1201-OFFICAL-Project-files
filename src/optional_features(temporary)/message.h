//Header File with function definition

#ifndef MESSAGE_H
#define MESSAGE_H

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

void editMessage();

#endif
