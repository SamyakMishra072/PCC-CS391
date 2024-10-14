#include <stdio.h>
#include <ctype.h>  // For isdigit function
#include <string.h> // For strlen function

#define MAX 100  // Maximum size for the stack

// Structure to represent a stack
struct Stack {
    char arr[MAX];
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
void push(struct Stack* stack, char value) {
    if (isFull(stack)) {
        printf("Stack Overflow! Cannot push '%c'\n", value);
        return;
    }
    stack->arr[++stack->top] = value;
}

// Function to pop an element from the stack
char pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack Underflow! Cannot pop.\n");
        return '\0';
    }
    return stack->arr[stack->top--];
}

// Function to get the precedence of operators
int precedence(char operator) {
    switch (operator) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
        case '%':
            return 2;
        case '^':
            return 3;
        default:
            return 0;
    }
}

// Function to check if the given character is an operator
int isOperator(char symbol) {
    return symbol == '+' || symbol == '-' || symbol == '*' || symbol == '/' || symbol == '%' || symbol == '^';
}

// Function to convert an infix expression to a postfix expression
void infixToPostfix(char* infix, char* postfix) {
    struct Stack stack;
    initStack(&stack);
    int i = 0, j = 0;
    
    while (infix[i] != '\0') {
        // If the character is an operand, add it to the postfix expression
        if (isalnum(infix[i])) {
            postfix[j++] = infix[i];
        }
        // If the character is '(', push it onto the stack
        else if (infix[i] == '(') {
            push(&stack, infix[i]);
        }
        // If the character is ')', pop until '(' is found
        else if (infix[i] == ')') {
            while (!isEmpty(&stack) && stack.arr[stack.top] != '(') {
                postfix[j++] = pop(&stack);
            }
            pop(&stack);  // Pop the '('
        }
        // If the character is an operator
        else if (isOperator(infix[i])) {
            while (!isEmpty(&stack) && precedence(stack.arr[stack.top]) >= precedence(infix[i])) {
                postfix[j++] = pop(&stack);
            }
            push(&stack, infix[i]);
        }
        i++;
    }
    
    // Pop any remaining operators in the stack
    while (!isEmpty(&stack)) {
        postfix[j++] = pop(&stack);
    }
    
    postfix[j] = '\0';  // Null-terminate the postfix expression
}

int main() {
    char infix[MAX], postfix[MAX];
    
    // Input infix expression
    printf("Enter an infix expression: ");
    scanf("%s", infix);
    
    // Convert to postfix
    infixToPostfix(infix, postfix);
    
    // Output the postfix expression
    printf("Postfix expression: %s\n", postfix);
    
    return 0;
}
