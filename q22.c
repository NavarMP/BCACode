#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define MAX 100

// Function to get the precedence of operators
int precedence(char c) {
    if (c == '+' || c == '-') {
        return 1;
    } else if (c == '*' || c == '/') {
        return 2;
    } else if (c == '^') {
        return 3;
    }
    return 0;
}

// Function to check if the character is an operand (number or variable)
int isOperand(char c) {
    return isalpha(c) || isdigit(c);
}

// Function to convert infix expression to postfix expression
void infixToPostfix(char* infix, char* postfix) {
    char stack[MAX];
    int top = -1;
    int j = 0;
    
    for (int i = 0; infix[i] != '\0'; i++) {
        char c = infix[i];
        
        // If the character is an operand, add it to the result
        if (isOperand(c)) {
            postfix[j++] = c;
        }
        // If the character is '(', push it to the stack
        else if (c == '(') {
            stack[++top] = c;
        }
        // If the character is ')', pop until '(' is encountered
        else if (c == ')') {
            while (top != -1 && stack[top] != '(') {
                postfix[j++] = stack[top--];
            }
            top--; // Pop '(' from the stack
        }
        // If the character is an operator
        else {
            while (top != -1 && precedence(stack[top]) >= precedence(c)) {
                postfix[j++] = stack[top--];
            }
            stack[++top] = c; // Push the current operator to the stack
        }
    }
    
    // Pop all remaining operators from the stack
    while (top != -1) {
        postfix[j++] = stack[top--];
    }
    
    postfix[j] = '\0'; // Null-terminate the postfix expression
}

int main() {
    char infix[MAX], postfix[MAX];
    
    printf("Enter the infix expression: ");
    scanf("%s", infix);
    
    infixToPostfix(infix, postfix);
    
    printf("Postfix expression: %s\n", postfix);
    
    return 0;
}