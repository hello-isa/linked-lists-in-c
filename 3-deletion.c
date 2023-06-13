// Do #1: Delete the first node of the linked list
// Do #2: Delete the last node of the linked list
// Do #3: Delete a node at any position in the linked list

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
void deleteFirst(node **headOfList); 
void deleteLast(node *headOfList);
void deleteAt(node **headOfList, int pos);

int main(){
    // Creating the nodes
    node *firstNode = (node *) calloc(1, sizeof(node));
    node *secondNode = (node *) calloc(1, sizeof(node));
    node *thirdNode = (node *) calloc(1, sizeof(node));
    node *fourthNode = (node *) calloc(1, sizeof(node));
    node *fifthNode = (node *) calloc(1, sizeof(node));

    // Assigning values to the nodes
    firstNode->value = 22;
    secondNode->value = 33;
    thirdNode->value = 44;
    fourthNode->value = 55;
    fifthNode->value = 66;

    // Linking each node to the next
    firstNode->next = secondNode;
    secondNode->next = thirdNode;
    thirdNode->next = fourthNode;
    fourthNode->next = fifthNode;
    fifthNode->next = NULL;

    // Function call
    displayList(firstNode);

    // Do #1
    printf("\nDelete first: \n");
    deleteFirst(&firstNode);
    displayList(firstNode);

    // Do #2
    printf("\nDelete last: \n");
    deleteLast(firstNode);
    displayList(firstNode);

    // Do #3
    printf("\nDelete at a certain position: \n");
    deleteAt(&firstNode, 2);
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

void deleteFirst(node **headOfList){
    // Assigning the what the head node points to as the new node
    *headOfList = (*headOfList)->next;
    // Freeing the head node
    free(headOfList); 
}

void deleteLast(node *headOfList){
    node *currentNode = headOfList;
    node *previousNode = NULL;

    // Traversing the list until the last node that points to null
    while (currentNode->next != NULL)
    {
        // This holds the second to the last node
        previousNode = currentNode;
        // This holds the last node
        currentNode = currentNode->next;
    }

    previousNode->next = NULL;
    // Freeing the last node
    free(currentNode);
}

// Can be used for deleteFirst and deleteLast as well
void deleteAt(node **headOfList, int pos){
    node *currentNode = (*headOfList);
    node *previousNode;
    int i = 1;

    if (pos == 1)
    {
        (*headOfList) = (*headOfList)->next;
        free(headOfList);
    } else
    {
        // Traversing the linked list until desired position
        while (i < pos)
        {
            // This is the note preceding the node to be deleted
            previousNode = currentNode;
            // This is the desired node to be deleted
            currentNode = currentNode->next;
            i++;
        }
        
        // Linking the preceding node to where the deleted node is pointing to
        previousNode->next = currentNode->next;
        // Freeing the desired node to be deleted
        free(currentNode);
    }
}