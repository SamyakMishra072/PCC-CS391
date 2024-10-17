#include <stdio.h>
#include <stdlib.h>

// Define the structure for a binary search tree node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Stack structure to hold nodes for traversals
struct Stack {
    struct Node* data;
    struct Stack* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to insert a node into the BST
struct Node* insert(struct Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }
    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }
    return root;
}

// Stack Operations: Push, Pop, and IsEmpty
void push(struct Stack** top, struct Node* node) {
    struct Stack* newStackNode = (struct Stack*)malloc(sizeof(struct Stack));
    newStackNode->data = node;
    newStackNode->next = *top;
    *top = newStackNode;
}

struct Node* pop(struct Stack** top) {
    if (*top == NULL) return NULL;
    struct Stack* temp = *top;
    struct Node* node = temp->data;
    *top = (*top)->next;
    free(temp);
    return node;
}

int isEmpty(struct Stack* top) {
    return top == NULL;
}

// Non-Recursive Inorder Traversal
void inorder(struct Node* root) {
    struct Stack* stack = NULL;
    struct Node* current = root;

    printf("Inorder Traversal: ");
    while (!isEmpty(stack) || current != NULL) {
        while (current != NULL) {
            push(&stack, current);
            current = current->left;
        }
        current = pop(&stack);
        printf("%d ", current->data);
        current = current->right;
    }
    printf("\n");
}

// Non-Recursive Preorder Traversal
void preorder(struct Node* root) {
    if (root == NULL) return;
    struct Stack* stack = NULL;
    push(&stack, root);

    printf("Preorder Traversal: ");
    while (!isEmpty(stack)) {
        struct Node* node = pop(&stack);
        printf("%d ", node->data);

        if (node->right != NULL) {
            push(&stack, node->right);
        }
        if (node->left != NULL) {
            push(&stack, node->left);
        }
    }
    printf("\n");
}

// Non-Recursive Postorder Traversal
void postorder(struct Node* root) {
    if (root == NULL) return;
    struct Stack* stack1 = NULL;
    struct Stack* stack2 = NULL;
    push(&stack1, root);

    while (!isEmpty(stack1)) {
        struct Node* node = pop(&stack1);
        push(&stack2, node);

        if (node->left != NULL) {
            push(&stack1, node->left);
        }
        if (node->right != NULL) {
            push(&stack1, node->right);
        }
    }

    printf("Postorder Traversal: ");
    while (!isEmpty(stack2)) {
        printf("%d ", pop(&stack2)->data);
    }
    printf("\n");
}

// Main function to test the operations
int main() {
    struct Node* root = NULL;

    // Insert elements into the BST
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 70);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 60);
    root = insert(root, 80);

    // Perform non-recursive traversals
    inorder(root);
    preorder(root);
    postorder(root);

    return 0;
}
