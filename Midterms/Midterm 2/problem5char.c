//function to count the number of letters in Midterm document

#include <stdio.h>
//adding library header file
#include "problem5char.h"

//method to count letters
int countCharacters(char* filepath) {
        //opening & reading file
        FILE* file = fopen(filepath, "r");
        //variable to count letters
        int count = 0;
        char chara;

        //going through entire file until eof
        while ((chara = fgetc(file)) != EOF) {
                //checking if letter is not a newline chara
                if (chara != '\n') {
                        count++;
                }
        }
        //closing file
        fclose(file);
        return count;
}