#ifndef TREE_H
#define TREE_H

#include <stdio.h>
#include <stdlib.h>

// Structure for binary tree node
typedef struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

// Function declarations
TreeNode* createNode(int val);
TreeNode* buildTree(int* inorder, int* postorder, int length);
void printTreePreorder(TreeNode* root);
void freeTree(TreeNode* root);
#endif