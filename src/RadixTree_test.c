#include "RadixTree.c"
#include <stdio.h>

#define TRUE 1
#define FALSE 0
#define bool int

void userAddString()
{
    printf("Enter string: ");
    char inputString[1024];
    scanf("%s", &inputString);
    addStringToRadixTree(inputString);
    return;
}

void checkString()
{
    printf("Enter string: ");
    char inputString[1024];
    scanf("%s", &inputString);
    
    if(containsString(inputString))
    {
        printf("\n\n%s is inside the radix tree\n\n", inputString);
    }
    else 
    {
        printf("\n\n%s is NOT inside the radix tree\n\n", inputString);
    }

    return;
}

int main()
{
    createRadixTree();
    printf("****************Welcome to the test program for the Radix Tree****************\n\n");


    bool isRunning = TRUE;

    while(isRunning)
    {
        printf("(1) Add String (1024 characters max)\n");
        printf("(2) Check String\n");
        printf("(3) Iterate\n");
        printf("(4) Exit\n");
        printf("\n\n");

        int userInput;
        //printf("Enter: ");
        scanf("%d", &userInput);
        printf("\n\n");
        

		
		switch (userInput)
        {
            case 1:
                userAddString();
                break;
            
            case 2:
                checkString();
                break;

            case 3:
                printf("*****BEGIN*****\n");
                iterate();
                printf("******END******\n\n");
                break;

            case 4:
                isRunning = FALSE;
                break;

            default:
                printf("That is an invalid option. Please pick a different number.\n\n");
                break;
        }

        printf("\n\n");
    }

    return 0;
}