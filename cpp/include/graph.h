#ifndef GRAPH_H
#define GRAPH_H

#include <unordered_map>
#include <vector>

struct Edge {
    int destination;
    double weight;
};

class Graph {
private:
    std::unordered_map<int, std::vector<Edge>> adjacencyList;

public:
    void addNode(int node);

    void addEdge(int source, int destination, double weight);

    const std::vector<Edge>& getNeighbors(int node) const;

    std::vector<int> getNodes() const;
};

#endif