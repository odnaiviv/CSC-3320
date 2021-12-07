//library header for counting letters/characters
#ifndef PROBLEM5CHAR_H_INCLUDED
#define PROBLEM5CHAR_H_INCLUDED

int problem5char(FILE *filepath) {
        int count = 0;
        char chara;

        while ((chara = fgetc(filepath)) != EOF) {
                if (chara != '\n') {
                        count++;
                }
        }
        return count;
}

#endif