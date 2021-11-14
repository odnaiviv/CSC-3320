#include <stdio.h>
#include <string.h>

int main() {
	char input[20];
	char smallest[20];
	char largest[20];
	int length = 0;

	while(1) {
		printf("Enter word: ", input);
		scanf("%s", input);

		if(length == 0) {
			strcpy(smallest, input);
			strcpy(largest, input);
		}
		else {
			if(strcmp(smallest, input) > 0) {
				strcpy(smallest, input);
			}
			if(strcmp(largest, input) < 0) {
				strcpy(largest, input);
			}
		}

		length += 1;
		if(strlen(input) == 4) {
			break;
		}
	}
	printf("\nSmallest word: %s\n", smallest);
	printf("Largest word: %s\n", largest);
	return 0;
}