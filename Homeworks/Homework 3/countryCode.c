// countryCode.c
// Part 3 Question 5
//
// searching for the country's international dialing code based on the user's input
// when code is found, the corresponding country name is displayed
// when code is not found, and error message is displayed

#include <stdio.h>

struct internationalCodes {
        char* country;
        int code;
};

//creating a struct array with the international dialing codes
const struct internationalCodes countryCodes[] = {
  {"Argentina",           54}, {"Bangladesh",      880},
  {"Brazil",              55}, {"Burma",            95},
  {"China",               86}, {"Colombia",         57},
  {"Dem. Rep. of Congo", 243}, {"Egypt",            20},
  {"Ethiopia",           251}, {"France",           33},
  {"Germany",             49}, {"India",            91},
  {"Indonesia",           62}, {"Iran",             98},
  {"Italy",               39}, {"Japan",            81},
  {"Mexico",              52}, {"Nigeria",         234},
  {"Pakistan",            92}, {"Phillippines",     63},
  {"Poland",              48}, {"Russia",            7},
  {"South Africa",        27}, {"South Korea",      82},
  {"Spain",               34}, {"Sudan",           249},
  {"Thailand",            66}, {"Turkey",           90},
  {"Ukraine",            380}, {"United Kingdom",   44},
  {"United States",        1}, {"Vietnam",          84} };

//displaying all country and country codes
void printCodes();

//main method
int main() {
        //finding the total number of elements in array
        int internationalCodeLength = sizeof(countryCodes) / sizeof(countryCodes[0]);
        int code;
        printf("Enter country code from the list below: \n");
        printCodes(internationalCodeLength);
        scanf("%d", &code);
        int codeFound = 0;
        int index = 0;
        int i;
        for (i = 0; i < internationalCodeLength && !codeFound; i++) {
                if (code == countryCodes[i].code) {
                        codeFound = 1;
                        index = i;
                }
        }
        //checking if code has been found
        if (codeFound) {
                printf("%s has the code #%d.\n", countryCodes[index].country, countryCodes[index].code);
        }
        //checking if code has not been found
        else {
                printf("Country with code #%d could not be found.\n", code);
        }
        return 0;
}

//method to display the country and its codes
void printCodes(int length) {
        int i;
        for (i = 0; i < length; i++) {
                printf("%s %d\n", countryCodes[i].country, countryCodes[i].code);
        }
        printf("\n");
}
