#include <stdio.h>
#include <string.h>

int main()
{
    printf("Please enter a work or phrase you would like to search...") // ask the user to search
    fgets(input, MAX_LEN, stdin);
    input[strcspn(input, "\n")] = 0; // removes the newline character (\n) that fgets usually includes at the end of the input.
    
    for (int i = 0; i < plain_messages; i++){
        int plain_messages = strstr(messages[i].id, input) != NULL ||
        strstr(messages[i].title, input) != NULL ||
        strstr(messages[i].content, input) != NULL) 
        
        int decrypted_messages = messages[i].isEncrypted &&
            strstr(messages[i].decryptedContent, searchTerm) != NULL;{
        
        if (plain_messages || decrypted_messages)
            if (plain_messages){
            //if plain messages are found the following will print
            printf("\nPlease see your messages below\n");
            printf("Message ID: %s\n", messages[i].id);
            printf("Title: %s\n", messages[i].title);
            printf("Message Content: %s\n", messages[i].content);
            
            if (messages[i].isEncrypted)
            char password[MAX_LEN];
                printf("You have encryted messages. Please enter the password to view them: ");
                fgets(password, MAX_LEN, stdin);
                password[strcspn(password, "\n")] = 0;

                if (strcmp(password, PASSWORD) == 0) {
                    printf("\nPlease see your messages below\n");
            printf("Message ID: %s\n", messages[i].id);
            printf("Title: %s\n", messages[i].title);
            printf("Message Content: %s\n", messages[i].decryptedContent);
                } 
                else {
                    printf("You have entered the wrong password.\n");
                }
            }
            
        else {
        
        printf("You messages found")
        }

    return 0;
}
