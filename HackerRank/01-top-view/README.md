# Top View of Binary Search Tree

## Problem Description

Given a Binary Search Tree (BST), print the top view of the tree.

The top view consists of the nodes that are visible when looking at the tree from above.

## Solution Approach

The solution uses **Breadth-First Search (BFS)** with horizontal distance tracking.

Each node is assigned a horizontal distance:

- Root node: `0`
- Left child: `horizontal distance - 1`
- Right child: `horizontal distance + 1`

A `map` is used to store the first node found at each horizontal distance.

Because BFS visits nodes level by level, the first node stored for each horizontal distance is the node visible from the top.

## How It Works

Example tree:

```txt
        5
       / \
      3   7
     / \
    2   4
```

Horizontal distances:

```txt
        5(0)
       /    \
    3(-1)   7(1)
    /   \
 2(-2) 4(0)
```

Top view:

```txt
2 3 5 7
```

Node `4` is not included because it has the same horizontal distance as `5`, but it is below `5`.

## Input Format

The first line contains an integer `t`, the number of nodes.

The next `t` values are integers to be inserted into the BST.

Example:

```txt
5
5 3 7 2 4
```

## Output Format

Print the nodes in the top view from left to right.

Example output:

```txt
2 3 5 7
```

## Usage

Run the program:

```bash
./main
```

Then enter input:

```txt
5
5 3 7 2 4
```

Output:

```txt
2 3 5 7
```

## Key Concepts

- Binary Search Tree insertion
- Breadth-First Search
- Horizontal distance
- `queue`
- `map`

## Complexity

Let `n` be the number of nodes.

- Time Complexity: `O(n log n)`
- Space Complexity: `O(n)`

The `log n` factor comes from using `map` to store nodes by horizontal distance.