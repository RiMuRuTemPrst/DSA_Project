#ifndef ANCESTOR_MATRIX_TREE_H
#define ANCESTOR_MATRIX_TREE_H

#include <stdio.h>
#include <stdlib.h>

// Structure for binary tree node
typedef struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;


TreeNode* constructTreeFromAncestorMatrix(int** ancestorMatrix, int size);
void printPreorder(TreeNode* root);
void freeTree(TreeNode* root);
#endif
