#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the stack
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to check if the stack is empty
int isEmpty(struct Node* top) {
    return top == NULL;
}

// Function to push an element onto the stack
void push(struct Node** top, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = *top;
    *top = newNode;
    printf("%d pushed to stack.\n", data);
}

// Function to pop an element from the stack
int pop(struct Node** top) {
    if (isEmpty(*top)) {
        printf("Stack underflow! No elements to pop.\n");
        return -1;
    }
    struct Node* temp = *top;
    int poppedData = temp->data;
    *top = (*top)->next;
    free(temp);
    return poppedData;
}

// Function to peek at the top element of the stack
int peek(struct Node* top) {
    if (isEmpty(top)) {
        printf("Stack is empty!\n");
        return -1;
    }
    return top->data;
}

// Function to display all elements in the stack
void display(struct Node* top) {
    if (isEmpty(top)) {
        printf("Stack is empty!\n");
        return;
    }
    printf("Stack elements: ");
    while (top != NULL) {
        printf("%d ", top->data);
        top = top->next;
    }
    printf("\n");
}

// Main function to test the stack operations
int main() {
    struct Node* stack = NULL;  // Initialize an empty stack

    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);
    display(stack);

    printf("Top element is %d\n", peek(stack));

    printf("Popped element is %d\n", pop(&stack));
    display(stack);

    printf("Popped element is %d\n", pop(&stack));
    display(stack);

    printf("Popped element is %d\n", pop(&stack));
    display(stack);

    printf("Popped element is %d\n", pop(&stack));  // Attempting to pop from empty stack

    return 0;
}
