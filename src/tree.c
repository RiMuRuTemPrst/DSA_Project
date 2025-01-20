#include "tree.h"

// Create a new tree node
TreeNode* createNode(int val) {
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Find the index of a value in the inorder array
int findIndex(int* arr, int start, int end, int value) {
    for (int i = start; i <= end; i++) {
        if (arr[i] == value) {
            return i;
        }
    }
    return -1;
}

// Build binary tree from inorder and postorder traversal
TreeNode* buildTreeHelper(int* inorder, int* postorder, int inorderStart, int inorderEnd, int* postIndex) {
    if (inorderStart > inorderEnd) {
        return NULL;
    }

    int rootVal = postorder[(*postIndex)--];
    TreeNode* root = createNode(rootVal);

    int rootPos = findIndex(inorder, inorderStart, inorderEnd, rootVal);

    root->right = buildTreeHelper(inorder, postorder, rootPos + 1, inorderEnd, postIndex);
    root->left = buildTreeHelper(inorder, postorder, inorderStart, rootPos - 1, postIndex);

    return root;
}

TreeNode* buildTree(int* inorder, int* postorder, int length) {
    int postIndex = length - 1;
    return buildTreeHelper(inorder, postorder, 0, length - 1, &postIndex);
}

// Print tree in preorder
void printTreePreorder(TreeNode* root) {
    if (root == NULL) {
        return;
    }
    printf("%d ", root->val);
    printTreePreorder(root->left);
    printTreePreorder(root->right);
}

// Free allocated memory for the tree
void freeTree(TreeNode* root) {
    if (root == NULL) return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}
