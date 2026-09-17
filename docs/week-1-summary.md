# Week 1 — Foundation & Dijkstra Baseline

**Status:** Complete  
**Project:** Intelligent Multi-Objective Route Optimization System with Dynamic Traffic-Aware Re-Routing

## 1. Project Setup

- Created and initialized the GitHub repository.
- Set up the Node.js project and Jest testing environment.
- Established the project structure:

```text
Code/
├── cpp/
│   ├── include/
│   ├── src/
│   └── tests/
├── src/
│   ├── algorithms/
│   ├── services/
│   └── api/
├── tests/
├── benchmarks/
├── docs/
├── papers/
└── package.json
```

- **Architecture decision:** Core routing algorithms will be implemented in **C++**, while **Node.js/Express** will later provide the API and integration layer.

## 2. Graph Implementation

Implemented a reusable **weighted directed graph** using an adjacency-list representation.

### Data Structure

```cpp
std::unordered_map<int, std::vector<Edge>>
```

Each edge is represented as:

```cpp
struct Edge {
    int destination;
    double weight;
};
```

### Graph Operations

The `Graph` class supports:

- Adding nodes
- Adding weighted directed edges
- Getting outgoing neighbors
- Getting all nodes
- Handling duplicate nodes
- Handling unknown nodes

### Files

```text
cpp/include/graph.h
cpp/src/graph.cpp
cpp/tests/test_graph.cpp
```

## 3. Dijkstra Implementation

Implemented **Dijkstra's shortest-path algorithm** as the project's baseline routing algorithm.

Dijkstra will serve as the **correctness reference** for future shortest-path algorithms such as A*, Bidirectional A*, and Contraction Hierarchies.

### Main Data Structures

- `std::priority_queue` — min-priority queue for selecting the lowest-cost node.
- `std::unordered_map<int, double>` — stores shortest known distances.
- `std::unordered_map<int, int>` — stores predecessor information for path reconstruction.

### Result Structure

```cpp
struct DijkstraResult {
    double distance;
    std::vector<int> path;
    int nodesExpanded;
    int edgesExamined;
};
```

The result provides:

- `distance` — total path cost
- `path` — source-to-destination node sequence
- `nodesExpanded` — number of expanded nodes
- `edgesExamined` — number of examined edges

The search statistics are retained for use during the project's later benchmarking phase.

### Files

```text
cpp/include/dijkstra.h
cpp/src/dijkstra.cpp
cpp/tests/test_dijkstra.cpp
```

## 4. Testing

Dijkstra was tested for:

- Normal shortest-path calculation
- Source equal to destination
- Unreachable destination
- Selecting the lower-cost path when multiple paths exist

All Dijkstra tests passed.

The graph implementation was also tested for basic node and edge operations.

## 5. Build & Run Tests

### Graph Tests

```powershell
g++ -std=c++17 -Icpp/include cpp/src/graph.cpp cpp/tests/test_graph.cpp -o cpp/test_graph
.\cpp\test_graph.exe
```

### Dijkstra Tests

```powershell
g++ -std=c++17 -Icpp/include cpp/src/graph.cpp cpp/src/dijkstra.cpp cpp/tests/test_dijkstra.cpp -o cpp/test_dijkstra
.\cpp\test_dijkstra.exe
```

### JavaScript Tests

The Node.js/Jest environment can be run with:

```powershell
$env:NODE_OPTIONS="--experimental-vm-modules"
npm test
```

## 6. Git Milestone

All Week 1 work was committed and pushed to the GitHub repository.

Final repository state:

```text
main
up to date with origin/main
working tree clean
```

Repository:

https://github.com/sarthakbisht111/route-optimization

## 7. Important Decisions

| Area | Decision |
|---|---|
| Graph representation | Adjacency list |
| Graph type | Weighted directed graph |
| Core language | C++ |
| API layer | Node.js + Express |
| Baseline algorithm | Dijkstra |
| Future correctness reference | Dijkstra |
| Benchmark statistics | Nodes expanded, edges examined |
| Development approach | Implement only planned tasks for each week |

## 8. Week 1 Outcome

The foundational routing layer is complete.

The project now has:

- A reusable graph data structure
- A working Dijkstra implementation
- Path reconstruction
- Unreachable-path handling
- Basic algorithm statistics
- Automated/basic test coverage
- C++ routing core structure
- Node.js project structure
- GitHub repository and milestone commit

## 9. Week 2 Starting Point

According to the project plan, Week 2 focuses on:

1. **A* router implementation**
2. **Generic traffic simulator**
3. **A* vs Dijkstra correctness tests**
4. Commit and push

The traffic simulator is intended to be reusable by the dynamic re-routing system planned for Week 7.

---

**Week 1 — Complete**
