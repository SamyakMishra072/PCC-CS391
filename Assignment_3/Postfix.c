#include <stdio.h>
#include <ctype.h>  // for isdigit function
#include <stdlib.h> // for exit function

#define MAX 100  // Define maximum size for the stack

// Structure to represent a stack
struct Stack {
    int arr[MAX];
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

// Function to push an element onto the stack
void push(struct Stack* stack, int value) {
    if (isFull(stack)) {
        printf("Stack Overflow! Cannot push %d\n", value);
        exit(1);
    }
    stack->arr[++stack->top] = value;
}

// Function to pop an element from the stack
int pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack Underflow! Cannot pop.\n");
        exit(1);
    }
    return stack->arr[stack->top--];
}

// Function to evaluate the postfix expression
int evaluatePostfix(char* expression) {
    struct Stack stack;
    initStack(&stack);
    
    // Traverse through each character in the expression
    for (int i = 0; expression[i] != '\0'; i++) {
        // If the character is a digit (operand), push it to the stack
        if (isdigit(expression[i])) {
            push(&stack, expression[i] - '0');  // Convert char to int
        }
        // If the character is an operator, pop two elements, apply the operator, and push the result
        else {
            int operand2 = pop(&stack);
            int operand1 = pop(&stack);

            switch (expression[i]) {
                case '+':
                    push(&stack, operand1 + operand2);
                    break;
                case '-':
                    push(&stack, operand1 - operand2);
                    break;
                case '*':
                    push(&stack, operand1 * operand2);
                    break;
                case '/':
                    if (operand2 == 0) {
                        printf("Division by zero error!\n");
                        exit(1);
                    }
                    push(&stack, operand1 / operand2);
                    break;
                default:
                    printf("Invalid operator encountered: %c\n", expression[i]);
                    exit(1);
            }
        }
    }
    
    // The final result will be the only element left in the stack
    return pop(&stack);
}

int main() {
    char expression[MAX];

    // Input the postfix expression
    printf("Enter a postfix expression: ");
    scanf("%s", expression);

    // Evaluate the postfix expression
    int result = evaluatePostfix(expression);

    // Output the result
    printf("Result of postfix expression '%s' is: %d\n", expression, result);

    return 0;
}
