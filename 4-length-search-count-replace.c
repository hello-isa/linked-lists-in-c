// Do #1: Compute the length of the linked list. If linked list is empty, return 0.
// Do #2: Use a recursive function to compute the length of linked list.
// Do #3: Search the list and check if a node matches the given value.
// Do #4: Count the number of nodes that matches the given value.
// Do #5: Replace the matched value with another value.

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

// Structure definition
typedef struct listMember
{
    int value;
    struct listMember *next;
} node;

// Function declaration
void displayList(node *headOfList);
int lengthOfList(node *headOfList);
int recursiveLengthOfList(node *headOfList);
bool isMember(node *headOfList, int findValue);
int countMatches(node *headOfList, int findValue);
void replaceMatches(node *headOfList, int value, int newValue);
void recursiveReplaceMatches(node *headOfList, int value, int newValue);

int main(){
    // node *firstNode = NULL; // This returns 0 for an empty linked list
    node *firstNode = calloc(1, sizeof(node));
    node *secondNode = calloc(1, sizeof(node));
    node *thirdNode = calloc(1, sizeof(node));

    firstNode->value = 3;
    secondNode->value = 2;
    thirdNode->value = 3;

    firstNode->next = secondNode;
    secondNode->next = thirdNode;
    thirdNode->next = NULL;

    // Function call
    displayList(firstNode);

    // Do #1
    printf("\nLength \n");
    printf("Length of the linked list: %d \n", lengthOfList(firstNode));

    // Do #2
    printf("Length of the linked list (recursion): %d \n", recursiveLengthOfList(firstNode));

    // Do #3
    printf("\nSearch \n");
    if (isMember(firstNode, 3))
    {
        printf("Found in the list. \n");
    }else
    {
        printf("Not found in the list. \n");
    }

    // Do #4
    printf("\nCount Matches \n");
    printf("Number of 1s: %d \n", countMatches(firstNode, 1));
    printf("Number of 2s: %d \n", countMatches(firstNode, 2));
    printf("Number of 3s: %d \n", countMatches(firstNode, 3));

    // Do #5
    printf("\nReplace Matches \n");
    replaceMatches(firstNode, 3, 10);
    displayList(firstNode);

    printf("\nReplace Matches (Recursive) \n");
    recursiveReplaceMatches(firstNode, 10, 5);
    displayList(firstNode);

    return 0;
}

// Function definition
void displayList(node *headOfList){
    node *currentNode = headOfList;
    int i = 1;
    
    // Traversing the linked list
    while (currentNode != NULL)
    {
        printf("Node %d: %d \n", i++, currentNode->value);
        currentNode = currentNode->next;
    }
    
}

int lengthOfList(node *headOfList){
    node *currentNode = headOfList;
    int i = 0;

    // Traversing the linked list
    while (currentNode != NULL)
    {
        i++; // Counter
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

bool isMember(node *headOfList, int findValue){
    if (headOfList == NULL) 
    {
        return false;
    } else if (headOfList->value == findValue)
    {
        return true;
    } else {
        return isMember(headOfList->next, findValue);
    }
}

int countMatches(node *headOfList, int findValue){
    if (headOfList == NULL)
    {
        return 0;
    } else if (headOfList->value == findValue)
    {
        return 1 + countMatches(headOfList->next, findValue);
    } else {
        return countMatches(headOfList->next, findValue);
    }
}

void replaceMatches(node *headOfList, int value, int newValue){
    node *currentNode = headOfList;

    while (currentNode != NULL)
    {
        if (currentNode->value == value)
        {
            currentNode->value = newValue;
        }
        currentNode = currentNode->next;
    }
}

void recursiveReplaceMatches(node *headOfList, int value, int newValue){
    while (headOfList != NULL) // This works as well: if (headOfList != NULL) 
    {
        if (headOfList->value == value)
        {
            headOfList->value = newValue;
        }
        return recursiveReplaceMatches(headOfList->next,value, newValue);
    }
}