#include <stdio.h>
#include <string.h>
#include <ctype.h>  // For isdigit and isalpha functions

#define MAX 100  // Maximum size for the stack

// Structure to represent a stack of strings
struct Stack {
    char arr[MAX][MAX];  // Array of strings
    int top;
};

// Function to initialize the stack
void initStack(struct Stack* stack) {
    stack->top = -1;
}

// Function to check if the stack is empty
int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

// Function to check if the stack is full
int isFull(struct Stack* stack) {
    return stack->top == MAX - 1;
}

// Function to push a string onto the stack
void push(struct Stack* stack, char* str) {
    if (isFull(stack)) {
        printf("Stack Overflow! Cannot push '%s'\n", str);
        return;
    }
    strcpy(stack->arr[++stack->top], str);
}

// Function to pop a string from the stack
char* pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack Underflow! Cannot pop.\n");
        return NULL;
    }
    return stack->arr[stack->top--];
}

// Function to convert a prefix expression to postfix
void prefixToPostfix(char* prefix, char* postfix) {
    struct Stack stack;
    initStack(&stack);
    int length = strlen(prefix);

    // Scan the prefix expression from right to left
    for (int i = length - 1; i >= 0; i--) {
        // If the character is an operand (alphanumeric), push it to the stack
        if (isalnum(prefix[i])) {
            char operand[2] = {prefix[i], '\0'};
            push(&stack, operand);
        }
        // If the character is an operator
        else {
            // Pop two operands from the stack
            char operand1[MAX], operand2[MAX];
            strcpy(operand1, pop(&stack));
            strcpy(operand2, pop(&stack));

            // Form a new string "operand1 operand2 operator"
            char temp[MAX];
            snprintf(temp, sizeof(temp), "%s%s%c", operand1, operand2, prefix[i]);

            // Push the new string back to the stack
            push(&stack, temp);
        }
    }

    // The final postfix expression will be the only element in the stack
    strcpy(postfix, pop(&stack));
}

int main() {
    char prefix[MAX], postfix[MAX];

    // Input the prefix expression
    printf("Enter a prefix expression: ");
    scanf("%s", prefix);

    // Convert to postfix
    prefixToPostfix(prefix, postfix);

    // Output the postfix expression
    printf("Postfix expression: %s\n", postfix);

    return 0;
}
