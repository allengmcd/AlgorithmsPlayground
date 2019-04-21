#include <stdio.h>

#define TRUE 1
#define FALSE 0
#define bool int

struct node {
    struct node* children;
    struct node* parent;
    char data;
    int childSize;
    bool isEndOfString; 
} *radixTree;


void createRadixTree()
{
    radixTree = malloc(sizeof(struct node));
    radixTree->childSize = 0;
}

int checkChildCharacters(struct node *currentNode, char inChar)
{
    for(int i = 0; i < currentNode->childSize; i++)
    {
        if((char)currentNode->children[i].data == inChar)
        {
            return i;
        }
    }

    return -1;
}

void addString(char* inString, int inLength)
{
    struct node *currentNode = radixTree;
    for(int i = 0; i < inLength; i++)
    {
        int childNode = checkChildCharacters(currentNode, inString[i]);
        if(childNode != -1) // Character already exists
        {
            currentNode = &currentNode->children[childNode];
        }
        else // Need to create a new character
        {
            // Initialize the new Node
            struct node *newNode = malloc(sizeof(struct node));
            newNode->parent = currentNode;
            newNode->data = inString[i];
            newNode->childSize = 0;

            currentNode->childSize ++; // Increase the child count
			struct node *tempChildList = malloc(currentNode->childSize * sizeof(struct node)); // TODO(allen): right now I make a temp array, I want to just add on to the end

            for(int i = 0; i < currentNode->childSize; i++)
            {
                if(i == currentNode->childSize - 1)
                {
                    tempChildList[i] = *newNode;
                    currentNode->children = tempChildList;
                    currentNode = &currentNode->children[i];
                }
                else 
                {
                    tempChildList[i] = currentNode->children[i];
                }
            }
        }
    }
    
    currentNode->isEndOfString = TRUE;
}

void basicTest()
{
    struct node *test = radixTree;
    test = &test->children[0];
    while(TRUE)
    {
        printf("%c \n", test->data);
        if(test->childSize)
        {
            if(test->childSize == 2)
            {
                struct node temp1 = test->children[0];
                struct node temp2 = test->children[1];
                printf("%c \n", temp1.data);
                printf("%c \n", temp2.data);
            }

            test = &test->children[0];
        }
        else
        { 
            return;
        }
        
    }
}

int main()
{
    createRadixTree();
    addString("Hello, World!", 13);
    addString("He11ds4", 13);
    addString("Hello, WoXXrld!", 13);
    basicTest();
    printf("Hello, World!");

    return 0;
}