#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    char symbol;
    int freq;
    struct Node* left;
    struct Node* right;
};

struct PriorityQueue {
    struct Node** nodes;
    int size;
};

struct Node* createNode(char symbol, int freq) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->symbol = symbol;
    node->freq = freq;
    node->left = NULL;
    node->right = NULL;
    return node;
}

struct PriorityQueue* initPriorityQueue(int capacity) {
    struct PriorityQueue* pq = (struct PriorityQueue*)malloc(sizeof(struct PriorityQueue));
    pq->nodes = (struct Node**)malloc(capacity * sizeof(struct Node*));
    pq->size = 0;
    return pq;
}

void insert(struct PriorityQueue* pq, struct Node* node) {
    int i = pq->size;
    while (i > 0 && node->freq < pq->nodes[(i - 1) / 2]->freq) {
        pq->nodes[i] = pq->nodes[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    pq->nodes[i] = node;
    pq->size++;
}

struct Node* removeMin(struct PriorityQueue* pq) {
    struct Node* minNode = pq->nodes[0];
    pq->size--;
    struct Node* lastNode = pq->nodes[pq->size];
    int i = 0;
    while (i * 2 + 1 < pq->size) {
        int child = i * 2 + 1;
        if (child + 1 < pq->size && pq->nodes[child + 1]->freq < pq->nodes[child]->freq) {
            child++;
        }
        if (lastNode->freq <= pq->nodes[child]->freq) {
            break;
        }
        pq->nodes[i] = pq->nodes[child];
        i = child;
    }
    pq->nodes[i] = lastNode;
    return minNode;
}

struct Node* buildHuffmanTree(char symbols[], int freq[], int n) {
    struct PriorityQueue* pq = initPriorityQueue(n);
    int i;
    for (i = 0; i < n; i++) {
        insert(pq, createNode(symbols[i], freq[i]));
    }
    while (pq->size > 1) {
        struct Node* left = removeMin(pq);
        struct Node* right = removeMin(pq);
        struct Node* newNode = createNode('$', left->freq + right->freq);
        newNode->left = left;
        newNode->right = right;
        insert(pq, newNode);
    }
    return removeMin(pq);
}

void printHuffmanCodes(struct Node* root, char code[], int top) {
    if (root->left) {
        code[top] = '0';
        printHuffmanCodes(root->left, code, top + 1);
    }
    if (root->right) {
        code[top] = '1';
        printHuffmanCodes(root->right, code, top + 1);
    }
    if (!root->left && !root->right) {
        code[top] = '\0';
        printf("%c: %s\n", root->symbol, code);
    }
}

int main() {
    int n;
    printf("Enter the number of symbols: ");
    scanf("%d", &n);

    char symbols[n];
    int freq[n];
int i;
    for ( i = 0; i < n; i++) {
        printf("Enter symbol %d: ", i + 1);
        scanf(" %c", &symbols[i]);
        printf("Enter frequency for %c: ", symbols[i]);
        scanf("%d", &freq[i]);
    }

    struct Node* root = buildHuffmanTree(symbols, freq, n);

    char code[100];
    printf("\nHuffman Codes:\n");
    printHuffmanCodes(root, code, 0);

    return 0;
}

