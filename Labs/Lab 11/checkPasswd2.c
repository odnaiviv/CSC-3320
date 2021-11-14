// checkPasswd2.c
// Part 1 Question 2
//
// doing the exact same thing as Question 1, but now deducting more points!
// -5 for every character under pw length 10
// -20 for missing lowercase letters, lack of capital letters, missing numbers, and having more than 2 consecutive characters (ie. 123 or abc)

#include <stdio.h>
#include <string.h>

void checkLength(char *, int *);
//adding criteria checking method
void checkCriteria(char *, int *);
const char* isPasswordSafe(int);

//main method
int main() {
        char enterPass[50];
        int deductions = 0;

        printf("Enter Password: ");
        scanf("%s", &enterPass);

        checkLength(enterPass, &deductions);
        //adding criteria checking method
        checkCriteria(enterPass, &deductions);
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

//method to check if pw meets these criterias
void checkCriteria(char *password, int *deduct) {
        char *p = password;
        int lowercaseNum = 0;
        int capitalNum = 0;
        int numbersNum = 0;
        int consecutiveNum = 0;
        char previousChar;
        int i = 0;

        //checking pw to so if it meets these criterias
        for (i; password[i] != '\0'; i++) {
                if (password[i] >= 'a' && password[i] <= 'z')
                        lowercaseNum++;
                if (password[i] >= 'A' && password[i] <= 'Z')
                        capitalNum++;
                if (password[i] >= '0' && password[i] <= '9')
                        numbersNum++;
                if (password[i] == previousChar)
                        consecutiveNum++;
                previousChar = password[i];
        }
        //-20 for every missing lowercase letter
        if (lowercaseNum < 1)
                *deduct += 20;
        ///-20 for every missing capital letter
        if (capitalNum < 1)
                *deduct += 20;
        //-20 for every missing number
        if (numbersNum < 1)
                *deduct += 20;
        //-20 for every consecutive character
        if (consecutiveNum > 0)
                *deduct += 20;
}
