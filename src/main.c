/**
 * @file main.c
 * @author Trương Quốc Ánh (anh.tq224430@sis.hust.edu.vn)
 * @brief 
------------------------------------------------------------------------
Construct a binary tree from inorder and postorder traversals:
Example: 
Inorder Traversal   : { 4, 2, 1, 7, 5, 8, 3, 6 }
Postorder Traversal : { 4, 2, 7, 8, 5, 6, 3, 1 }
The binary Tree: 
        1
       / \
      2   3
     /   / \
    4   5   6
       / \
      7   8
    Output: 1 2 4 3 5 7 8 6
------------------------------------------------------------------------
 * @version 0.1
 * @date 2025-01-20
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#include "tree.h"

void runTestCases() {
    // {{Inorder Traversal},{Postorder Traversal}}
    int testCases[10][2][7] = {
        // Test case 1:
        {{4, 2, 5, 1, 6, 3, 7}, {4, 5, 2, 6, 7, 3, 1}},
        /**
         * @note: Expected Out                   
        1
       / \
      2   3
     / \  / \
    4   5 6  7
         *
         */
        // Test case 2:
        {{9, 3, 15, 20, 7}, {9, 15, 7, 20, 3}},
        /**
         * @brief Expected Output:
         * 
        3
       / \
      9   20
          /  \
         15   7
         */
        // Test Case 3:
        {{1, 2, 3}, {3, 2, 1}},
        /**
         * @brief Expected Output:
         * 1
         *  \ 
         *   2
         *    \ 
         *     3
         **/
        // Test case 4:
        {{1}, {1}},
        /**
         * @brief: Expected Output:
         * 1
         */
        // Test case 5:
        {{1, 2}, {2, 1}},
        /**
         * @brief: Expected Output:
         * 1
         *  \
         *   2
         **/
        // Test case 6:
        {{2, 1}, {2, 1}},
        /**
         * @brief: Expected output
         *    1
         *   /
         * 2
         */
        // Test case 7:
        {{3, 2, 1}, {3, 2, 1}},
        /**
         * @brief: Expected Output
         *      1
         *    /
         *   2 
         *  /
         * 3
         */
        // Test case 8:
        {{7, 3, 1, 5, 4}, {7, 3, 4, 5, 1}},
        /**
         * @brief: Expected Output
         *    1
         *   / \
         *  3   5
         * /     \
         * 7      4
         */
        // Test case 9:
        {{5, 10, 20}, {5, 20, 10}},
        /**
         * @brief: Expected Output
         *    10
         *   / \
         * 5   20
         */
        // Test case 10:
        {{11, 14, 13, 15, 12}, {11, 14, 15, 13, 12}}
        /**
         * @brief: Expected Output
         *        12
         *      /  \
         *    13    
         *   /  \ 
         *  14   15
         *  /
         * 11   
         */
    };

    int testSizes[10] = {7, 5, 3, 1, 2, 2, 3, 5, 3, 5};

    for (int i = 0; i < 10; i++) {
        printf("Test case %d:\n", i + 1);
        TreeNode* root = buildTree(testCases[i][0], testCases[i][1], testSizes[i]);
        printTreePreorder(root);
        printf("\n");
        freeTree(root);
    }
}

int main() {
    printf("Running test cases for building binary tree from inorder and postorder:\n");
    runTestCases();
    return 0;
}

