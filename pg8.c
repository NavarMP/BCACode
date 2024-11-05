#include <stdio.h> 
#include <stdlib.h> 
struct Node { 
    int data; 
    struct Node* next; 
}; 
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
struct Node* deleteNode(struct Node* head, int position) { 
    struct Node* temp = head; 
    struct Node* prev = NULL; 
    int i; 
    if(head == NULL) { 
        printf("List is empty.\n"); 
        return head; 
    } 
    if(position == 1) { 
        head = temp->next; 
        free(temp);
        return head; 
    } 
    for(i = 1; i < position && temp != NULL; i++) { 
        prev = temp; 
        temp = temp->next;
        } 
    if(temp == NULL) { 
        printf("Position out of range.\n"); 
        return head; 
    } 
    prev->next = temp->next; 
    free(temp); 
    return head; 
} 
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
    printf("Enter the number of nodes: "); 
    scanf("%d", &n); 
    head = createLinkedList(n); 
    displayLinkedList(head); 
    printf("Enter the position of the node to delete: "); 
    scanf("%d", &position); 
    head = deleteNode(head, position); 
    displayLinkedList(head); 
    return 0; 
}