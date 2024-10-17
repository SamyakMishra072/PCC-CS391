#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the beginning
void insertAtBeginning(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head != NULL) {
        newNode->next = *head;
        (*head)->prev = newNode;
    }
    *head = newNode;
    printf("%d inserted at the beginning.\n", data);
}

// Function to insert a node at the end
void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        printf("%d inserted at the end.\n", data);
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
    printf("%d inserted at the end.\n", data);
}

// Function to delete a node by value
void deleteByValue(struct Node** head, int value) {
    if (*head == NULL) {
        printf("List is empty! Cannot delete %d.\n", value);
        return;
    }
    struct Node* temp = *head;

    // Search for the node to delete
    while (temp != NULL && temp->data != value) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("%d not found in the list.\n", value);
        return;
    }

    // Adjust pointers for deletion
    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    } else {
        *head = temp->next;
    }
    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }

    free(temp);
    printf("%d deleted from the list.\n", value);
}

// Function to display the list in forward direction
void displayForward(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    printf("List (Forward): ");
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

// Function to display the list in reverse direction
void displayReverse(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    // Go to the last node
    while (head->next != NULL) {
        head = head->next;
    }
    printf("List (Reverse): ");
    // Display nodes in reverse order
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->prev;
    }
    printf("\n");
}

// Function to reverse the entire list
void reverseList(struct Node** head) {
    struct Node *temp = NULL, *current = *head;

    // Swap next and prev pointers for all nodes
    while (current != NULL) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }

    // Adjust the head pointer
    if (temp != NULL) {
        *head = temp->prev;
    }
    printf("List reversed.\n");
}

// Main function to test the operations
int main() {
    struct Node* list = NULL;

    // Insert elements into the list
    insertAtBeginning(&list, 10);
    insertAtEnd(&list, 20);
    insertAtEnd(&list, 30);
    insertAtBeginning(&list, 5);
    displayForward(list);
    displayReverse(list);

    // Delete an element from the list
    deleteByValue(&list, 20);
    displayForward(list);

    // Reverse the list
    reverseList(&list);
    displayForward(list);
    displayReverse(list);

    return 0;
}
