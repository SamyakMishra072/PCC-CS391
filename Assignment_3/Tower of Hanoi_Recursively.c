#include <stdio.h>

// Recursive function to solve Tower of Hanoi
void towerOfHanoi(int n, char source, char destination, char auxiliary) {
    if (n == 1) {
        // Base case: Move the last disk directly from source to destination
        printf("Move disk 1 from %c to %c\n", source, destination);
        return;
    }
    
    // Step 1: Move the top n-1 disks from source to auxiliary peg
    towerOfHanoi(n - 1, source, auxiliary, destination);
    
    // Step 2: Move the nth disk from source to destination peg
    printf("Move disk %d from %c to %c\n", n, source, destination);
    
    // Step 3: Move the n-1 disks from auxiliary peg to destination peg
    towerOfHanoi(n - 1, auxiliary, destination, source);
}

int main() {
    int n;

    // Input the number of disks from the user
    printf("Enter the number of disks: ");
    scanf("%d", &n);

    // Validate the input
    if (n <= 0) {
        printf("Number of disks must be a positive integer.\n");
        return 1; // Exit with an error code
    }

    // Call the recursive function to solve the Tower of Hanoi puzzle
    printf("The sequence of moves involved in the Tower of Hanoi are:\n");
    towerOfHanoi(n, 'A', 'C', 'B');  // A = Source, C = Destination, B = Auxiliary

    return 0;
}
