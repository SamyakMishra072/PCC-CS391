#include <stdio.h>
// Function for Linear Search
int linearSearch(int arr[], int n, int target) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == target) {
            return i; // Return index if target is found
        }
    }
    return -1; // Return -1 if target is not found
}

// Function for Binary Search (requires a sorted array)
int binarySearch(int arr[], int n, int target) {
    int left = 0;
    int right = n - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            return mid; // Return index if target is found
        }
        if (arr[mid] < target) {
            left = mid + 1; // Search in the right half
        } else {
            right = mid - 1; // Search in the left half
        }
    }
    return -1; // Return -1 if target is not found
}

// Function for Interpolation Search (requires a sorted array)
int interpolationSearch(int arr[], int n, int target) {
    int low = 0, high = n - 1;

    while (low <= high && target >= arr[low] && target <= arr[high]) {
        if (low == high) {
            if (arr[low] == target) {
                return low; // Return index if target is found
            }
            return -1; // Return -1 if target is not found
        }

        // Calculate the position using interpolation
        int pos = low + ((target - arr[low]) * (high - low)) / (arr[high] - arr[low]);

        // Check if the target is found
        if (arr[pos] == target) {
            return pos; // Return index if target is found
        }
        if (arr[pos] < target) {
            low = pos + 1; // Search in the right half
        } else {
            high = pos - 1; // Search in the left half
        }
    }
    return -1; // Return -1 if target is not found
}

// Main function
int main() {
    int arr[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100}; // Sorted array for Binary and Interpolation Search
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 70;

    // Linear Search
    int result = linearSearch(arr, n, target);
    if (result != -1) {
        printf("Linear Search: Element found at index %d\n", result);
    } else {
        printf("Linear Search: Element not found\n");
    }

    // Binary Search
    result = binarySearch(arr, n, target);
    if (result != -1) {
        printf("Binary Search: Element found at index %d\n", result);
    } else {
        printf("Binary Search: Element not found\n");
    }

    // Interpolation Search
    result = interpolationSearch(arr, n, target);
    if (result != -1) {
        printf("Interpolation Search: Element found at index %d\n", result);
    } else {
        printf("Interpolation Search: Element not found\n");
    }

    return 0;
}
