#include <stdio.h>
#include <stdlib.h>

// Define a structure for the node
struct Node {
    int data;
    struct Node* next;
};

// Function to create a linked list with n nodes
struct Node* createLinkedList(int n) {
    struct Node *head = NULL, *temp = NULL, *newNode;
    int data, i;
    
    for(i = 1; i <= n; i++) {
        newNode = (struct Node*)malloc(sizeof(struct Node));
        printf("Enter data for node %d: ", i);
        scanf("%d", &data);
        newNode->data = data;
        newNode->next = NULL;
        
        if(head == NULL) {
            head = newNode;
        } else {
            temp->next = newNode;
        }
        temp = newNode;
    }
    return head;
}

// Function to delete a node at a given position
struct Node* deleteNode(struct Node* head, int position) {
    struct Node* temp = head;
    struct Node* prev = NULL;
    int i;
    
    // Case 1: List is empty
    if(head == NULL) {
        printf("List is empty.\n");
        return head;
    }
    
    // Case 2: Deleting the head node (position = 1)
    if(position == 1) {
        head = temp->next;
        free(temp); // Free the old head
        return head;
    }
    
    // Case 3: Deleting a node at a given position (not the head)
    for(i = 1; i < position && temp != NULL; i++) {
        prev = temp;
        temp = temp->next;
    }
    
    // If the position is greater than the number of nodes
    if(temp == NULL) {
        printf("Position out of range.\n");
        return head;
    }
    
    // Unlink the node to be deleted and free it
    prev->next = temp->next;
    free(temp);
    
    return head;
}

// Function to display the linked list
void displayLinkedList(struct Node* head) {
    struct Node* temp = head;
    
    if(head == NULL) {
        printf("List is empty.\n");
        return;
    }
    
    printf("Linked list: ");
    while(temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    int n, position;
    struct Node* head = NULL;
    
    // Input number of nodes
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    
    // Create linked list
    head = createLinkedList(n);
    
    // Display the linked list
    displayLinkedList(head);
    
    // Input the position of the node to delete
    printf("Enter the position of the node to delete: ");
    scanf("%d", &position);
    
    // Delete the node at the given position
    head = deleteNode(head, position);
    
    // Display the updated linked list
    displayLinkedList(head);
    
    return 0;
}