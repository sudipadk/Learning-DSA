#include <stdio.h>
#include <stdlib.h>

// Structure for a binary tree node
struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Function to create a new node with a given value
struct TreeNode* createNode(int value) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a value into a binary search tree
struct TreeNode* insert(struct TreeNode* root, int value) {
    if (root == NULL) {
        return createNode(value);
    }

    if (value < root->data) {
        root->left = insert(root->left, value);
    } else if (value > root->data) {
        root->right = insert(root->right, value);
    }

    return root;
}

// Function to perform in-order traversal of the binary search tree
void inorderTraversal(struct TreeNode* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

int main() {
    int sequence[] = {50, 30, 70, 20, 40, 60, 80};
    int size = sizeof(sequence) / sizeof(sequence[0]);
int i;
    struct TreeNode* root = NULL;

    // Insert the elements one by one into the BST
    for ( i = 0; i < size; i++) {
        root = insert(root, sequence[i]);
    }

    // Perform in-order traversal to display the elements in sorted order
    printf("In-order Traversal: ");
    inorderTraversal(root);
    printf("\n");

    return 0;
}

