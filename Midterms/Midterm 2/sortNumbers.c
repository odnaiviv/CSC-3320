// sortNumbers.c
// Midterm 2 Question 1
//
// program to sort the elements of a given array in ascending or descending order

#include <stdio.h>

//main method
int main() {
        double size = 11;
        int i;
        //given array
        double array[] = {10, 0.25, -2342, 12123, 3.145435, 6, 6, 5.999, -2, -5, -109.56};
        char sortingOrder;

        printf("Enter choice to sort array by (A)scending or (D)escending: ");
        scanf(" %c", &sortingOrder);
        sort_numeric(array, size, sortingOrder);
        //printing results
        printf("Array after sorting: \n");
        printArray(array, size);

        return 0;
}

//method to sort array in ascending or descending order
void sort_numeric(double *array, double size, char sortingOrder) {
        int i;
        int j;

        //checking user input for ascending order
        if (sortingOrder == 'A' || sortingOrder == 'a') {
                for (i = 0; i < size; i++) {
                        for (j = i + 1; j < size; j++) {
                                if (*(array + j) < *(array + i)) {
                                        //calling method to swap elements
                                        swapNumbers((array + i), (array + j));
                        }
                }
        }
}
        //checking user input for descending order
        else if (sortingOrder == 'D' || sortingOrder == 'd') {
                for (i = 0; i < size; i++) {
                        for (j = i + 1; j < size; j++) {
                                if (*(array + j) > *(array + i)) {
                                        //calling method to swap elements
                                        swapNumbers((array + i), (array + j));
                                }
                        }
                }
        }
}

//method to swap elements in array
void swapNumbers(double *array, double *swapped) {
        double tempArray;
        tempArray = *(array);
        *(array) = *(swapped);
        *(swapped) = tempArray;
}

//method to print result of array
void printArray(double *array, double size) {
        int i;
        for (i = 0; i < size; i++) {
                printf("%1f\t", array[i]);
        }
        printf("\n");
}
