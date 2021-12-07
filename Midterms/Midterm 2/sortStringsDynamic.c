// sortStringsDynamic.c
// Midterm 2 Question 3
//
// repeating question 2, but the size of the array is unknown at the start instead of being given an array

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//main method
int main() {
    //using dynamic memory allocation to create array
    char **array = malloc(1);
    int size = 0;
    char input[15];
    int i;
    char sortingOrder;

    //prompting user to input words into array or q to stop
    printf("Enter words or (Q)uit: \n");
    do {
        scanf("%s", input);
        array = (char **)realloc(array, (size + 1) * sizeof(char *));
        array[size++] = strdup(input);
    }
    while (strcasecmp(input, "q") != 0);

    printf("Enter choice to sort array by (A)scending or (D)escending: ");
    scanf(" %c", &sortingOrder);
    sort_alphabetic(array, size - 1, sortingOrder);
    //printing results
    printf("Array after sorting: \n");
    for (i = 0; i < size; i++) {
        printf("%s\n", array[i]);
    }

    //deallocating memory for every element in array
    for (i = 0; i < size; i++) {
        free(array[i]);
    }
    //deallocating array
    free(array);
    return 0;
}

//method to sort array in ascending or descending order
void sort_alphabetic(char *array[], int size, char sortingOrder) {
    int i;
    int j;
    char* tempArray;
    int compare;

    //checking user input for ascending order
    if (sortingOrder == 'A' || sortingOrder == 'a') {
        for (i = 0; i < size; i++) {
            for (j = i + 1; j < size; j++) {
                compare = strcmp(array[i], array[j]);
                if (compare > 0) {
                    //swapping elements in array
                    tempArray = array[i];
                    array[i] = array[j];
                    array[j] = tempArray;
                }
            }
        }
    }

    //checking user input for descending order
    else if (sortingOrder == 'D' || sortingOrder == 'd') {
        for (i = 0; i < size; i++) {
            for (j = i + 1; j < size; j++) {
                compare = strcmp(array[i], array[j]);
                if (compare < 0) {
                    //swapping elements in array
                    tempArray = array[i];
                    array[i] = array[j];
                    array[j] = tempArray;
                }
            }
        }
    }
}
