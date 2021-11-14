#include <stdio.h>

char* strcpy(char*, const char*);

int main() {
	char source[] = "hello";
	char destination[100];

	printf("Source String: %s\n", source);
	printf("Copying Source String...\nDestination String: %s\n", strcpy(destination, source));
	return 0;
}

char* strcpy(char* strDest, const char* strSrc) {
	int i;
	for(i = 0; strSrc[i] != '\0'; i++)
		strDest[i] = strSrc[i];

	strDest[i] = '\0';
	return strDest;
}