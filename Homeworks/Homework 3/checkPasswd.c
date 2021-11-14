// checkPasswd.c
// Part 1 Question 1
//
// checking for the safty of a pw and deducting points if deductions are greater than 30 for an unsafe pw
// -5 for every character under pw length 10

#include <stdio.h>
#include <string.h>

void checkLength(char *, int *);
const char* isPasswordSafe(int);

//main method
int main() {
        char enterPass[50];
        int deductions = 0;

        printf("Enter Password: ");
        scanf("%s", &enterPass);

        checkLength(enterPass, &deductions);
        printf("%s", isPasswordSafe(deductions));

        return 0;
}

//method to check if pw length is less than 10 characters
void checkLength(char *password, int *deduct) {
        if ((int) strlen(password) < 10) {
                //-5 points for every missing character
                *deduct += (10 - ((int) strlen(password))) * 5;
        }
}

//method to check if pw is safe or not safe
const char* isPasswordSafe(int deductedPoints) {
        printf("Total Deductions: %d\n", deductedPoints);
        //pw is safe if less than 30 points are deducted
        //otherwise, pw is not safe
        return (deductedPoints > 30) ? "The password is unsafe! Please reset.\n" : "The password is safe.\n";
}
