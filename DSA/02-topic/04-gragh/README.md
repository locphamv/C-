# Graph Data Structures

This folder contains implementations and exercises related to **Graph** algorithms and data structures.

## Overview

A graph is a non-linear data structure consisting of vertices (nodes) and edges. Graphs are used to represent networks, relationships, and connections.

## Key Concepts

### Graph Representations

1. **Adjacency Matrix**
   - 2D array where `a[i][j] = 1` if there's an edge from vertex i to j
   - Space Complexity: O(V²)
   - Good for dense graphs

2. **Adjacency List**
   - Array of vectors/lists storing neighbors of each vertex
   - Space Complexity: O(V + E)
   - Good for sparse graphs

3. **Edge List**
   - List of all edges in the graph
   - Useful for certain algorithms

### Common Algorithms

- **DFS (Depth First Search)**: Explore graph using stack
- **BFS (Breadth First Search)**: Explore graph using queue
- **Topological Sort**: Order vertices linearly respecting dependencies
- **Dijkstra's Algorithm**: Shortest path in weighted graphs
- **Floyd-Warshall**: All pairs shortest paths
- **Kruskal's/Prim's**: Minimum Spanning Tree
- **Bipartite Check**: Determine if graph is bipartite

## Files

- `main.cpp` - Graph adjacency matrix implementation

## Compilation & Execution

```bash
clang++ -std=c++17 main.cpp -o main
./main
```

## Time Complexity Reference

| Operation | Adjacency Matrix | Adjacency List |
|-----------|------------------|-----------------|
| Add Edge  | O(1)             | O(1)            |
| Remove Edge | O(1)           | O(degree)       |
| Check Edge | O(1)            | O(degree)       |
| Get Neighbors | O(V)         | O(degree)       |
| Space | O(V²)              | O(V + E)        |

## Notes

- Choose representation based on graph density
- Dense graphs (many edges): Adjacency Matrix
- Sparse graphs (few edges): Adjacency List
