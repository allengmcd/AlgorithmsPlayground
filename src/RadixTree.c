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
        if(&currentNode->children[i].data == inChar)
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
            //currentNode->children = realloc(tempChildList, currentNode->childSize * sizeof(struct node)); // Reallocate memory for the new node
			struct node *tempChildList = malloc(currentNode->childSize * sizeof(struct node));

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

int main()
{
    createRadixTree();
    addString("Hello, World!", 13);
    basicTest();
   printf("Hello, World!");

   return 0;
}