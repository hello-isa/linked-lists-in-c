// Do #1: Compute the length of the linked list. If linked list is empty, return 0.
// Do #2: Use a recursive function to compute the length of linked list.

#include<stdio.h>
#include<stdlib.h>

// Structure definition
typedef struct listMember
{
    int value;
    struct listMember *next;
} node;

// Function declaration
int lengthOfList(node *headOfList);
int recursiveLengthOfList(node *headOfList);

int main(){
    // node *firstNode = NULL; // This returns 0 for an empty linked list
    node *firstNode = calloc(1, sizeof(node));
    node *secondNode = calloc(1, sizeof(node));
    node *thirdNode = calloc(1, sizeof(node));

    firstNode->value = 101;
    secondNode->value = 202;
    thirdNode->value = 303;

    firstNode->next = secondNode;
    secondNode->next = thirdNode;
    thirdNode->next = NULL;

    // Do #1
    int length;
    length = lengthOfList(firstNode);
    printf("Length of the linked list: %d \n", length);

    // Do #2
    int recursiveLength;
    recursiveLength = recursiveLengthOfList(firstNode);
    printf("Length of the linked list (recursion): %d \n", recursiveLength);

    return 0;
}

// Function definition
int lengthOfList(node *headOfList){
    node *currentNode = headOfList;
    int i = 0;

    // Traversing the linked list
    while (currentNode != NULL)
    {
        i++;
        currentNode = currentNode->next;
    }
    return i;
}

int recursiveLengthOfList(node *headOfList){
    if (headOfList == NULL) // Base case 
    {
        return 0;
    } else // Recursive step
    {
        return 1 + recursiveLengthOfList(headOfList->next);
    }
}