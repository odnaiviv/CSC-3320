// question5.c
// Midterm 2 Question 5 & 6
//
// program that counts the letters, words, and lines of the Midterm document
// this is the main execution program that prints the results of the functions

#include <stdio.h>

int main() {
        //directing filepath to the midterm document
        char *filepath = "midterm2.txt";

        //getting letter, word, and line count from functions
        int charas = countCharacters(filepath);
        int words = countWords(filepath);
        int lines = countLines(filepath);

        //printing results
        printf("Characters: %d\nWords: %d\nLines: %d\n", charas, words, lines);
}