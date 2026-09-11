# Week 1 — Foundation & Dijkstra Baseline

**Status:** Complete  
**Project:** Intelligent Multi-Objective Route Optimization System with Dynamic Traffic-Aware Re-Routing

## 1. Project Setup

- Created and initialized the GitHub repository.
- Set up the Node.js project and Jest testing environment.
- Established the project structure:
  - `cpp/` — C++ routing algorithm core
  - `src/` — Node.js/API layer
  - `tests/` — JavaScript tests
  - `benchmarks/` — future benchmarking work
  - `docs/` — project documentation
  - `papers/` — research papers/references
- **Architecture decision:** Core routing algorithms will be implemented in C++, while Node.js/Express will later be used for the API and integration layer.

## 2. Graph Implementation

Implemented a reusable **weighted directed graph**.

### Data Structure

The graph uses an adjacency-list representation:

```cpp
std::unordered_map<int, std::vector<Edge>>