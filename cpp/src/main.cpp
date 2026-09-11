#include <iostream>
#include "graph.h"

int main() {
    Graph graph;

    graph.addEdge(1, 2, 5.0);
    graph.addEdge(1, 3, 2.0);
    graph.addEdge(3, 4, 3.0);
    graph.addEdge(2, 4, 1.0);

    std::cout << "Neighbors of node 1:\n";

    for (const auto& edge : graph.getNeighbors(1)) {
        std::cout << "  -> " << edge.destination
                  << " (weight: " << edge.weight << ")\n";
    }

    std::cout << "\nAll nodes:\n";

    for (int node : graph.getNodes()) {
        std::cout << "  " << node << '\n';
    }

    return 0;
}