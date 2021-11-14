// palindrome.c
// Part 2 Question 3
//
// checking if user inputted message is a palindrome or not when message is read from left-to-right or right-to-left

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int checkPalindrome(char* string, int length);
void removeSpaces(char* string);
void lowercasing(char* string, int length);

int main(void) {
        printf("Enter message: ");
        //allocating space for user inputted message
        size_t messageLength = 100;
        char* message = (char*)malloc(messageLength * sizeof(char));
        getline(&message, &messageLength, stdin);

        //saving the original copy of the message
        char* originalMessage;
        strcpy(originalMessage, message);
        //removing newline character from copied message
        originalMessage[strlen(originalMessage) - 1] = '\0';
        //remove spaces in the message
        removeSpaces(message);

        //checking if user inputted message is a palindrome or not
        //and printing results
        if (checkPalindrome(message, strlen(message)))
                printf("This message is a palindrome!\n");
        else
                printf("This message is not a palindrome...\n");
        free(message);
        return 0;
}

//method to check if message is a palindrome
int checkPalindrome(char* string, int length) {
        //changing all characters in message to lower case
        lowercasing(string, length);
        //pointers for beginning and ending of string message
        int i = 0;
        int j = length - 1;

        //iterating pointers until they cross each other
        while (j > i) {
                //ignoring any special characters by shifting pointers to the next alphabetical character
                while (!isalpha(string[i]))
                        i++;
                while (!isalpha(string[j]))
                        j--;
                //checking if the beginning and ending characters are the same or not
                if (string[i] != string[j])
                        return 0;
                //moving pointers inward
                i++;
                j--;
        }
        return 1;
}

//method to remove spaces in the user inputted message
void removeSpaces(char* string) {
        int i;
        int j = 0;
        //iterating through each character and shifting to the left of any spaces, tabs, and newlines
        for (i = 0; string[i]; i++) {
                string[i] = string[i + j];
                if (string[i] == ' ' || string[i] == '\t' || string[i] == '\n') {
                        j++;
                        i--;
                }
        }
}

//method to change the characters of the user inputted message to lower case
void lowercasing(char* string, int length) {
        int i;
        for (i = 0; i < strlen(string); i++) {
                if (string[i] >= 65 && string[i] <= 90) {
                        //upper case - lower case = 32 (based on the ASCII table)
                        string[i] = (char)(string[i] + 32);
                }
        }
}