#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void get_user_words(){
    char * list_of_words;
    scanf("%s", &list_of_words);

}

//Replace a word in a string with '*'
void replace_word(char *message, const char *word) {
    char *position_of_substring;
    int word_length = strlen(word);

    // Loop to find all occurrences of the word
    while ((position_of_substring = strstr(message, word)) != NULL) {
        // Replace the word with '*'
        for (int i = 0; i < word_length; i++) {
            position_of_substring[i] = '*';
        }
    }
}

int main() {
    char message[256] = "She metal on my gear till im solid: Metal Gear Solid";
    char word[50];

    printf("Original message: %s\n", message);

    // Get the word to replace from the user
    printf("Enter the word to replace: ");
    scanf("%s", word);

    // Replace the word in the message
    replace_word(message, word);

    // Print the modified message
    printf("Modified message: %s\n", message);

    return 0;
}

