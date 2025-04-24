#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left, *right;
} Node;

Node *newNode(int data) {
    Node *temp = (Node *)malloc(sizeof(Node));
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

int isValidBST(Node *root, int min, int max) {
    if (root == NULL)
        return 1;
    if (root->data < min || root->data > max)
        return 0;
    return isValidBST(root->left, min, root->data - 1) &&
           isValidBST(root->right, root->data + 1, max);
}

int main() {
    /* Constructing the following BST:
                8
              /   \
             3    10
            / \     \
           1   6     14
    */
    Node *root = newNode(8);
    root->left = newNode(3);
    root->right = newNode(10);
    root->left->left = newNode(1);
    root->left->right = newNode(6);
    root->right->right = newNode(14);

    if (isValidBST(root, INT_MIN, INT_MAX))
        printf("The tree is a valid binary search tree.\n");
    else
        printf("The tree is not a valid binary search tree.\n");

    return 0;
}