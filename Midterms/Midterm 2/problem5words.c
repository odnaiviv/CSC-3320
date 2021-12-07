//function to count the number of words in Midterm document

#include <stdio.h>
//adding library header file
#include "problem5words.h"

//method to count words
int countWords(char* filepath) {
        //opening & reading file
        FILE* file = fopen(filepath, "r");
        //variable to count letters
        int count = 0;
        char word;

        //going through entire file until eof
        while ((word = fgetc(file)) != EOF) {
                //checking is word is a newline or space chara
                if (word == '\n' || word == ' ') {
                        count++;
                }
        }
        //closing file
        fclose(file);
        return count;
}