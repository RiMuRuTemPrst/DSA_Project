#include "ancestor_matrix_tree.h"

// Create a new tree node
TreeNode* createNode(int val) {
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

/**
 * @brief Constructs a binary tree from an ancestor matrix.
 * 
 * This function takes an N x N ancestor matrix, where each cell (i, j)
 * indicates whether node i is an ancestor of node j in a binary tree.
 * It constructs and returns the root of the binary tree where nodes
 * are labeled from 0 to N-1.
 * 
 * @param ancestorMatrix A 2D array representing the ancestor matrix.
 * @param size The size of the matrix (number of nodes in the tree).
 * @return TreeNode* The root of the constructed binary tree.
 */

TreeNode* constructTreeFromAncestorMatrix(int** ancestorMatrix, int size) {
    int* parent = (int*)calloc(size, sizeof(int));
    TreeNode** nodes = (TreeNode**)malloc(size * sizeof(TreeNode*));

    for (int i = 0; i < size; i++) {
        nodes[i] = createNode(i);
    }

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (ancestorMatrix[i][j] == 1) {
                parent[j] = 1;
            }
        }
    }

    TreeNode* root = NULL;
    for (int i = 0; i < size; i++) {
        if (parent[i] == 0) {
            root = nodes[i];
            break;
        }
    }

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (ancestorMatrix[i][j] == 1) {
                if (nodes[i]->left == NULL) {
                    nodes[i]->left = nodes[j];
                } else {
                    nodes[i]->right = nodes[j];
                }
            }
        }
    }

    free(parent);
    free(nodes);
    return root;
}


/**
 * @brief Prints the tree in pre-order traversal
 * 
 * This function prints the tree in pre-order traversal, i.e.,
 * parent node, left subtree, right subtree.
 * 
 * @param root Pointer to the root node of the tree
 */
void printPreorder(TreeNode* root) {
    if (root == NULL) return;
    printf("%d ", root->val);
    printPreorder(root->left);
    printPreorder(root->right);
}


/**
 * @brief Frees all nodes in a binary tree
 * 
 * @param root Pointer to the root node of the tree to be freed
 * 
 * @note This function traverses the tree in post-order and frees memory
 * allocated for each node, ensuring that the entire tree is deallocated.
 */
void freeTree(TreeNode* root) {
    if (root == NULL) return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}