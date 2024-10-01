#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Morse code array for letters A-Z and digits 0-9
char *code[] = {

"~", "`", "!", "@", "#", "$", "%", "^", "&", "*", "(", ")", "_", "-", "+", "=", "|", "--" ,"}", "]", "{}", "{", "[]", "[", """", """", "", ":", ";", "?", "/", ">", ".", "<", ",", "----", "}/", ""

};

// Corresponding English alphabet and digits
char *alphabet[] = {
    "A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O",
    "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z", "0", "1", "2", "3",
    "4", "5", "6", "7", "8", "9"
};

int main() {
    char message[1000];

    printf("Enter a message to be translated: ");
    fgets(message, 1000, stdin);

    int i;

    // English to Morse code
    printf("Morse code: ");
    for (i = 0; i < strlen(message); i++) {
        if (isalpha(message[i])) {
            printf("%s ", code[toupper(message[i]) - 'A']); // Convert A-Z to Morse
        } else if (isdigit(message[i])) {
            printf("%s ", code[message[i] - '0' + 26]); // Convert 0-9 to Morse
        } else if (isspace(message[i])) {
            printf("/ "); // Use "/" to represent spaces between words in Morse
        } else {
            printf("? "); // Handle unknown characters
        }
    }

    printf("\n");

    // Morse code to English
    printf("English: ");
    char morseMessage[1000];
    strcpy(morseMessage, message); // Copy message for processing Morse to English

    // Tokenize Morse code by space
    char *token = strtok(morseMessage, " ");

    while (token != NULL) {
        if (strcmp(token, "/") == 0) {
            printf(" "); // Convert "/" back to space in English
        } else {
            // Loop through the Morse code array to find a match
            for (i = 0; i < 36; i++) { // There are 36 characters (A-Z, 0-9)
                if (strcmp(token, code[i]) == 0) {
                    printf("%s", alphabet[i]); // Print the corresponding English character
                    break;
                }
            }
        }
        token = strtok(NULL, " ");
    }

    printf("\n");

    return 0;
}

