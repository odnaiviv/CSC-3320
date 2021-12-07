// sortStrings.c
// Midterm 2 Question 2
//
// program that creates a string array and sorts the elements in alphabetical order, either in ascension or descension order

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//main method
int main() {
    //given array
    char* array[] = {"Systems", "Programming", "Deep", "Learning", "Internet", "Things", "Robotics", "Course"};
    int size = 8;
    int i;
    char sortingOrder;

    printf("Enter choice to sort array by (A)scending or (D)escending: ");
    scanf(" %c", &sortingOrder);
    sort_alphabetic(array, size, sortingOrder);
    //printing results
    printf("Array after sorting: \n");
    for (i = 0; i < size; i++) {
        printf("%s\n", array[i]);
    }
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
