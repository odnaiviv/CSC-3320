//function to count the number of lines in Midterm document

#include <stdio.h>
//adding library header file
#include "problem5lines.h"

//method to count lines
int countLines(char* filepath) {
        //opening & reading file
        FILE* file = fopen(filepath, "r");
        //variable to count
        int count = 1;
        char line;

        //going through entire file until eof
        while ((line = fgetc(file)) != EOF) {
                //checking if line is a newline chara
                if (line == '\n') {
                        count++;
                }
        }
        //closing file
        fclose(file);
        return count;
}