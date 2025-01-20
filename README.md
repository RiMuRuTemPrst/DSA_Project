# Constructing a Binary Tree from an Ancestor Matrix

## Overview
Given an **ancestor matrix**, our goal is to construct the corresponding binary tree and print its preorder traversal.

### Ancestor Matrix Definition
An ancestor matrix is a square matrix where:
- `matrix[i][j] = 1` indicates that node `i` is an ancestor of node `j`.
- `matrix[i][j] = 0` otherwise.

## Solution Approach
### Steps to Construct the Tree
1. **Identify root node:**
   - A node with no ancestors (all zeros in its column) is the root.

2. **Construct child-parent relationships:**
   - Traverse through the matrix to identify parent-child connections.

3. **Build the tree structure:**
   - Use recursive or iterative approaches to link nodes accordingly.

4. **Print the tree in preorder:**
   - Visit root node, left subtree, then right subtree.

### Algorithm Pseudocode

```
FUNCTION constructTreeFromAncestorMatrix(matrix, size)
    CREATE parent[size] array initialized to 0
    CREATE nodes[size] array

    FOR i FROM 0 TO size-1
        nodes[i] <- CREATE node(i)

    FOR i FROM 0 TO size-1
        FOR j FROM 0 TO size-1
            IF matrix[i][j] == 1
                parent[j] <- 1

    root <- NULL
    FOR i FROM 0 TO size-1
        IF parent[i] == 0
            root <- nodes[i]

    FOR i FROM 0 TO size-1
        FOR j FROM 0 TO size-1
            IF matrix[i][j] == 1
                IF nodes[i].left IS NULL
                    nodes[i].left <- nodes[j]
                ELSE
                    nodes[i].right <- nodes[j]

    RETURN root

FUNCTION preorderTraversal(node)
    IF node IS NULL
        RETURN
    PRINT node.val
    preorderTraversal(node.left)
    preorderTraversal(node.right)
```

## Input and Output

### Test Case 1
**Input Matrix:**
```
0 1 1 0 0
0 0 0 0 0
0 0 0 1 1
0 0 0 0 0
0 0 0 0 0
```
**Tree Structure:**
```
       0
      / \
     1   2
        / \
       3   4
```
**Preorder Output:**
```
0 1 2 3 4
```

---

### Test Case 2
**Input Matrix:**
```
0 1 1 0 0
0 0 0 0 1
0 0 0 0 0
0 0 0 0 0
0 0 0 0 0
```
**Tree Structure:**
```
       0
      / \
     1   2
      \
       4
```
**Preorder Output:**
```
0 1 4 2
```

---

### Test Case 3
**Input Matrix:**
```
0 1 0 0 0
0 0 1 0 0
0 0 0 1 0
0 0 0 0 1
0 0 0 0 0
```
**Tree Structure:**
```
       0
        \
         1
          \
           2
            \
             3
              \
               4
```
**Preorder Output:**
```
0 1 2 3 4
```

---

### Test Case 4
**Input Matrix:**
```
0 1 0 0 0
0 0 0 0 0
0 0 0 0 0
0 0 0 0 1
0 0 0 0 0
```
**Tree Structure:**
```
       0
      /
     1
```
**Preorder Output:**
```
0 1
```

---

### Test Case 5
**Input Matrix:**
```
0 1 1 0 0
0 0 0 1 1
0 0 0 0 0
0 0 0 0 0
0 0 0 0 0
```
**Tree Structure:**
```
       0
      / \
     1   2
    / \
   3   4
```
**Preorder Output:**
```
0 1 3 4 2
```
---

### Test Case 6
**Input Matrix:**
```
0 1 0 0 0
0 0 0 0 1
0 0 0 1 0
0 0 0 0 0
0 0 0 0 0
```
**Tree Structure:**
```
       0
        \
         1
          \
           4
```
**Preorder Output:**
```
0 1 4
```

---

### Test Case 7
**Input Matrix:**
```
0 1 1 0 0
0 0 0 0 0
0 0 0 1 0
0 0 0 0 1
0 0 0 0 0
```
**Tree Structure:**
```
       0
      / \
     1   2
          \
           3
            \
             4
```
**Preorder Output:**
```
0 1 2 3 4
```

---

### Test Case 8
**Input Matrix:**
```
0 1 0 0 0
0 0 1 0 0
0 0 0 0 0
0 0 0 0 1
0 0 0 0 0
```
**Tree Structure:**
```
       0
        \
         1
          \
           2
```
**Preorder Output:**
```
0 1 2
```

---

### Test Case 9
**Input Matrix:**
```
0 1 1 0 0
0 0 0 0 1
0 0 0 1 0
0 0 0 0 0
0 0 0 0 0
```
**Tree Structure:**
```
       0
      / \
     1   2
        /
       3
```
**Preorder Output:**
```
0 1 2 3
```

---

### Test Case 10
**Input Matrix:**
```
0 1 0 0 0
0 0 0 0 0
0 0 1 0 0
0 0 0 0 1
0 0 0 0 0
```
**Tree Structure:**
```
       0
        \
         1
          \
           2
            \
             4
```
**Preorder Output:**
```
0 1 2 4
```

## Complexity Analysis

- **Time Complexity:** `O(n^2)` due to matrix traversal.
- **Space Complexity:** `O(n)` for storing nodes.

## How to Run the Program

1. **Compile the code using:**
   ```
   make
   ```
2. **Run the executable:**
   ```
   ./TREE
   ```
3. **Observe the preorder traversal output for test cases.**


