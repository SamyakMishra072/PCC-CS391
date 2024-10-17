#include <stdio.h>
#include <stdlib.h>

#define MAX 100 // Maximum size of the priority queue

// Structure to represent an item in the priority queue
typedef struct {
    int value; // Value of the element
    int priority; // Priority of the element
} Item;

// Structure to represent the priority queue
typedef struct {
    Item items[MAX]; // Array to store elements
    int size; // Current size of the queue
} PriorityQueue;

// Function to initialize the priority queue
void initializeQueue(PriorityQueue* pq) {
    pq->size = 0;
}

// Function to enqueue an element into the priority queue
void enqueue(PriorityQueue* pq, int value, int priority) {
    if (pq->size == MAX) {
        printf("Priority Queue is full!\n");
        return;
    }
    // Create a new item
    Item newItem;
    newItem.value = value;
    newItem.priority = priority;

    // Insert the new item at the end
    pq->items[pq->size] = newItem;
    pq->size++;

    // Rearranging the queue to maintain priority order
    for (int i = pq->size - 1; i > 0; i--) {
        if (pq->items[i].priority > pq->items[i - 1].priority) {
            // Swap items
            Item temp = pq->items[i];
            pq->items[i] = pq->items[i - 1];
            pq->items[i - 1] = temp;
        } else {
            break;
        }
    }
}

// Function to dequeue an element from the priority queue
Item dequeue(PriorityQueue* pq) {
    if (pq->size == 0) {
        printf("Priority Queue is empty!\n");
        exit(EXIT_FAILURE);
    }
    // Get the item with the highest priority (first item in the array)
    Item highestPriorityItem = pq->items[0];

    // Shift the elements to remove the dequeued item
    for (int i = 0; i < pq->size - 1; i++) {
        pq->items[i] = pq->items[i + 1];
    }
    pq->size--; // Decrease the size of the queue

    return highestPriorityItem; // Return the highest priority item
}

// Function to display the priority queue
void displayQueue(PriorityQueue* pq) {
    if (pq->size == 0) {
        printf("Priority Queue is empty!\n");
        return;
    }
    printf("Priority Queue: \n");
    for (int i = 0; i < pq->size; i++) {
        printf("Value: %d, Priority: %d\n", pq->items[i].value, pq->items[i].priority);
    }
}

// Main function
int main() {
    PriorityQueue pq;
    initializeQueue(&pq);

    // Enqueue elements
    enqueue(&pq, 10, 1);
    enqueue(&pq, 20, 3);
    enqueue(&pq, 30, 2);
    enqueue(&pq, 40, 5);
    enqueue(&pq, 50, 4);

    // Display the priority queue
    displayQueue(&pq);

    // Dequeue elements
    printf("Dequeued item: Value = %d, Priority = %d\n", dequeue(&pq).value, dequeue(&pq).priority);
    printf("Dequeued item: Value = %d, Priority = %d\n", dequeue(&pq).value, dequeue(&pq).priority);

    // Display the priority queue after dequeuing
    displayQueue(&pq);

    return 0;
}
