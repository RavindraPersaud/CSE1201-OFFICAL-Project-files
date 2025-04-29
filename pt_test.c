#include <stdio.h>
//take in message, a pointer to an array of words and print them
/*
        sizeof(list) and sizeof(list[0]) measures the amount of bytes. The number of elements is therefore 
        total_bytes/bytes for 1 element.
        */

int count_elements(const char **list){
    return sizeof(list)/ sizeof(list[]);
}
char redact_message(char *message, const char **redacted_words_list){


        for (int i = 0; i< sizeof(redacted_words_list)/sizeof(redacted_words_list[0]);){
            printf("%s\n Element no.%d | %s\n\n", message[], i,  redacted_words_list[i]);
            
 
    }
}

int main(){
    const char * list[] = {"hi", "hello", "gabagoo"};
    char message[] = "she metal on my gear till im solid: Sons Of Liberty";
    
    int x = count_elements(list);
    printf("%d", x);



}