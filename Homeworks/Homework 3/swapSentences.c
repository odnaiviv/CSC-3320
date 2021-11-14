// swapSentences.c
// Part 2 Question 4
//
// swapping two sentences with the same lengths
// when sentences have different lengths, the sentences will not swap

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swapSentences(char* string1, char* string2);

int main() {
        size_t length = 100;

        //prompting user to enter in their sentences
        printf("Enter Sentence 1: ");
        char* sentence1 = (char*)malloc(length * sizeof(char));
        getline(&sentence1, &length, stdin);
        printf("Enter Sentence 2: ");
        char* sentence2 = (char*)malloc(length * sizeof(char));
        getline(&sentence2, &length, stdin);

        //removing newline characters from both sentences
        sentence1[strlen(sentence1) - 1] = 0;
        sentence2[strlen(sentence2) - 1] = 0;

        //sentences before swapping
        printf("Before swapping...\n");
        printf("Sentence 1: %s\n", sentence1);
        printf("sentence 2: %s\n", sentence2);

        swapSentences(sentence1, sentence2);

        //sentence results after swapping
        printf("After swapping...\n");
        printf("Sentence 1: %s\n", sentence1);
        printf("sentence 2: %s\n", sentence2);

        return 0;
}

//method to swap the sentences
void swapSentences(char* string1, char* string2) {
        //checking if both sentences have the same length
        if (strlen(string1) != strlen(string2)) {
                printf("Sentences cannot be swapped due to having different lengths.\n");
                return;
        }
        //getting length of first string
        int senLen = strlen(string1);
        int i;
        for (i = 0; i < senLen; i++) {
                //swapping sentences
                string1[i] = string1[i] ^ string2[i];
                string2[i] = string1[i] ^ string2[i];
                string1[i] = string1[i] ^ string2[i];
        }
}