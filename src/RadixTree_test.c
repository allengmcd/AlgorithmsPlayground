#include "RadixTree.c"

int main()
{
    createRadixTree(); // Initiate the tree
    addStringToRadixTree("Hello, World!"); // Add string
    iterate(); // Iterate over the tree
    containsString("Hello, World!"); // Check if string is in the tree

    return 0;
}