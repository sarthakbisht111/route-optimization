#ifndef TRAFFIC_SIMULATOR_H
#define TRAFFIC_SIMULATOR_H

#include <unordered_map>
#include <vector>

struct TrafficUpdate {
    int source;
    int destination;
    double multiplier;
};

class TrafficSimulator {
public:
    void setTraffic(
        int source,
        int destination,
        double multiplier
    );

    double getMultiplier(
        int source,
        int destination
    ) const;

    double getTravelTime(
        int source,
        int destination,
        double baseWeight
    ) const;

    void clearTraffic();

    std::vector<TrafficUpdate> getActiveUpdates() const;

private:
    std::unordered_map<long long, double> trafficMultipliers;

    long long makeKey(
        int source,
        int destination
    ) const;
};

#endif