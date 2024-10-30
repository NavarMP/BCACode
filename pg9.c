#include<stdio.h> 
#include<stdlib.h> 
struct Node { 
    int data; 
    struct Node* next; 
}; 
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
void printList(struct Node* head) { 
    struct Node* temp = head; 
    while (temp != NULL) { 
        printf("%d -> ", temp->data); 
        temp = temp->next; 
    } 
    printf("NULL\n"); 
}
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
    printf("Enter the number of nodes: "); 
    scanf("%d", &n); 
    for (i = 0; i < n; i++) { 
        printf("Enter value for node %d: ", i + 1); 
        scanf("%d", &value); 
        insertNode(&head, value); 
    } 
    printf("Linked list before sorting:\n"); 
    printList(head); 
    sortList(head);
    printf("Linked list after sorting:\n"); 
    printList(head); 
 
    return 0; 
}