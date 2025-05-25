#include <stdio.h>
#include <stdlib.h>

// Structure for a node in the BST
struct Node {
    char data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* createNode(char data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to insert a node into the BST
struct Node* insert(struct Node* root, char data) {
    if (root == NULL) {
        return createNode(data);
    }
    
    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }
    
    return root;
}

// Function to search for a node in the BST
int search(struct Node* root, char key) {
    if (root == NULL) {
        return 0; // Not found
    }
    
    if (root->data == key) {
        return 1; // Found
    } else if (key < root->data) {
        return search(root->left, key);
    } else {
        return search(root->right, key);
    }
}

// Function for in-order traversal of the BST (Left, Root, Right)
void inorderTraversal(struct Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%c ", root->data);
        inorderTraversal(root->right);
    }
}

// Function to find the minimum value node in the BST
struct Node* findMin(struct Node* root) {
    while (root && root->left != NULL) {
        root = root->left;
    }
    return root;
}

// Function to delete a node from the BST
struct Node* delete(struct Node* root, char key) {
    if (root == NULL) {
        return root; // Element not found
    }
    
    // Traverse the tree
    if (key < root->data) {
        root->left = delete(root->left, key);
    } else if (key > root->data) {
        root->right = delete(root->right, key);
    } else {
        // Node with only one child or no child
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }
        
        // Node with two children: Get the in-order successor
        struct Node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = delete(root->right, temp->data);
    }
    
    return root;
}

int main() {
    struct Node* root = NULL;
    
    root = insert(root, 'D');
    root = insert(root, 'B');
    root = insert(root, 'A');
    root = insert(root, 'C');
    root = insert(root, 'F');
    root = insert(root, 'E');
    root = insert(root, 'G');
    
    printf("In-order traversal of the BST:\n");
    inorderTraversal(root);
    printf("\n");
    
    char key = 'C';
    if (search(root, key)) {
        printf("Character '%c' found in the tree.\n", key);
    } else {
        printf("Character '%c' not found in the tree.\n", key);
    }
    
    printf("Deleting character 'B' from the tree...\n");
    root = delete(root, 'B');
    inorderTraversal(root);
    printf("\n");
    
    return 0;
}