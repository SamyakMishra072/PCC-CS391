#include <stdio.h>
#include <stdlib.h>
#define TABLE_SIZE 10 

// Structure to represent a hash table entry
typedef struct {
    int key; // Key of the entry
    int value; // Value of the entry
} HashEntry;

// Structure to represent the hash table
typedef struct {
    HashEntry* table[TABLE_SIZE]; // Array of hash entries
} HashTable;

// Hash function
int hashFunction(int key) {
    return key % TABLE_SIZE;
}

// Function to create a new hash entry
HashEntry* createEntry(int key, int value) {
    HashEntry* newEntry = (HashEntry*)malloc(sizeof(HashEntry));
    newEntry->key = key;
    newEntry->value = value;
    return newEntry;
}

// Function to initialize the hash table
HashTable* createHashTable() {
    HashTable* ht = (HashTable*)malloc(sizeof(HashTable));
    for (int i = 0; i < TABLE_SIZE; i++) {
        ht->table[i] = NULL; // Initialize all entries to NULL
    }
    return ht;
}

// Function to insert a key-value pair into the hash table
void insert(HashTable* ht, int key, int value) {
    int index = hashFunction(key);
    
    // Linear probing to find an empty slot
    while (ht->table[index] != NULL) {
        index = (index + 1) % TABLE_SIZE; // Wrap around if needed
    }
    
    // Create and insert the new entry
    ht->table[index] = createEntry(key, value);
    printf("Inserted (%d, %d) at index %d\n", key, value, index);
}

// Function to search for a value by key in the hash table
int search(HashTable* ht, int key) {
    int index = hashFunction(key);
    
    // Linear probing to find the key
    while (ht->table[index] != NULL) {
        if (ht->table[index]->key == key) {
            return ht->table[index]->value; // Return the value if found
        }
        index = (index + 1) % TABLE_SIZE; // Wrap around if needed
    }
    
    return -1; // Return -1 if not found
}

// Function to delete a key from the hash table
void delete(HashTable* ht, int key) {
    int index = hashFunction(key);
    
    // Linear probing to find the key
    while (ht->table[index] != NULL) {
        if (ht->table[index]->key == key) {
            free(ht->table[index]); // Free the memory
            ht->table[index] = NULL; // Mark the slot as empty
            printf("Deleted key %d from index %d\n", key, index);
            return;
        }
        index = (index + 1) % TABLE_SIZE; // Wrap around if needed
    }
    
    printf("Key %d not found for deletion\n", key);
}

// Function to display the hash table
void display(HashTable* ht) {
    printf("Hash Table:\n");
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (ht->table[i] != NULL) {
            printf("Index %d: Key = %d, Value = %d\n", i, ht->table[i]->key, ht->table[i]->value);
        } else {
            printf("Index %d: NULL\n", i);
        }
    }
}

// Main function
int main() {
    HashTable* ht = createHashTable();

    // Insert some key-value pairs
    insert(ht, 1, 100);
    insert(ht, 2, 200);
    insert(ht, 12, 300); // This will cause a collision
    insert(ht, 22, 400); // This will cause a collision
    insert(ht, 3, 500);

    // Display the hash table
    display(ht);

    // Search for a key
    int keyToSearch = 12;
    int value = search(ht, keyToSearch);
    if (value != -1) {
        printf("Value for key %d: %d\n", keyToSearch, value);
    } else {
        printf("Key %d not found\n", keyToSearch);
    }

    // Delete a key
    delete(ht, 2);
    display(ht);

    // Clean up memory
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (ht->table[i] != NULL) {
            free(ht->table[i]);
        }
    }
    free(ht);

    return 0;
}
