# README

## Constructing a Binary Tree from Inorder and Postorder Traversals

### Problem Description
Given two sequences representing the inorder and postorder traversals of a binary tree, the goal is to reconstruct the original binary tree and print its preorder traversal.

### Solution Approach
The solution involves recursively building the binary tree using the properties of inorder and postorder traversals.

### Algorithm Overview

1. **Identify the root node:**
   - The last element in the postorder traversal is the root of the tree.

2. **Locate the root in the inorder sequence:**
   - The position of the root in the inorder sequence divides the elements into left and right subtrees.

3. **Recursively construct the left and right subtrees:**
   - Use the elements before the root's position in the inorder sequence for the left subtree.
   - Use the elements after the root's position for the right subtree.

4. **Continue the process until the entire tree is constructed.**

### Detailed Algorithm (Pseudocode)

```
FUNCTION buildTree(inorder, postorder, inStart, inEnd, postIndex)
    IF inStart > inEnd:
        RETURN NULL

    rootVal <- postorder[postIndex]
    root <- createNode(rootVal)
    postIndex <- postIndex - 1

    rootPosition <- findIndex(inorder, inStart, inEnd, rootVal)

    // Build right subtree first (postorder processing order)
    root.right <- buildTree(inorder, postorder, rootPosition + 1, inEnd, postIndex)
    root.left <- buildTree(inorder, postorder, inStart, rootPosition - 1, postIndex)

    RETURN root

FUNCTION findIndex(arr, start, end, value)
    FOR i FROM start TO end
        IF arr[i] == value
            RETURN i
    RETURN -1

FUNCTION printPreorder(root)
    IF root IS NULL
        RETURN
    PRINT root.val
    printPreorder(root.left)
    printPreorder(root.right)
```

### Example Walkthrough

#### Input:
```
Inorder   : [4, 2, 5, 1, 6, 3, 7]
Postorder : [4, 5, 2, 6, 7, 3, 1]
```

#### Step-by-Step Execution:
```
1. Root from postorder: 1
   Left subtree: [4, 2, 5]
   Right subtree: [6, 3, 7]

2. Process right subtree:
   Root: 3
   Left subtree: [6]
   Right subtree: [7]

3. Process left subtree:
   Root: 2
   Left subtree: [4]
   Right subtree: [5]
```

#### Expected Output (Preorder):
```
1 2 4 5 3 6 7
```

### Complexity Analysis

- **Time Complexity:** O(n), where n is the number of nodes (each node is processed once).
- **Space Complexity:** O(n), for recursive stack and storage of the tree.

### Usage Instructions

1. Compile the code using:
   ```
   make
   ```

2. Run the binary:
   ```
   ./BINARY_TREE
   ```

3. Observe the preorder traversal output for test cases.

---

Author: Trương Quốc Ánh
Date: 2025-01-20

