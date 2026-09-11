#include "graph.h"

void Graph::addNode(int node) {
    if (adjacencyList.find(node) == adjacencyList.end()) {
        adjacencyList[node] = {};
    }
}

void Graph::addEdge(int source, int destination, double weight) {
    addNode(source);
    addNode(destination);

    adjacencyList[source].push_back({
        destination,
        weight
    });
}

const std::vector<Edge>& Graph::getNeighbors(int node) const {
    static const std::vector<Edge> empty;

    auto it = adjacencyList.find(node);

    if (it == adjacencyList.end()) {
        return empty;
    }

    return it->second;
}

std::vector<int> Graph::getNodes() const {
    std::vector<int> nodes;

    for (const auto& pair : adjacencyList) {
        nodes.push_back(pair.first);
    }

    return nodes;
}