#include "astar.h"

#include <algorithm>
#include <cmath>
#include <limits>
#include <queue>
#include <unordered_map>

namespace {

double heuristic(int node, int destination) {
    // Week 1 graph nodes only have integer IDs and no geographic
    // coordinates, so we cannot calculate a geographic distance yet.
    // Using 0 makes this implementation behave like Dijkstra while
    // keeping the A* structure ready for a future heuristic.
    (void)node;
    (void)destination;

    return 0.0;
}

}

AStarResult astar(
    const Graph& graph,
    int source,
    int destination
) {
    std::unordered_map<int, double> distances;
    std::unordered_map<int, int> previous;

    using QueueEntry = std::pair<double, int>;

    std::priority_queue<
        QueueEntry,
        std::vector<QueueEntry>,
        std::greater<QueueEntry>
    > priorityQueue;

    int nodesExpanded = 0;
    int edgesExamined = 0;

    for (int node : graph.getNodes()) {
        distances[node] =
            std::numeric_limits<double>::infinity();
    }

    if (distances.find(source) == distances.end() ||
        distances.find(destination) == distances.end()) {
        return {
            std::numeric_limits<double>::infinity(),
            {},
            nodesExpanded,
            edgesExamined
        };
    }

    distances[source] = 0.0;

    double initialPriority =
        distances[source] +
        heuristic(source, destination);

    priorityQueue.push({
        initialPriority,
        source
    });

    while (!priorityQueue.empty()) {

        auto [currentPriority, currentNode] =
            priorityQueue.top();

        priorityQueue.pop();

        double currentDistance =
            distances[currentNode];

        double expectedPriority =
            currentDistance +
            heuristic(currentNode, destination);

        if (currentPriority > expectedPriority) {
            continue;
        }

        nodesExpanded++;

        if (currentNode == destination) {
            break;
        }

        for (const Edge& edge :
             graph.getNeighbors(currentNode)) {

            edgesExamined++;

            double newDistance =
                currentDistance + edge.weight;

            if (newDistance <
                distances[edge.destination]) {

                distances[edge.destination] =
                    newDistance;

                previous[edge.destination] =
                    currentNode;

                double priority =
                    newDistance +
                    heuristic(
                        edge.destination,
                        destination
                    );

                priorityQueue.push({
                    priority,
                    edge.destination
                });
            }
        }
    }

    if (
        distances.find(destination) == distances.end() ||
        std::isinf(distances[destination])
    ) {
        return {
            std::numeric_limits<double>::infinity(),
            {},
            nodesExpanded,
            edgesExamined
        };
    }

    std::vector<int> path;

    int currentNode = destination;

    while (true) {

        path.push_back(currentNode);

        if (currentNode == source) {
            break;
        }

        currentNode = previous[currentNode];
    }

    std::reverse(path.begin(), path.end());

    return {
        distances[destination],
        path,
        nodesExpanded,
        edgesExamined
    };
}