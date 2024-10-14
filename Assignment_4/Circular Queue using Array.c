#include <stdio.h>
#include <stdlib.h>

#define MAX 5  // Maximum size of the queue

// Structure to represent the circular queue
struct CircularQueue {
    int items[MAX];
    int front;
    int rear;
};

// Function to initialize the circular queue
void initQueue(struct CircularQueue* q) {
    q->front = -1;
    q->rear = -1;
}

// Function to check if the queue is empty
int isEmpty(struct CircularQueue* q) {
    return q->front == -1;
}

// Function to check if the queue is full
int isFull(struct CircularQueue* q) {
    return (q->rear + 1) % MAX == q->front;
}

// Function to add an element to the queue
void enqueue(struct CircularQueue* q, int value) {
    if (isFull(q)) {
        printf("Queue is full. Cannot enqueue %d.\n", value);
        return;
    }
    if (isEmpty(q)) {
        q->front = 0;  // Set front to 0 if adding the first element
    }
    q->rear = (q->rear + 1) % MAX;  // Circular increment of rear
    q->items[q->rear] = value;
    printf("Enqueued: %d\n", value);
}

// Function to remove an element from the queue
int dequeue(struct CircularQueue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty. Cannot dequeue.\n");
        return -1;
    }
    int value = q->items[q->front];
    if (q->front == q->rear) {
        // Queue has only one element, reset queue after dequeue
        q->front = -1;
        q->rear = -1;
    } else {
        // Circular increment of front
        q->front = (q->front + 1) % MAX;
    }
    return value;
}

// Function to display the elements of the queue
void display(struct CircularQueue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue elements: ");
    int i = q->front;
    do {
        printf("%d ", q->items[i]);
        i = (i + 1) % MAX;  // Circular increment
    } while (i != (q->rear + 1) % MAX);
    printf("\n");
}

// Main function
int main() {
    struct CircularQueue q;
    initQueue(&q);
    int choice, value;

    do {
        printf("\nMenu:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Check if Queue is Empty\n");
        printf("5. Check if Queue is Full\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                enqueue(&q, value);
                break;
            case 2:
                value = dequeue(&q);
                if (value != -1) {
                    printf("Dequeued: %d\n", value);
                }
                break;
            case 3:
                display(&q);
                break;
            case 4:
                if (isEmpty(&q)) {
                    printf("Queue is empty.\n");
                } else {
                    printf("Queue is not empty.\n");
                }
                break;
            case 5:
                if (isFull(&q)) {
                    printf("Queue is full.\n");
                } else {
                    printf("Queue is not full.\n");
                }
                break;
            case 6:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 6);

    return 0;
}
