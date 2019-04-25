#include "RadixTree.c"
#include <stdio.h>

#define TRUE 1
#define FALSE 0
#define bool int

int main()
{
    createRadixTree();
    printf("****************Welcome to the test program for the Radix Tree****************\n\n");


    bool isRunning = TRUE;

    while(isRunning)
    {
        printf("(1) Add String\n");
        printf("(2) Check String\n");
        printf("(3) Iterate\n");
        printf("(4) Exit\n");
        printf("\n\n");

        int userInput;
        scanf("%d", &userInput);
        printf("\n\n");
        

		
		switch (userInput)
        {
            case 1:
                printf("Option 1 picked.\n\n");
                break;
            
            case 2:
                printf("Option 1 picked.\n\n");
                break;

            case 3:
                printf("Option 1 picked.\n\n");
                break;

            case 4:
                isRunning = FALSE;
                break;

            default:
                printf("That is an invalid option. Please pick a different number.\n\n");
                break;
        }
    }


    createRadixTree(); // Initiate the tree
    addStringToRadixTree("Hello, World!"); // Add string
    iterate(); // Iterate over the tree
    containsString("Hello, World!"); // Check if string is in the tree

    char name[20];
    scanf("%d", &name);

    return 0;
}