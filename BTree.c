#include <stdio.h>

#define ORDER 5

// Structure to represent a B-tree node
struct BTreeNode {
    int keys[ORDER - 1];
    struct BTreeNode* children[ORDER];
    int num_keys;
    int is_leaf;
};

// Function to print a B-tree
void printBTree(struct BTreeNode* node, int level) {
    if (node != NULL) {
        int i;
        for (i = 0; i < node->num_keys; i++) {
            printf("%d ", node->keys[i]);
        }
        printf("\n");

        if (!node->is_leaf) {
            for (i = 0; i <= node->num_keys; i++) {
                printBTree(node->children[i], level + 1);
            }
        }
    }
}

int main() {
    // Create a sample B-tree
    struct BTreeNode* root = NULL;

    // Insert keys into the B-tree (you would typically implement a B-tree insertion function)

    // Print the B-tree
    printf("B-tree:\n");
    printBTree(root, 0);

    return 0;
}
