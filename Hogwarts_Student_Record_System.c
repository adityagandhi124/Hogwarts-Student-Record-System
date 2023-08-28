//pre-processor directives 
#include <stdio.h> 
#include <string.h>
#include <ctype.h> 

#define ELEMENTS 50 //constant declared for the amount of elements in a string 

//struct data structure to house 3 char data types, 1 int data type, and a double data type
typedef struct
{
    int studentID; 
    char firstName[ELEMENTS]; 
    char lastName[ELEMENTS]; 
    char House[ELEMENTS]; 
    double GPA; 
} record; //the struct is given the nickname record. 


//all function prototypes
void hardCODE(record Records[]); 
void addSTUDENTRECORD(record Records [], int *records); 
void displaySTUDENTRECORD(record Records [], int *records); 
void addSTUDENTRECORD(record Records [], int *records); 
void lookupSTUDENTRECORD(record Records [], int *records); 
void deleteSTUDENTRECORD(record Records [], int *records); 
void printSTUDENTRECORD(record Records [], int *records); 
void hogwartsHome(int houseINPUT, char houseSTRING[]);

int main(void)
{

    record Records[ELEMENTS]; //each element in the record data type array will have a defined group of variables

    hardCODE(Records); //hardCODE function is called to populate record Records[ELEMENTS]. 

    char userINPUT; 

    int *records;
    int xyz; 
    records = &xyz; //pointer is pointing to the address of xyz
    *records = 6; //there are 6 records populated when the hardcode function is run. 

    //while loop only worlds when the user input is not E because if it is then the program will exit. 
    while(userINPUT != 'E')
    {

        //greeting to welcome the user and to prompt them with 5 choices.
        printf("Welcome to the Hogwars School Student Record System\n");
        printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"); 
        printf("What do you wanna do?\n"); 
        printf("A: Add a student record\n"); 
        printf("R: Remove a Student Record\n");  
        printf("D: Display All student records\n");
        printf("L: Lookup Student Record\n"); 
        printf("E: Exit Program\n");
        printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"); 

        scanf(" %c%*c", &userINPUT); //stores user inputer to the address of userINPUT variable
        userINPUT = toupper(userINPUT); //the user input becomes uppercase 

        //switch statement takes in the user input and tests it with 6 cases to run the corresponding statement.
        switch(userINPUT)
        {
            case 'D':
            displaySTUDENTRECORD(Records, records); //function is called 
            break; 

            case 'A':
            addSTUDENTRECORD(Records, records); 
            break; 

            case 'L':
            lookupSTUDENTRECORD(Records, records); 
            break; 

            case 'R':
            deleteSTUDENTRECORD(Records, records);
            break; 

            case 'E':
            printSTUDENTRECORD(Records, records); 
            break; 

            default: 
            printf("Invalid option. Please choose again.\n"); //this occurs when the user does not input the correct char value. 
        }


    }

    printf("The records will be saved to a text file called Records.txt have a good rest of your day\n");

    return 0; //returns 0 because the main function returns an int. 
}

//void hardCODE takes in record Records[] and populates the array with 6 records. 

