#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node
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

// Function to print the linked list
void printList(struct Node* head) {
    struct Node* temp = head;
    
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    
    printf("NULL\n");
}

// Function to sort the linked list using bubble sort
void sortList(struct Node* head) {
    int swapped, tempData;
    struct Node *ptr1;
    struct Node *lptr = NULL;
    
    if (head == NULL)
        return;
    
    do {
        swapped = 0;
        ptr1 = head;
        
        while (ptr1->next != lptr) {
            if (ptr1->data > ptr1->next->data) {
                // Swap the data
                tempData = ptr1->data;
                ptr1->data = ptr1->next->data;
                ptr1->next->data = tempData;
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);
}

int main() {
    struct Node* head = NULL;
    int n, value, i;
    
    // Accept the number of nodes
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    
    // Accept the values from the user
    for (i = 0; i < n; i++) {
        printf("Enter value for node %d: ", i + 1);
        scanf("%d", &value);
        insertNode(&head, value);
    }
    
    // Display the list before sorting
    printf("Linked list before sorting:\n");
    printList(head);
    
    // Sort the linked list
    sortList(head);
    
    // Display the list after sorting
    printf("Linked list after sorting:\n");
    printList(head);
    
    return 0;
}