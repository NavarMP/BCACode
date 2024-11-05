#include <stdio.h> 
#include <stdlib.h> 
 
// 
struct Node { 
    int data; 
    struct Node* next; 
}; 
 
// Function to insert a new node at the end of the linked list 
void insertNode(struct Node** head, int data) { 
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node)); 
    struct Node* last = *head; 
    newNode->data = data; 
    newNode->next = NULL; 
 
    if (*head == NULL) { 
        *head = newNode; 
        return; 
    } 
 
    while (last->next != NULL) { 
        last = last->next; 
    } 
    last->next = newNode; 
} 
 
// Function to search for an element in the linked list 
int searchElement(struct Node* head, int value) {
    struct Node* current = head; 
    while (current != NULL) { 
        if (current->data == value) { 
            return 1; // Element found 
        } 
        current = current->next; 
    } 
    return 0; // Element not found 
} 
 
// Function to print the linked list 
void printList(struct Node* head) { 
    struct Node* temp = head; 
    while (temp != NULL) { 
        printf("%d -> ", temp->data); 
        temp = temp->next; 
    } 
    printf("NULL\n"); 
} 
 
// Main function 
int main() { 
    struct Node* head = NULL; 
    int n, value, searchVal, i;
    // Accept the number of nodes 
    printf("Enter the number of nodes: "); 
    scanf("%d", &n); 
 
    // Accept the values from the user 
    for (i = 0; i < n; i++) { 
        printf("Enter value for node %d: ", i + 1); 
        scanf("%d", &value); 
        insertNode(&head, value); 
    } 
 
    // Display the list 
    printf("Linked list:\n"); 
    printList(head); 
 
    // Accept the value to search 
    printf("Enter value to search in the list: "); 
    scanf("%d", &searchVal); 
 
    // Search the element in the list 
    if (searchElement(head, searchVal)) { 
        printf("Element %d found in the list.\n", searchVal); 
    } else { 
        printf("Element %d not found in the list.\n", searchVal); 
    } 
    return 0;
}