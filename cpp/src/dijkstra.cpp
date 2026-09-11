#include "dijkstra.h"

#include <algorithm>
#include <limits>
#include <queue>
#include <unordered_map>
#include <unordered_set>

DijkstraResult dijkstra(
    const Graph& graph,
    int source,
    int destination
) {
    // Distance from source to each node
    std::unordered_map<int, double> distances;

    // Previous node used to reach each node
    std::unordered_map<int, int> previous;

    // Priority queue stores:
    // {distance, node}
    using QueueEntry = std::pair<double, int>;

    std::priority_queue<
        QueueEntry,
        std::vector<QueueEntry>,
        std::greater<QueueEntry>
    > priorityQueue;

    // Initialize all distances to infinity
    for (int node : graph.getNodes()) {
        distances[node] = std::numeric_limits<double>::infinity();
    }

    // Source has distance 0
    distances[source] = 0.0;

    priorityQueue.push({0.0, source});

    while (!priorityQueue.empty()) {

        auto [currentDistance, currentNode] =
            priorityQueue.top();

        priorityQueue.pop();

        // Ignore an outdated queue entry
        if (currentDistance > distances[currentNode]) {
            continue;
        }

        // We have reached the destination
        if (currentNode == destination) {
            break;
        }

        // Examine all outgoing edges
        for (const Edge& edge : graph.getNeighbors(currentNode)) {

            double newDistance =
                currentDistance + edge.weight;

            // Found a shorter path
            if (newDistance < distances[edge.destination]) {

                distances[edge.destination] = newDistance;

                previous[edge.destination] = currentNode;

                priorityQueue.push({
                    newDistance,
                    edge.destination
                });
            }
        }
    }

    // Destination cannot be reached
    if (
        distances.find(destination) == distances.end() ||
        distances[destination] ==
            std::numeric_limits<double>::infinity()
    ) {
        return {
            std::numeric_limits<double>::infinity(),
            {}
        };
    }

    // Reconstruct path
    std::vector<int> path;

    int currentNode = destination;

    while (true) {
        path.push_back(currentNode);

        if (currentNode == source) {
            break;
        }

        currentNode = previous[currentNode];
    }

    // Path was reconstructed backwards
    std::reverse(path.begin(), path.end());

    return {
        distances[destination],
        path
    };
}