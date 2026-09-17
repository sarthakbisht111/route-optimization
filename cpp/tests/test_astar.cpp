#include <cassert>
#include <cmath>
#include <iostream>
#include <vector>

#include "astar.h"
#include "dijkstra.h"

void testAStarMatchesDijkstra() {
    Graph graph;

    graph.addEdge(1, 2, 5.0);
    graph.addEdge(1, 3, 2.0);
    graph.addEdge(3, 4, 3.0);
    graph.addEdge(2, 4, 1.0);

    DijkstraResult dijkstraResult = dijkstra(graph, 1, 4);
    AStarResult astarResult = astar(graph, 1, 4);

    assert(astarResult.distance == dijkstraResult.distance);
    assert(astarResult.path == dijkstraResult.path);

    std::cout << "PASS: A* matches Dijkstra\n";
}

void testAStarMatchesDijkstraOnAlternativeRoutes() {
    Graph graph;

    graph.addEdge(1, 2, 10.0);
    graph.addEdge(1, 3, 2.0);
    graph.addEdge(3, 2, 3.0);
    graph.addEdge(2, 4, 4.0);
    graph.addEdge(3, 4, 20.0);

    DijkstraResult dijkstraResult = dijkstra(graph, 1, 4);
    AStarResult astarResult = astar(graph, 1, 4);

    assert(astarResult.distance == dijkstraResult.distance);
    assert(astarResult.path == dijkstraResult.path);

    std::cout << "PASS: A* matches Dijkstra on alternative routes\n";
}

void testUnreachableDestination() {
    Graph graph;

    graph.addEdge(1, 2, 5.0);
    graph.addNode(3);

    DijkstraResult dijkstraResult = dijkstra(graph, 1, 3);
    AStarResult astarResult = astar(graph, 1, 3);

    assert(std::isinf(dijkstraResult.distance));
    assert(std::isinf(astarResult.distance));

    assert(dijkstraResult.path.empty());
    assert(astarResult.path.empty());

    std::cout << "PASS: A* and Dijkstra handle unreachable destination\n";
}

void testSourceEqualsDestination() {
    Graph graph;

    graph.addNode(1);

    DijkstraResult dijkstraResult = dijkstra(graph, 1, 1);
    AStarResult astarResult = astar(graph, 1, 1);

    assert(dijkstraResult.distance == 0.0);
    assert(astarResult.distance == 0.0);

    assert(dijkstraResult.path == astarResult.path);

    std::cout << "PASS: A* and Dijkstra handle source equals destination\n";
}

int main() {
    testAStarMatchesDijkstra();
    testAStarMatchesDijkstraOnAlternativeRoutes();
    testUnreachableDestination();
    testSourceEqualsDestination();

    std::cout << "\nAll A* vs Dijkstra tests passed!\n";

    return 0;
}