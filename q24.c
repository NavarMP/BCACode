#include <stdio.h>
#include <stdlib.h>

// Define the structure for a doubly linked list node
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

// Function to insert at the beginning of the doubly linked list
void insertAtBeginning(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    
    if (*head == NULL) {
        *head = newNode;
    } else {
        newNode->next = *head;
        (*head)->prev = newNode;
        *head = newNode;
    }
}

// Function to insert at the end of the doubly linked list
void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* temp = *head;
        
        while (temp->next != NULL) {
            temp = temp->next;
        }
        
        temp->next = newNode;
        newNode->prev = temp;
    }
}

// Function to delete a node from the beginning
void deleteFromBeginning(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }
    
    struct Node* temp = *head;
    *head = (*head)->next;
    
    if (*head != NULL) {
        (*head)->prev = NULL;
    }
    
    free(temp);
}

// Function to delete a node from the end
void deleteFromEnd(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }
    
    struct Node* temp = *head;
    
    while (temp->next != NULL) {
        temp = temp->next;
    }
    
    if (temp->prev != NULL) {
        temp->prev->next = NULL;
    } else {
        *head = NULL; // If there's only one node
    }
    
    free(temp);
}

// Function to print the list from beginning to end
void printForward(struct Node* head) {
    struct Node* temp = head;
    
    printf("List in Forward Direction: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    
    printf("\n");
}

// Function to print the list from end to beginning
void printBackward(struct Node* head) {
    struct Node* temp = head;
    
    if (temp == NULL) {
        printf("List is empty.\n");
        return;
    }
    
    while (temp->next != NULL) {
        temp = temp->next;
    }
    
    printf("List in Backward Direction: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->prev;
    }
    
    printf("\n");
}

int main() {
    struct Node* head = NULL;
    
    // Insert elements at the beginning and end
    insertAtBeginning(&head, 10);
    insertAtBeginning(&head, 20);
    insertAtEnd(&head, 5);
    insertAtEnd(&head, 15);
    
    // Print the list in both directions
    printForward(head);
    printBackward(head);
    
    // Delete from beginning and end
    deleteFromBeginning(&head);
    deleteFromEnd(&head);
    
    // Print the updated list
    printForward(head);
    printBackward(head);
    
    return 0;
}