void hardCODE(record Records[])
{ 
    //all char strings are declared and initialized
    char string1[ELEMENTS] = "Harry"; 
    char string2[ELEMENTS] = "Potter"; 
    char string3[ELEMENTS] = "Gryffindor"; 

    char string4[ELEMENTS] = "Ron"; 
    char string5[ELEMENTS] = "Wesley"; 
    char string6[ELEMENTS] = "Gryffindor"; 

    char string7[ELEMENTS] = "Hermoine"; 
    char string8[ELEMENTS] = "Granger"; 
    char string9[ELEMENTS] = "Gryffindor"; 

    char string10[ELEMENTS] = "Draco"; 
    char string11[ELEMENTS] = "Malfoy"; 
    char string12[ELEMENTS] = "Slytherin"; 

    char string13[ELEMENTS] = "Luna"; 
    char string14[ELEMENTS] = "Lovegood"; 
    char string15[ELEMENTS] = "Ravenclaw"; 

    char string16[ELEMENTS] = "Cedric"; 
    char string17[ELEMENTS] = "Diggory"; 
    char string18[ELEMENTS] = "Hufflepuff";
    
    record population; //the population struct has been declared. 

    population.studentID = 1; 
    strcpy(population.firstName, string1); //the strings are getting copied into the strings in the struct. 
    strcpy(population.lastName, string2); 
    strcpy(population.House, string3); 
    population.GPA = 3.87; 
    Records[0] = population; //the struct values get stored into Records[]

    population.studentID = 2; 
    strcpy(population.firstName, string4); 
    strcpy(population.lastName, string5); 
    strcpy(population.House, string6); 
    population.GPA = 3.01; 
    Records[1] = population; 

    population.studentID = 3; 
    strcpy(population.firstName, string7); 
    strcpy(population.lastName, string8); 
    strcpy(population.House, string9); 
    population.GPA = 4.00; 
    Records[2] = population; 

    population.studentID = 4; 
    strcpy(population.firstName, string10); 
    strcpy(population.lastName, string11); 
    strcpy(population.House, string12); 
    population.GPA = 2.57; 
    Records[3] = population; 

    population.studentID = 5; 
    strcpy(population.firstName, string13); 
    strcpy(population.lastName, string14); 
    strcpy(population.House, string15); 
    population.GPA = 3.42; 
    Records[4] = population; 

    population.studentID = 6; 
    strcpy(population.firstName, string16); 
    strcpy(population.lastName, string17); 
    strcpy(population.House, string18); 
    population.GPA = 3.38; 
    Records[5] = population; 
}

//void displaySTUDENTRECORD takes in an array and an address. It displays a students record. 

void displaySTUDENTRECORD(record Records [], int *records)
{
    printf("Hey there, all of the student records will be displayed, give me a moment\n"); 
    
    //the for loop will print out each record by adding one to x in every iteration. 
    for(int x = 0; x < *records; ++x)
    {
        printf("Id:          %d\n", Records[x].studentID); 
        printf("FIRST NAME:  %s\n", Records[x].firstName); 
        printf("LAST NAME:   %s\n", Records[x].lastName);
        printf("HOUSE:       %s\n", Records[x].House); 
        printf("GPA          %.2lf\n", Records[x].GPA);
        printf("\n"); 
    }
}

//void addSTUDENTRECORD takes in an array and an address. And adds a student to the record system.

void addSTUDENTRECORD(record Records[], int *records)
{

    record addition; 

    addition.studentID = *records + 1; //the ID value is added by one because a student is going to get added to the system.
    
    printf("Enter the student's first name? ");
    fgets(addition.firstName, ELEMENTS, stdin); //stores characters into the string. 
    addition.firstName[strlen(addition.firstName) - 1] = '\0'; //puts a null character at the end of the string. 

    printf("Enter the student's last name? "); 
    fgets(addition.lastName, ELEMENTS, stdin); 
    addition.lastName[strlen(addition.lastName) - 1] = '\0'; 
    
    int homeINPUT;
    printf("Please select one of the following for the student's house.\n");
    printf("1: Gryffindor\n");
    printf("2: Hufflepuff\n"); 
    printf("3: Ravenclaw\n"); 
    printf("4: Slytherin\n"); 
    printf("Enter key: ");
    scanf("%d", &homeINPUT); 

    //the while loop makes sure the input is valid to enter the switch statement. 
    while(!(homeINPUT >= 1 && homeINPUT <= 4))
    {
        printf("please choose a valid house\n");
        printf("Enter key: ");
        scanf("%d", &homeINPUT); 
    }

    
    
    char houseSTRING[100]; 
    hogwartsHome(homeINPUT, houseSTRING); 
    

    strcpy(addition.House, houseSTRING); 

  
    printf("What is %s GPA: ", addition.firstName);
    scanf("%lf", &addition.GPA); //the double value is being stores into the double GPA var in the struct. 

    Records[*records] = addition; //the array record is being updated with the addition struct. 

    (*records)++;  //the pointer value is incrementing by one because a student has been added to the system. 

}

//function looks up a student to see if he or she is in the system. 

