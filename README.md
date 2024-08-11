# Graph Implementation in C++ with DFS and BFS Traversals

This repository contains a C++ implementation of a graph data structure using an adjacency list. It includes methods for adding and removing edges, counting vertices, and performing both Depth-First Search (DFS) and Breadth-First Search (BFS) traversals. The code is designed to be simple yet efficient, making it a great resource for learning or integrating into other projects.

## Table of Contents
- [Introduction](#introduction)
- [Features](#features)
- [Usage](#usage)
- [DFS Traversal](#dfs-traversal)
- [BFS Traversal](#bfs-traversal)
- [Code Snippets](#code-snippets)
- [How to Run](#how-to-run)
- [Contributing](#contributing)

## Introduction

Graphs are versatile data structures used in a variety of applications such as social networks, pathfinding algorithms, and network flow analysis. This implementation provides a basic, easy-to-understand graph structure with support for directed and undirected graphs. It also includes two fundamental graph traversal algorithms: DFS and BFS.

## Features

- **Directed and Undirected Graphs:** Supports both types of graphs.
- **Add/Remove Edges:** Easily manage the edges between nodes.
- **DFS Traversal:** Depth-first search to explore nodes as deep as possible.
- **BFS Traversal:** Breadth-first search to explore nodes level by level.
- **Vertex Count:** Retrieve the number of vertices in the graph.
- **Neighbors:** List all neighbors of a specific vertex.

## Usage

To use this graph implementation, include the `Graph` class in your C++ project. The class provides methods for adding/removing edges and performing DFS and BFS traversals.

### Example

```cpp
#include "Graph.h"

int main() {
    Graph g;
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 3);

    // Perform BFS and DFS starting from vertex 0
    g.bfs(0);
    cout << endl;
    g.dfs(0);

    return 0;
}
```

## DFS Traversal

Depth-First Search (DFS) is an algorithm for traversing or searching tree or graph data structures. The algorithm starts at the root node and explores as far as possible along each branch before backtracking.

### DFS Code Snippet

```cpp
void dfs(int v, vector<bool>& visited) {
    // Mark the current node as visited and print it
    visited[v] = true;
    cout << v << " ";

    // Recur for all the vertices adjacent to this vertex
    for (int i : adjList[v]) {
        if (!visited[i]) {
            dfs(i, visited);
        }
    }
}

void dfs(int start) {
    vector<bool> visited(vertexCount(), false);
    dfs(start, visited);
}
```

## BFS Traversal

Breadth-First Search (BFS) is an algorithm for traversing or searching tree or graph data structures. It starts at an arbitrary node and explores the neighbor nodes at the present depth before moving on to nodes at the next depth level.

### BFS Code Snippet

```cpp
void bfs(int start) {
    vector<bool> visited(vertexCount(), false);
    queue<int> q;

    visited[start] = true;
    q.push(start);

    while (!q.empty()) {
        int v = q.front();
        cout << v << " ";
        q.pop();

        // Get all adjacent vertices of the dequeued vertex v
        // If an adjacent has not been visited, mark it visited and enqueue it
        for (int i : adjList[v]) {
            if (!visited[i]) {
                visited[i] = true;
                q.push(i);
            }
        }
    }
}
```

## Code Snippets

### Adding an Edge

```cpp
void addEdge(int u, int v) {
    adjList[u].push_back(v);
    if (!is_directed) {
        adjList[v].push_back(u);
    }
}
```

### Removing an Edge

```cpp
void removeEdge(int u, int v) {
    adjList[u].remove(v);
    if (!is_directed) {
        adjList[v].remove(u);
    }
}
```

### Counting Vertices

```cpp
int vertexCount() {
    return adjList.size();
}
```

### Getting Neighbors

```cpp
list<int> neighbors(int vertex) {
    return adjList[vertex];
}
```

## How to Run

To compile and run the code, follow these steps:

1. Save the code in a file named `main.cpp`.
2. Use a C++ compiler to compile the code:
   ```bash
   g++ -o graph main.cpp
   ```
3. Run the compiled program:
   ```bash
   ./graph
   ```

## Contributing

Contributions are welcome! If you have any suggestions, improvements, or new features to add, feel free to fork the repository and submit a pull request.

