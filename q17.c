#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the polynomial linked list
struct Node {
    int coefficient;
    int exponent;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int coeff, int exp) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->coefficient = coeff;
    newNode->exponent = exp;
    newNode->next = NULL;
    return newNode;
}

// Function to add two polynomials
struct Node* addPolynomials(struct Node* poly1, struct Node* poly2) {
    struct Node* result = NULL; // Resultant polynomial
    struct Node* temp = NULL;
    
    // Traverse both polynomials
    while (poly1 != NULL && poly2 != NULL) {
        // If exponents are equal, add the coefficients
        if (poly1->exponent == poly2->exponent) {
            int coeffSum = poly1->coefficient + poly2->coefficient;
            if (coeffSum != 0) { // Only add non-zero terms
                if (result == NULL) {
                    result = createNode(coeffSum, poly1->exponent);
                    temp = result;
                } else {
                    temp->next = createNode(coeffSum, poly1->exponent);
                    temp = temp->next;
                }
            }
            poly1 = poly1->next;
            poly2 = poly2->next;
        }
        // If exponent of poly1 is greater, add poly1's term
        else if (poly1->exponent > poly2->exponent) {
            if (result == NULL) {
                result = createNode(poly1->coefficient, poly1->exponent);
                temp = result;
            } else {
                temp->next = createNode(poly1->coefficient, poly1->exponent);
                temp = temp->next;
            }
            poly1 = poly1->next;
        }
        // If exponent of poly2 is greater, add poly2's term
        else {
            if (result == NULL) {
                result = createNode(poly2->coefficient, poly2->exponent);
                temp = result;
            } else {
                temp->next = createNode(poly2->coefficient, poly2->exponent);
                temp = temp->next;
            }
            poly2 = poly2->next;
        }
    }
    
    // If poly1 has remaining terms
    while (poly1 != NULL) {
        temp->next = createNode(poly1->coefficient, poly1->exponent);
        temp = temp->next;
        poly1 = poly1->next;
    }
    
    // If poly2 has remaining terms
    while (poly2 != NULL) {
        temp->next = createNode(poly2->coefficient, poly2->exponent);
        temp = temp->next;
        poly2 = poly2->next;
    }
    
    return result;
}

// Function to display the polynomial
void displayPolynomial(struct Node* poly) {
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

int main() {
    // Create the first polynomial: 5x^3 + 3x^2 + 2x + 1
    struct Node* poly1 = createNode(5, 3);
    poly1->next = createNode(3, 2);
    poly1->next->next = createNode(2, 1);
    poly1->next->next->next = createNode(1, 0);
    
    // Create the second polynomial: 3x^2 + x + 4
    struct Node* poly2 = createNode(3, 2);
    poly2->next = createNode(1, 1);
    poly2->next->next = createNode(4, 0);
    
    // Print the input polynomials
    printf("Polynomial 1: ");
    displayPolynomial(poly1);
    printf("Polynomial 2: ");
    displayPolynomial(poly2);
    
    // Add the two polynomials
    struct Node* result = addPolynomials(poly1, poly2);
    
    // Print the result of the addition
    printf("\nSum of the polynomials: ");
    displayPolynomial(result);
    
    return 0;
}