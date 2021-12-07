//library header for counting words
#ifndef PROBLEM5WORDS_H_INCLUDED
#define PROBLEM5WORDS_H_INCLUDED

int problem5words(FILE *filepath) {
        int count = 0;
        char word;

        while ((word = fgetc(filepath)) != EOF) {
                if (word == '\n' || word == ' ') {
                        count++;
                }
        }
        return count;
}

#endif