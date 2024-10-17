#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Structure to represent a node in the expression tree
struct Node {
    char data;                // Store operator or operand
    struct Node* left;       // Pointer to left subtree
    struct Node* right;      // Pointer to right subtree
};

// Function to create a new node
struct Node* createNode(char data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to check if a character is an operator
int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

// Function to evaluate the expression tree
int evaluate(struct Node* root) {
    // Base case: If the node is NULL
    if (root == NULL) {
        return 0;
    }

    // If the node is a leaf node (operand), return its integer value
    if (!isOperator(root->data)) {
        return root->data - '0'; // Convert char to int
    }

    // Recursively evaluate the left and right subtrees
    int leftEval = evaluate(root->left);
    int rightEval = evaluate(root->right);

    // Apply the operator to the evaluated values
    switch (root->data) {
        case '+': return leftEval + rightEval;
        case '-': return leftEval - rightEval;
        case '*': return leftEval * rightEval;
        case '/': return leftEval / rightEval;
    }
    return 0; // Default return
}

// Function to construct an expression tree from a postfix expression
struct Node* constructTree(char* postfix) {
    struct Node* stack[100]; // Stack to hold pointers to tree nodes
    int top = -1; // Stack pointer

    for (int i = 0; postfix[i] != '\0'; i++) {
        char c = postfix[i];

        // If the character is an operand, create a node and push it to the stack
        if (!isOperator(c)) {
            stack[++top] = createNode(c);
        } else {
            // Operator, pop two nodes from stack
            struct Node* rightNode = stack[top--];
            struct Node* leftNode = stack[top--];

            // Create a new node for the operator
            struct Node* operatorNode = createNode(c);
            operatorNode->left = leftNode;
            operatorNode->right = rightNode;

            // Push the new operator node back to the stack
            stack[++top] = operatorNode;
        }
    }

    // The last node remaining in the stack is the root of the expression tree
    return stack[top];
}

// Function to print the expression in infix notation (for verification)
void printInfix(struct Node* root) {
    if (root == NULL) {
        return;
    }

    // If this node is an operator, print '(' before left child
    if (isOperator(root->data)) {
        printf("(");
    }

    // Recursively print left subtree
    printInfix(root->left);

    // Print the root node (operator or operand)
    printf("%c", root->data);

    // Recursively print right subtree
    printInfix(root->right);

    // If this node is an operator, print ')' after right child
    if (isOperator(root->data)) {
        printf(")");
    }
}

int main() {
    char postfix[] = "53+82-*"; // Example postfix expression: (5 + 3) * (8 - 2)
    struct Node* root = constructTree(postfix);

    printf("Infix Expression: ");
    printInfix(root);
    printf("\n");

    int result = evaluate(root);
    printf("Evaluation Result: %d\n", result);

    return 0;
}
