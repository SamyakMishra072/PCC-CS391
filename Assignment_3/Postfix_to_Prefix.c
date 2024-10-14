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

// Function to convert a postfix expression to prefix
void postfixToPrefix(char* postfix, char* prefix) {
    struct Stack stack;
    initStack(&stack);
    int length = strlen(postfix);

    // Scan the postfix expression from left to right
    for (int i = 0; i < length; i++) {
        // If the character is an operand (alphanumeric), push it to the stack
        if (isalnum(postfix[i])) {
            char operand[2] = {postfix[i], '\0'};
            push(&stack, operand);
        }
        // If the character is an operator
        else {
            // Pop two operands from the stack
            char operand1[MAX], operand2[MAX];
            strcpy(operand2, pop(&stack)); // Note: order is important for prefix
            strcpy(operand1, pop(&stack));

            // Form a new string "operator operand1 operand2"
            char temp[MAX];
            snprintf(temp, sizeof(temp), "%c %s %s", postfix[i], operand1, operand2);

            // Push the new string back to the stack
            push(&stack, temp);
        }
    }

    // The final prefix expression will be the only element in the stack
    strcpy(prefix, pop(&stack));
}

int main() {
    char postfix[MAX], prefix[MAX];

    // Input the postfix expression
    printf("Enter a postfix expression: ");
    scanf("%s", postfix);

    // Convert to prefix
    postfixToPrefix(postfix, prefix);

    // Output the prefix expression
    printf("Prefix expression: %s\n", prefix);

    return 0;
}
