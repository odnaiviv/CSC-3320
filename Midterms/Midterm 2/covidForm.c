// covidForm.c
// Midterm 2 Question 4
//
// program building a covid vaccine registration form
// upon registration, system will output a unique 8-letter alphanumeric code

#include <stdio.h>
#include <string.h>

//constructing user
struct User {
        char firstName[15];
        char lastName[15];
        char bday[10];
        char age[3];
        char gender[10];
        char doseNum[2];
        char previousDose[10];
        char vaccineType[15];
        char zipCode[5];
        char userID[9];
};

void registered(struct User);
void generate_code(struct User);
void retrive(struct User);
void displayForm();

//main method
int main() {
        //creating variables
        int userInput;
        struct User users[20];
        int numberOfUsers = 0;
        char *idInput;
        int i;

        //do-while loop prompting user to select option for registration form
        do {
                //displaying form
                displayForm();
                scanf("%d", &userInput);

                //switch-case for selecting options
                switch(userInput) {
                        case 1:
                                if (numberOfUsers >= 20) {
                                        printf("List is full.");
                                        break;
                                }
                        registered(users[numberOfUsers]);
                        numberOfUsers++;
                        break;
                        case 2:
                                printf("User ID: ");
                                scanf("%s", idInput);
                                for (i = 0; i < numberOfUsers; i++) {
                                        if (strcasecmp(idInput, users[i].userID) == 0) {
                                                retrive(users[i]);
                                        }
                                        else {
                                                printf("The ID you've entered does not exist.\n");
                                        }
                                }
                                break;
                        case 3:
                                break;
                        default:
                                printf("ERROR! Could not read input.\n");
                                break;
                }
        }
        while (userInput != 3);
        return 0;
}

//method to display contents of the form
void displayForm() {
        printf("\n - COVID Vaccine Registration Form - \n\n");
        printf("\t1\tRegister a User\n");
        printf("\t2\tDisplay Info\n");
        printf("\t3\tQuit\n\n");
        printf("\tEnter a Number: ");
}

//method to save user information in struct based on user input
void registered(struct User users) {
        char input[15];
        printf("First Name: ");
        scanf("%s", &input);
        strcpy(users.firstName, input);

        printf("Last Name: ");
        scanf("%s", &input);
        strcpy(users.lastName, input);

        printf("Date of Birth (mm/dd/yyyy): ");
        scanf("%s", &input);
        strcpy(users.bday, input);

        printf("Current Age: ");
        scanf("%s", input);
        strcpy(users.age, input);

        printf("Gender: ");
        scanf("%s", input);
        strcpy(users.gender, input);

        printf("Dose Number (1 or 2): ");
        scanf("%s", input);
        strcpy(users.doseNum, input);

        printf("Date of Previous Dose (mm/dd/yyy) or N/A: ");
        scanf("%s", input);
        strcpy(users.previousDose, input);

        printf("Type of Vaccine (Pfizer, Moderna, or Johnson&Johnson): ");
        scanf("%s", input);
        strcpy(users.vaccineType, input);

        printf("Zip Code: ");
        scanf("%s", input);
        strcpy(users.zipCode, input);

        //generates the unique alphanumeric code for user
        generate_code(users);
}

//code to generate user code
//based on first initial, last initial, current age, vaccine type initial, and last 3 numbers of zipcode
void generate_code(struct User users) {
        users.userID[0] = users.firstName[0];
        users.userID[1] = users.lastName[0];
        users.userID[2] = users.age[0];
        users.userID[3] = users.age[1];
        users.userID[4] = users.vaccineType[0];
        users.userID[5] = users.zipCode[2];
        users.userID[6] = users.zipCode[3];
        users.userID[7] = users.zipCode[4];
        users.userID[8] = '\0';

        printf("User ID: %s\n", users.userID);
}

//method to retrieve user inputted information
void retrive(struct User users) {
        printf("\nFirst Name: %s", users.firstName);
        printf("\nLast Name: %s", users.lastName);
        printf("\nDate of Birth: %s", users.bday);
        printf("\nCurrent Age: %s", users.age);
        printf("\nGender: %s", users.gender);
        printf("\nDose Number: %s", users.doseNum);
        printf("\nDate of Previous Dose: %s", users.previousDose);
        printf("\nType of Vaccine: %s", users.vaccineType);
        printf("\nZip Code: %s\n", users.zipCode);
}