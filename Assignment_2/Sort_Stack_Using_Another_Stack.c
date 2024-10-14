#include <stdio.h>
#include <stdlib.h>
#define MAX 100
struct Stack {
    int arr[MAX];
    int top;
};
void initStack(struct Stack* stack) {
    stack->top = -1;
}
int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}
int isFull(struct Stack* stack) {
    return stack->top == MAX - 1;
}
void push(struct Stack* stack, int value) {
    if (isFull(stack)) {
        printf("Stack Overflow! Cannot push %d\n", value);
        return;
    }
    stack->arr[++stack->top] = value;
}
int pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack Underflow! Cannot pop.\n");
        return -1;
    }
    return stack->arr[stack->top--];
}
int peek(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty! No top element.\n");
        return -1;
    }
    return stack->arr[stack->top];
}

// Function to print the stack
void printStack(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty!\n");
        return;
    }
    printf("Stack: ");
    for (int i = 0; i <= stack->top; i++) {
        printf("%d ", stack->arr[i]);
    }
    printf("\n");
}

// Function to sort a stack using another stack
void sortStack(struct Stack* inputStack) {
    struct Stack tempStack;
    initStack(&tempStack);
    
    while (!isEmpty(inputStack)) {
        // Pop an element from the input stack
        int temp = pop(inputStack);

        // While the temporary stack is not empty and top of tempStack is greater than temp
        while (!isEmpty(&tempStack) && peek(&tempStack) > temp) {
            // Push the element from tempStack back to inputStack
            push(inputStack, pop(&tempStack));
        }

        // Push temp into the tempStack
        push(&tempStack, temp);
    }

    // Transfer sorted elements back to inputStack
    while (!isEmpty(&tempStack)) {
        push(inputStack, pop(&tempStack));
    }
}

int main() {
    struct Stack stack;
    initStack(&stack);

    // Push elements onto the stack
    push(&stack, 34);
    push(&stack, 3);
    push(&stack, 31);
    push(&stack, 98);
    push(&stack, 92);
    push(&stack, 23);

    printf("Original Stack:\n");
    printStack(&stack);

    // Sort the stack
    sortStack(&stack);

    printf("\nSorted Stack:\n");
    printStack(&stack);

    return 0;
}
