// Do #1: Create three nodes and link it
// Do #2: Traverse the linked list and print the values each node holds
#include<stdio.h>
#include<stdlib.h>

// Structure definition
typedef struct listMember{
    int value;
    struct listMember *next;
} node;

// Function declaration
void displayList(node *headOfNode);

int main(){
    // Creating the nodes in the stack
    // node firstNode;
    // node secondNode;
    // node thirdNode;

    // It is best to create nodes in the heap especially that you will perform insertion, deletion and other operation
    node *firstNode = (node *) calloc(1, sizeof(node));
    node *secondNode = (node *) calloc(1, sizeof(node));
    node *thirdNode = (node *) calloc(1, sizeof(node));

    // Assigning values to each node
    firstNode->value = 11;
    secondNode->value = 22;
    thirdNode->value = 33;

    // Linking each node to the next
    firstNode->next = secondNode;
    secondNode->next = thirdNode;
    thirdNode->next = NULL;

    // Function call
    displayList(firstNode);

    return 0;
}

// Function definition
void displayList(node *headOfNode){
    node *currentNode = headOfNode;
    int i = 1;

    while (currentNode != NULL)
    {
        printf("Node %d: %d \n", i++, currentNode->value);
        currentNode = currentNode->next;
    }
    
}

