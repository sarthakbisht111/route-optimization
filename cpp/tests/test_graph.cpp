#include <cassert>
#include <iostream>

#include "graph.h"

void testAddNodes() {
    Graph graph;

    graph.addNode(1);
    graph.addNode(2);

    auto nodes = graph.getNodes();

    assert(nodes.size() == 2);

    std::cout << "PASS: addNode\n";
}

void testAddEdge() {
    Graph graph;

    graph.addEdge(1, 2, 5.0);

    const auto& neighbors = graph.getNeighbors(1);

    assert(neighbors.size() == 1);
    assert(neighbors[0].destination == 2);
    assert(neighbors[0].weight == 5.0);

    std::cout << "PASS: addEdge\n";
}

void testNoDuplicateEdgesFromAddNode() {
    Graph graph;

    graph.addNode(1);
    graph.addNode(1);

    auto nodes = graph.getNodes();

    assert(nodes.size() == 1);

    std::cout << "PASS: duplicate node handling\n";
}

void testUnknownNode() {
    Graph graph;

    const auto& neighbors = graph.getNeighbors(999);

    assert(neighbors.empty());

    std::cout << "PASS: unknown node handling\n";
}

int main() {
    testAddNodes();
    testAddEdge();
    testNoDuplicateEdgesFromAddNode();
    testUnknownNode();

    std::cout << "\nAll graph tests passed!\n";

    return 0;
}