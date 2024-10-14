#include <stdio.h>
#include <stdlib.h>

#define MAX 5  // Define the maximum size of the stack

int stack[MAX];
int top = -1;  // Initialize the stack as empty (top = -1)

// Function to push an element onto the stack
void push() {
    int value;
    if (top == MAX - 1) {
        printf("Stack Overflow! Cannot push the element.\n");
    } else {
        printf("Enter the element to push: ");
        scanf("%d", &value);
        top++;
        stack[top] = value;
        printf("Element %d pushed onto the stack.\n", value);
    }
}

// Function to pop an element from the stack
void pop() {
    if (top == -1) {
        printf("Stack Underflow! No element to pop.\n");
    } else {
        printf("Element %d popped from the stack.\n", stack[top]);
        top--;
    }
}

// Function to peek at the top element of the stack
void peek() {
    if (top == -1) {
        printf("Stack is empty! No element to peek.\n");
    } else {
        printf("Top element is: %d\n", stack[top]);
    }
}

// Function to display the stack
void display() {
    if (top == -1) {
        printf("Stack is empty!\n");
    } else {
        printf("Stack elements are:\n");
        for (int i = top; i >= 0; i--) {
            printf("%d\n", stack[i]);
        }
    }
}

// Main function to handle the menu-driven stack operations
int main() {
    int choice;
    
    while (1) {
        printf("\n--- Stack Menu ---\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    
    return 0;
}
