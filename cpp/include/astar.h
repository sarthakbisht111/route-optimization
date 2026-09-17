#ifndef ASTAR_H
#define ASTAR_H

#include "graph.h"
#include <vector>

struct AStarResult {
    double distance;
    std::vector<int> path;
    int nodesExpanded;
    int edgesExamined;
};

AStarResult astar(
    const Graph& graph,
    int source,
    int destination
);

#endif