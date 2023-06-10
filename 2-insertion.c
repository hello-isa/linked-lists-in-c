// Do #1: Insert a node at the head of the linked list
// Do #2: Insert a node at the end of the linked list
// Do #3: Insert a node at a certain position of the linked list
#include<stdio.h>
#include<stdlib.h>

// Structure definition
typedef struct listMember
{
    int value;
    struct listMember *next;
} node;

// Function declaration
void displayList(node *headOfList);
void insertFirst(node **headOfList, int newValue);
void insertLast(node *headOfList, int newValue);
void insertAt(node **headOfList, int pos, int newValue);

int main(){
    // Creating the nodes in the heap
    node *firstNode = (node *) calloc(1, sizeof(node));
    node *secondNode = (node *) calloc(1, sizeof(node));

    // Assigning values to each node
    firstNode->value = 20;
    secondNode->value = 30;

    // Linking each node to the next
    firstNode->next = secondNode;
    secondNode->next = NULL;

    // Function call
    displayList(firstNode);

    // Do #1
    printf("\nInsert at head: \n");
    insertFirst(&firstNode, 18);
    displayList(firstNode);

    // Do #2
    printf("\nInsert at end: \n");
    insertLast(firstNode, 35);
    displayList(firstNode);

    // Do #3
    printf("\nInsert at a certain position: \n");
    insertAt(&firstNode, 3, 100);
    displayList(firstNode);

    return 0;
}

// Function definition
void displayList(node *headOfList){
    node *currentNode = headOfList;
    int i = 1;
    
    while (currentNode != NULL)
    {
        printf("Node %d: %d \n", i++, currentNode->value);
        currentNode = currentNode->next;
    }
    
}

void insertFirst(node **headOfList, int newValue){
    // NOTE: Double pointer is used (i.e. **headOfList) so that the changes in the head will be reflected in the main
    // Creating a new node in the heap
    node *newNode = (node *) calloc(1, sizeof(node));
    // Assigning a value to the new node
    newNode->value = newValue;
    // Connecting the new node to the existing head of the list
    newNode->next = *headOfList;
    // Making the new node the new head of the list
    *headOfList = newNode;
}

void insertLast(node *headOfList, int newValue){
    // Creating a new node in the heap
    node *newNode = (node *) calloc(1, sizeof(node));
    // Assigning a value to the new node
    newNode->value = newValue;
    // Since the new node is the last member of the list, it will be pointing to NULL
    newNode->next = NULL;

    // Traversing the linked list to locate the existing tail 
    node *currentNode = headOfList;

    while (currentNode->next != NULL)
    {
        currentNode = currentNode->next;
    }

    // Connecting the last node to the new node
    currentNode->next = newNode;
}

// insertAt can be used as a replacement for insertFirst and insertLast
void insertAt(node **headOfList, int pos, int newValue){
    // Creating a new node in the heap
    node *newNode = (node *) calloc(1, sizeof(node));
    // Assigning a value to the new node
    newNode->value = newValue;
    newNode->next = NULL; // In case the new node will be the last node

    // Traversing the linked list until the desired position
    node *currentNode = *headOfList;
    int i = 1;

    if(pos == 1){
        // Connecting the new node to the existing head of the list
        newNode->next = *headOfList;
        //Assigning the new node as the new head of the list
        (*headOfList) = newNode;
    } else {
        while (i < pos-1)
        {
            currentNode = currentNode->next;
            i++;
        }
    
    // Assigning what the current node is pointing to, to the new node
    newNode->next = currentNode->next;
    // Connecting the new node to the desired node
    currentNode->next = newNode;
    }
}
