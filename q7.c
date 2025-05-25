#include <stdio.h>
#include <stdlib.h>

// Define the structure of a node
struct Node {
    int data;
    struct Node* next;
};

// Function to print the linked list
void printList(struct Node* head) {
    struct Node *p = head; // Start from the head
    while (p != NULL) {
        printf("%d -> ", p->data); // Print the data of the current node
        p = p->next; // Move to the next node
    }
    printf("NULL\n"); // End of the list
}

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

int main() {
    // Create nodes
    struct Node* head = createNode(1);
    struct Node* second = createNode(2);
    struct Node* third = createNode(3);
    struct Node* fourth = createNode(4);
    
    // Link nodes
    head->next = second;
    second->next = third;
    third->next = fourth;
    
    // Traverse and print the list
    printList(head);
    
    return 0;
}