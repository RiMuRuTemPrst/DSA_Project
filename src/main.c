/**
 * @file main.c
 * @author Trương Quốc Ánh (anh.tq224430@sis.hust.edu.vn)
 * @brief 
------------------------------------------------------------------------
Construct a binary tree from an ancestor matrix
Given an N × N ancestor matrix, whose cell (i, j) has the value true if i is the ancestor of j in a binary tree, 
construct a binary tree from it where binary tree nodes are labeled from 0 to N-1.
------------------------------------------------------------------------
 * @version 0.1
 * @date 2025-01-20
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#include "ancestor_matrix_tree.h"

void runTestCases() {
    int testCases[10][5][5] = {
        // Test case 1
        {{0, 1, 1, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 1, 1},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0}},
        
        // Test case 2
        {{0, 1, 1, 0, 0},
        {0, 0, 0, 0, 1},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0}},

        // Test case 3
        {{0, 1, 0, 0, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 1, 0},
        {0, 0, 0, 0, 1},
        {0, 0, 0, 0, 0}},

        // Test case 4
        {{0, 1, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 1},
        {0, 0, 0, 0, 0}},

        // Test case 5
        {{0, 1, 1, 0, 0},
        {0, 0, 0, 1, 1},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0}},

        // Test case 6
        {{0, 1, 0, 0, 0},
        {0, 0, 0, 0, 1},
        {0, 0, 0, 1, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0}},

        // Test case 7
        {{0, 1, 1, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 1, 0},
        {0, 0, 0, 0, 1},
        {0, 0, 0, 0, 0}},

        // Test case 8
        {{0, 1, 0, 0, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 1},
        {0, 0, 0, 0, 0}},

        // Test case 9
        {{0, 1, 1, 0, 0},
        {0, 0, 0, 0, 1},
        {0, 0, 0, 1, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0}},

        // Test case 10
        {{0, 1, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 1},
        {0, 0, 0, 0, 0}}
    };

    int sizes[10] = {5, 5, 5, 5, 5, 5, 5, 5, 5, 5};

    for (int i = 0; i < 10; i++) {
        printf("Test case %d:\n", i + 1);
        int** matrix = (int**)malloc(sizes[i] * sizeof(int*));
        for (int j = 0; j < sizes[i]; j++) {
            matrix[j] = (int*)malloc(sizes[i] * sizeof(int));
            for (int k = 0; k < sizes[i]; k++) {
                matrix[j][k] = testCases[i][j][k];
            }
        }

        TreeNode* root = constructTreeFromAncestorMatrix(matrix, sizes[i]);
        printPreorder(root);
        printf("\n");
        freeTree(root);

        for (int j = 0; j < sizes[i]; j++) {
            free(matrix[j]);
        }
        free(matrix);
    }
}

int main() {
    printf("Running test cases for constructing binary tree from ancestor matrix:\n");
    runTestCases();
    return 0;
}