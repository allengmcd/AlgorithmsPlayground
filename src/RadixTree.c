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

            for(int j = 0; j < currentNode->childSize; j++)
            {
                if(j == currentNode->childSize - 1)
                {
                    tempChildList[j] = *newNode;
                    currentNode->children = tempChildList;
                    currentNode = &currentNode->children[j];
                }
                else 
                {
                    tempChildList[j] = currentNode->children[j];
                }
            }
        }
    }
    
    currentNode->isEndOfString = TRUE;
}

bool containsString(char *inString, int inSize)
{
    struct node *currentNode = radixTree;


    bool hitData = TRUE;
    for(int i = 0; i < inSize && hitData == TRUE; i++) 
    {
        hitData = FALSE;
        for(int j = 0; j < currentNode->childSize && hitData == FALSE; j++ ) 
        {
            struct node *tempNode = &currentNode->children[j];
            if((char)tempNode->data == inString[i])
            {
                currentNode = &currentNode->children[j];
                hitData = TRUE;
            }
        }
    }


    if(hitData && currentNode->isEndOfString == TRUE)
    {
        return TRUE;
    }

    return FALSE;
}

char* GetString(struct node *endNode)
{
    char* string;
    struct node *currentNode = endNode;

}

void IterateRadixTree(char* currentString, struct node *currentNode)
{
	char *newString = malloc((strlen(currentString)+1) * sizeof(char));
    strcat(newString, currentString);
    strcat(newString, &currentNode->data);
    strcat(newString, "\0");

    if(currentNode->isEndOfString == TRUE)
    {
        printf("%s \n", newString);
    }

    for(int i = 0; i < currentNode->childSize; i++)
    {
        IterateRadixTree(newString, &currentNode->children[i]);
    }

    return;
}

void iterate()
{
    char *start = "\0";
    for(int i = 0; i < radixTree->childSize; i++)
    {
		IterateRadixTree(start, &radixTree->children[i]);
    }
}

int main()
{
    createRadixTree();
    addString("Sad!", 4);
    addString("Bad!", 4);
    addString("Lad!", 4);
    addString("Tad!", 4);
    addString("Mad!", 4);
    iterate();

    return 0;
}