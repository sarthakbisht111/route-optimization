#include <cassert>
#include <cmath>
#include <iostream>

#include "dijkstra.h"

void testShortestPath() {
    Graph graph;

    graph.addEdge(1, 2, 5.0);
    graph.addEdge(1, 3, 2.0);
    graph.addEdge(3, 4, 3.0);
    graph.addEdge(2, 4, 1.0);

    DijkstraResult result = dijkstra(graph, 1, 4);

    assert(result.distance == 5.0);

    std::vector<int> expectedPath = {1, 3, 4};

    assert(result.path == expectedPath);

    std::cout << "PASS: shortest path\n";
}

void testSourceEqualsDestination() {
    Graph graph;

    graph.addNode(1);

    DijkstraResult result = dijkstra(graph, 1, 1);

    assert(result.distance == 0.0);

    std::vector<int> expectedPath = {1};

    assert(result.path == expectedPath);

    std::cout << "PASS: source equals destination\n";
}

void testUnreachableDestination() {
    Graph graph;

    graph.addEdge(1, 2, 5.0);
    graph.addNode(3);

    DijkstraResult result = dijkstra(graph, 1, 3);

    assert(std::isinf(result.distance));
    assert(result.path.empty());

    std::cout << "PASS: unreachable destination\n";
}

void testChoosesLowerCostPath() {
    Graph graph;

    graph.addEdge(1, 2, 10.0);
    graph.addEdge(1, 3, 2.0);
    graph.addEdge(3, 2, 3.0);

    DijkstraResult result = dijkstra(graph, 1, 2);

    assert(result.distance == 5.0);

    std::vector<int> expectedPath = {1, 3, 2};

    assert(result.path == expectedPath);

    std::cout << "PASS: lower cost path selection\n";
}

int main() {
    testShortestPath();
    testSourceEqualsDestination();
    testUnreachableDestination();
    testChoosesLowerCostPath();

    std::cout << "\nAll Dijkstra tests passed!\n";

    return 0;
}