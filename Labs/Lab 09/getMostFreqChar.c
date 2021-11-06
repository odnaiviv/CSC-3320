#include <stdio.h>

void main (int argc, char *argv[]) {

        FILE *fp;
        char chara;
        char s[30] = "abcdefghijklmnopqrstuvwxyz";
        int count[30], i, max = 0, maxp = 0;

        for (i = 0; i < 30; i++)
        count[i] = 0; 
        fp = fopen(argv[1], "r");
        while ((chara = getc(fp)) != EOF) {
        	putchar(chara);
        	for (i = 0; s[i] != '\0'; i++) {
        		if(chara == s[i] || chara == (s[i] - 32))
        			count[i]++;
        	}
        }
        fclose(fp); 
        for (i = 0; s[i] != '\0'; i++)   
        if (max < count[i]) {
        	max = count[i];
        	maxp = i;
        }
        printf("The most frequent letter is '%c'. It appeared %d times.\n", s[maxp], max);
}