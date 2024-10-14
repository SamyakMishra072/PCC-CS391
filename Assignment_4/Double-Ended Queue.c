#include <stdio.h>
#include <stdlib.h>

#define MAX 5  // Maximum size of the deque

// Structure to represent the deque
struct Deque {
    int items[MAX];
    int front;
    int rear;
};

// Function to initialize the deque
void initDeque(struct Deque* dq) {
    dq->front = -1;
    dq->rear = -1;
}

// Function to check if the deque is empty
int isEmpty(struct Deque* dq) {
    return dq->front == -1;
}

// Function to check if the deque is full
int isFull(struct Deque* dq) {
    return (dq->rear + 1) % MAX == dq->front;
}

// Function to add an element at the front of the deque
void insertFront(struct Deque* dq, int value) {
    if (isFull(dq)) {
        printf("Deque is full. Cannot insert %d at the front.\n", value);
        return;
    }
    if (isEmpty(dq)) {
        dq->front = 0;  // Set front and rear to 0 if deque is empty
        dq->rear = 0;
    } else {
        dq->front = (dq->front - 1 + MAX) % MAX;  // Circular decrement of front
    }
    dq->items[dq->front] = value;
    printf("Inserted %d at the front.\n", value);
}

// Function to add an element at the rear of the deque
void insertRear(struct Deque* dq, int value) {
    if (isFull(dq)) {
        printf("Deque is full. Cannot insert %d at the rear.\n", value);
        return;
    }
    if (isEmpty(dq)) {
        dq->front = 0;  // Set front and rear to 0 if deque is empty
        dq->rear = 0;
    } else {
        dq->rear = (dq->rear + 1) % MAX;  // Circular increment of rear
    }
    dq->items[dq->rear] = value;
    printf("Inserted %d at the rear.\n", value);
}

// Function to delete an element from the front of the deque
int deleteFront(struct Deque* dq) {
    if (isEmpty(dq)) {
        printf("Deque is empty. Cannot delete from the front.\n");
        return -1;
    }
    int value = dq->items[dq->front];
    if (dq->front == dq->rear) {
        // Deque has only one element, reset deque after deletion
        dq->front = -1;
        dq->rear = -1;
    } else {
        dq->front = (dq->front + 1) % MAX;  // Circular increment of front
    }
    return value;
}

// Function to delete an element from the rear of the deque
int deleteRear(struct Deque* dq) {
    if (isEmpty(dq)) {
        printf("Deque is empty. Cannot delete from the rear.\n");
        return -1;
    }
    int value = dq->items[dq->rear];
    if (dq->front == dq->rear) {
        // Deque has only one element, reset deque after deletion
        dq->front = -1;
        dq->rear = -1;
    } else {
        dq->rear = (dq->rear - 1 + MAX) % MAX;  // Circular decrement of rear
    }
    return value;
}

// Function to display the elements of the deque
void display(struct Deque* dq) {
    if (isEmpty(dq)) {
        printf("Deque is empty.\n");
        return;
    }
    printf("Deque elements: ");
    int i = dq->front;
    do {
        printf("%d ", dq->items[i]);
        i = (i + 1) % MAX;  // Circular increment
    } while (i != (dq->rear + 1) % MAX);
    printf("\n");
}

// Main function
int main() {
    struct Deque dq;
    initDeque(&dq);
    int choice, value;

    do {
        printf("\nMenu:\n");
        printf("1. Insert at Front\n");
        printf("2. Insert at Rear\n");
        printf("3. Delete from Front\n");
        printf("4. Delete from Rear\n");
        printf("5. Display\n");
        printf("6. Check if Deque is Empty\n");
        printf("7. Check if Deque is Full\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert at front: ");
                scanf("%d", &value);
                insertFront(&dq, value);
                break;
            case 2:
                printf("Enter value to insert at rear: ");
                scanf("%d", &value);
                insertRear(&dq, value);
                break;
            case 3:
                value = deleteFront(&dq);
                if (value != -1) {
                    printf("Deleted from front: %d\n", value);
                }
                break;
            case 4:
                value = deleteRear(&dq);
                if (value != -1) {
                    printf("Deleted from rear: %d\n", value);
                }
                break;
            case 5:
                display(&dq);
                break;
            case 6:
                if (isEmpty(&dq)) {
                    printf("Deque is empty.\n");
                } else {
                    printf("Deque is not empty.\n");
                }
                break;
            case 7:
                if (isFull(&dq)) {
                    printf("Deque is full.\n");
                } else {
                    printf("Deque is not full.\n");
                }
                break;
            case 8:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 8);

    return 0;
}
