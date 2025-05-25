#include <stdio.h>
#include <stdlib.h>

// Define the structure for a polynomial node
struct Node {
    int coefficient;
    int exponent;
    struct Node *next;
};

// Function to create a new node
struct Node* createNode(int coeff, int exp) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->coefficient = coeff;
    newNode->exponent = exp;
    newNode->next = NULL;
    return newNode;
}

// Function to add two polynomials
struct Node* addPolynomials(struct Node* poly1, struct Node* poly2) {
    struct Node* result = NULL;
    struct Node* temp = NULL;
    
    // Traverse both polynomials
    while (poly1 != NULL && poly2 != NULL) {
        if (poly1->exponent == poly2->exponent) {
            // If exponents are same, add the coefficients
            int sum = poly1->coefficient + poly2->coefficient;
            struct Node* newNode = createNode(sum, poly1->exponent);
            if (result == NULL) {
                result = newNode;
            } else {
                temp->next = newNode;
            }
            temp = newNode;
            poly1 = poly1->next;
            poly2 = poly2->next;
        } else if (poly1->exponent > poly2->exponent) {
            // If exponent of poly1 is greater, add poly1's term to result
            struct Node* newNode = createNode(poly1->coefficient, poly1->exponent);
            if (result == NULL) {
                result = newNode;
            } else {
                temp->next = newNode;
            }
            temp = newNode;
            poly1 = poly1->next;
        } else {
            // If exponent of poly2 is greater, add poly2's term to result
            struct Node* newNode = createNode(poly2->coefficient, poly2->exponent);
            if (result == NULL) {
                result = newNode;
            } else {
                temp->next = newNode;
            }
            temp = newNode;
            poly2 = poly2->next;
        }
    }
    
    // If poly1 has remaining terms
    while (poly1 != NULL) {
        struct Node* newNode = createNode(poly1->coefficient, poly1->exponent);
        if (result == NULL) {
            result = newNode;
        } else {
            temp->next = newNode;
        }
        temp = newNode;
        poly1 = poly1->next;
    }
    
    // If poly2 has remaining terms
    while (poly2 != NULL) {
        struct Node* newNode = createNode(poly2->coefficient, poly2->exponent);
        if (result == NULL) {
            result = newNode;
        } else {
            temp->next = newNode;
        }
        temp = newNode;
        poly2 = poly2->next;
    }
    
    return result;
}

// Function to print a polynomial
void printPolynomial(struct Node* poly) {
    while (poly != NULL) {
        if (poly->next != NULL) {
            printf("%dx^%d + ", poly->coefficient, poly->exponent);
        } else {
            printf("%dx^%d", poly->coefficient, poly->exponent);
        }
        poly = poly->next;
    }
    printf("\n");
}

// Main function
int main() {
    // Create the first polynomial: 5x^4 + 3x^3 + 2x + 7
    struct Node* poly1 = createNode(5, 4);
    poly1->next = createNode(3, 3);
    poly1->next->next = createNode(2, 1);
    poly1->next->next->next = createNode(7, 0);
    
    // Create the second polynomial: 4x^3 + 6x^2 + 3x + 8
    struct Node* poly2 = createNode(6, 2);
    poly2->next = createNode(4, 3);
    poly2->next->next = createNode(3, 1);
    poly2->next->next->next = createNode(8, 0);
    
    // Print the input polynomials
    printf("Polynomial 1: ");
    printPolynomial(poly1);
    printf("Polynomial 2: ");
    printPolynomial(poly2);
    
    // Add the two polynomials
    struct Node* result = addPolynomials(poly1, poly2);
    
    // Print the result of the addition
    printf("Resultant Polynomial: ");
    printPolynomial(result);
    
    return 0;
}