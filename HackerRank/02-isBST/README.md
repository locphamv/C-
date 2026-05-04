# Is Binary Search Tree (BST) Validator

## Problem Description

Validate whether a given binary tree is a valid Binary Search Tree (BST). A BST must satisfy the property that all left subtree values are less than the node value, and all right subtree values are greater than the node value.

## Solution Approach

The solution uses **in-order traversal** to validate the BST:

1. Perform an in-order traversal of the tree to collect all node values
2. Check if the collected values are in strictly increasing order
3. If yes, it's a valid BST; otherwise, it's not

## How It Works

- **In-order traversal** of a valid BST always produces values in ascending order
- If any value is not greater than the previous value, the tree is not a BST

## Input Format

- First line: height of the tree (number of levels)
- Following values: node values to fill the tree in in-order sequence

## Output Format

- `Yes` - if the tree is a valid BST
- `No` - if the tree is not a valid BST

## Sample Input and Output

**Input:**
```
2
1 2 3 4 5 6 7
```

**Output:**
```
Yes
```

**Explanation:**
- Height = 2 (complete binary tree with 2 levels, 7 nodes total)
- Values filled in-order: 1 2 3 4 5 6 7
- The resulting tree is a valid BST, so output is `Yes`

## Time Complexity

- **Time**: O(n) - visits each node once for traversal and validation
- **Space**: O(n) - stores all node values in the in-order list

## Key Concepts

- Binary Search Tree properties and validation
- In-order tree traversal
- Vector storage for sequential value checking
