## Week 2 — A* + Traffic Base
  - Status: Complete
  - Project: Intelligent Multi-Objective Route Optimization System with Dynamic Traffic-Aware Re-Routing

## 1. A* Router Implementation
  - Implemented the A* shortest-path algorithm on the Week 1 weighted graph.
    Added:
    - cpp/include/astar.h
    - cpp/src/astar.cpp
    - Implemented priority-queue based node exploration and path reconstruction.
    - Added route statistics:
    - Total distance/cost
    - Path
    - Nodes expanded
    - Edges examined
    - Current heuristic is h(n) = 0 because the graph does not yet contain geographic coordinates.
## 2. Traffic Simulator
 - Implemented a generic traffic simulator for dynamically changing road costs.
    Added:
    - cpp/include/traffic_simulator.h
    - cpp/src/traffic_simulator.cpp
    - Traffic is represented using a multiplier:
    - Effective Cost = Base Weight × Traffic Multiplier
    - Supports setting, updating, retrieving and clearing traffic conditions.
    - Added validation for invalid traffic multipliers.
    - Designed to be reused later for Week 7 Dynamic Re-Routing.
## 3. Testing
- Added test_astar.cpp to verify A* against the Week 1 Dijkstra baseline.
    Tested:
    - Shortest path
    - Alternative routes
    - Unreachable destination
    - Source = destination
    Added test_traffic_simulator.cpp covering traffic updates, replacement, clearing and invalid values.
    All A and traffic simulator tests passed.*
## 4. Git
- Updated .gitignore to ignore generated .obj files.
    Created commit:
    - 3fca66a Implement A* routing and traffic simulator
    - Successfully pushed Week 2 to GitHub.
    ## Week 2 Status: Complete 