void lookupSTUDENTRECORD(record Records [], int *records)
{
    printf("Looking up a student record.\n");
    

    int studentID; 
    printf("Hey what student ID do you want to look up: ");
    scanf("%d", &studentID);

    //while loop checks for correct input. 
    while(!(studentID > 0 && studentID < 31))
    {
        printf("There is no student with that ID registered in our system you will need to try again\n");
        printf("What ID u want to look up: ");
        scanf("%d", &studentID);
    }
    
    //prints our the record of the student based on if the student is in the school or not. 
    if(studentID < (*records + 1))
    {
        printf("Yeah there is a student with that ID in our school\n");

        printf("Id:          %d\n", Records[studentID - 1].studentID); 
        printf("FIRST NAME:  %s\n", Records[studentID - 1].firstName); 
        printf("LAST NAME:   %s\n", Records[studentID - 1].lastName);
        printf("HOUSE:       %s\n", Records[studentID - 1].House); 
        printf("GPA          %.2lf\n", Records[studentID - 1].GPA);
        printf("\n"); 

        printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");

    }
    else //prints a statement to show the student is not found in the school. 
        printf("ID %d is not found sorry!\n", studentID); 
}

//function allows the user to delete a student off of the system. 

void deleteSTUDENTRECORD(record Records[], int *records)
{
    int IDstudent; 
    int y; 
    printf("Removing the student out of the Hogwarts Insitution\n");
    printf("Time to commence the removement process\n");
    
    printf("Please input the ID of the student you wish to remove: "); 
    scanf("%d", &IDstudent);

    //while loop checks for correct input. 
    while(!(IDstudent >= 1 && IDstudent <= *records))
    {
        printf("Please try again.\n"); 
        printf("Please input the ID of the student you wish to remove: "); 
        scanf("%d", &IDstudent);
    }

    
    for(int x = 1; x <= 6; ++x)
    {
        //when x - 1 is equal to IDstudent - 1 then the array index value equals the next index value. 
        if((x - 1) == IDstudent - 1)
        {
            Records[x - 1] = Records[x]; 
            Records[x - 1].studentID = IDstudent; //the ID of the student is updated. 
        }
    }
    


    printf("3...2...1\n");
    printf("Student has been removed\n"); 
    
    (*records)--;  //decrements the pointer value by 1. 


}

/*after the user wishes the exit the program the void printSTUDENTRECORD function will save all of the students records
in a txt file*/

void printSTUDENTRECORD(record Records[], int *records)
{
    FILE *ptr1; 

    ptr1 = fopen("Records.txt", "w"); //pointer is pointing to the file in write mode. 
    fprintf(ptr1, "Hogwarts School Student Records\n"); 

    //prints all of the contents in each index of the array. 
    for(int x = 0; x < *records; ++x)
    {
        fprintf(ptr1, "ID:            %d\n", Records[x].studentID);
        fprintf(ptr1, "FIRST NAME:    %s\n", Records[x].firstName);
        fprintf(ptr1, "LAST NAME:     %s\n", Records[x].lastName); 
        fprintf(ptr1, "HOUSE:         %s\n", Records[x].House);
        fprintf(ptr1, "GPA:           %.2lf\n", Records[x].GPA);
        fprintf(ptr1, "~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");

    }

    fclose(ptr1); //pointer is closed.
}


void hogwartsHome(int houseINPUT, char houseSTRING[]) {
    
    
    switch(houseINPUT)
    {
        case 1:
            printf("Gryffindor Selected\n");
            strcpy(houseSTRING, "Gryffindor");
            break; 
        case 2:
            printf("Hufflepuff Selected\n"); 
            strcpy(houseSTRING, "Hufflepuff");
            break; 
        case 3:
            printf("Ravenclaw Selected\n");
            strcpy(houseSTRING, "Ravenclaw");
            break; 
        case 4: 
            printf("Slytherin Selected\n"); 
            strcpy(houseSTRING, "Slytherin");
            break; 
        default:
            printf("Invalid Option Please Choose again");
            strcpy(houseSTRING, "");
    }
}