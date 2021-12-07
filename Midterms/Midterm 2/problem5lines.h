//library header for counting lines
#ifndef PROBLEM5LINES_H_INCLUDED
#define PROBLEM5LINES_H_INCLUDED

int problem5lines(FILE *filepath) {
        int count = 1;
        char line;

        while ((line = fgetc(filepath)) != EOF) {
                if (line == '\n') {
                        count++;
                }
        }
        return count;
}

#endif