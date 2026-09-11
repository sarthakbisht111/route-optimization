#ifndef DIJKSTRA_H
#define DIJKSTRA_H

#include "graph.h"
#include <vector>

struct DijkstraResult {
    double distance;
    std::vector<int> path;
};

DijkstraResult dijkstra(
    const Graph& graph,
    int source,
    int destination
);

#endif