/*
a) Implement Linear search on a List using Array in C.

   i)Insertion at the specific position.

   ii)Deletion at the specific  position.
*/

#include <stdio.h>

#define MAX 100

// Function to display the array
void display(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Function for linear search
int linearSearch(int arr[], int size, int element) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == element) {
            return i;  // Return the index of the found element
        }
    }
    return -1;  // Element not found
}

// Function to insert an element at a specific position
void insertAtPosition(int arr[], int *size, int element, int position) {
    if (position > *size || position < 0) {
        printf("Invalid position!\n");
        return;
    }
    for (int i = *size; i > position; i--) {
        arr[i] = arr[i - 1];
    }
    arr[position] = element;
    (*size)++;
    printf("After insertion: ");
    display(arr, *size);
}

// Function to delete an element at a specific position
void deleteAtPosition(int arr[], int *size, int position) {
    if (position >= *size || position < 0) {
        printf("Invalid position!\n");
        return;
    }
    for (int i = position; i < *size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    (*size)--;
    printf("After deletion: ");
    display(arr, *size);
}

int main() {
    int arr[MAX], size, choice, element, position;
    
    printf("Enter the number of elements in the array: ");
    scanf("%d", &size);
    
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    while (1) {
        printf("\n1. Linear Search\n2. Insert at Position\n3. Delete at Position\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element to search: ");
                scanf("%d", &element);
                position = linearSearch(arr, size, element);
                if (position != -1) {
                    printf("Element found at position: %d\n", position);
                } else {
                    printf("Element not found.\n");
                }
                break;
            case 2:
                printf("Enter element to insert: ");
                scanf("%d", &element);
                printf("Enter position to insert: ");
                scanf("%d", &position);
                insertAtPosition(arr, &size, element, position);
                break;
            case 3:
                printf("Enter position to delete: ");
                scanf("%d", &position);
                deleteAtPosition(arr, &size, position);
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}
