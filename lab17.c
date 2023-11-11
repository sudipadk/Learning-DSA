#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 10

struct Node {
    int data;
    struct Node* next;
};

struct HashTable {
    struct Node* buckets[TABLE_SIZE];
};

void initializeHashTable(struct HashTable* hashTable) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        hashTable->buckets[i] = NULL;
    }
}

int hash(int key) {
    return key % TABLE_SIZE;
}

void insert(struct HashTable* hashTable, int key) {
    int index = hash(key);
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = key;
    newNode->next = hashTable->buckets[index];
    hashTable->buckets[index] = newNode;
}

struct Node* search(struct HashTable* hashTable, int key) {
    int index = hash(key);
    struct Node* current = hashTable->buckets[index];
    while (current != NULL) {
        if (current->data == key) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

int main() {
    struct HashTable hashTable;
    initializeHashTable(&hashTable);

    int size;
    printf("Enter the number of elements to insert: ");
    scanf("%d", &size);

    printf("Enter %d elements:\n", size);
    for (int i = 0; i < size; i++) {
        int element;
        printf("Enter element %d: ", i + 1);
        scanf("%d", &element);
        insert(&hashTable, element);
    }

    int keyToSearch;
    printf("Enter the element to search for: ");
    scanf("%d", &keyToSearch);

    struct Node* result = search(&hashTable, keyToSearch);

    if (result != NULL) {
        printf("Element %d found in the Hash Table.\n", keyToSearch);
    } else {
        printf("Element %d not found in the Hash Table.\n", keyToSearch);
    }

    return 0;
}