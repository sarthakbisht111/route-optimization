#include "traffic_simulator.h"

#include <stdexcept>

long long TrafficSimulator::makeKey(
    int source,
    int destination
) const {
    return (static_cast<long long>(source) << 32) |
           static_cast<unsigned int>(destination);
}

void TrafficSimulator::setTraffic(
    int source,
    int destination,
    double multiplier
) {
    if (multiplier <= 0.0) {
        throw std::invalid_argument(
            "Traffic multiplier must be greater than zero"
        );
    }

    trafficMultipliers[
        makeKey(source, destination)
    ] = multiplier;
}

double TrafficSimulator::getMultiplier(
    int source,
    int destination
) const {
    auto key = makeKey(source, destination);

    auto it = trafficMultipliers.find(key);

    if (it == trafficMultipliers.end()) {
        return 1.0;
    }

    return it->second;
}

double TrafficSimulator::getTravelTime(
    int source,
    int destination,
    double baseWeight
) const {
    return baseWeight *
           getMultiplier(source, destination);
}

void TrafficSimulator::clearTraffic() {
    trafficMultipliers.clear();
}

std::vector<TrafficUpdate>
TrafficSimulator::getActiveUpdates() const {

    std::vector<TrafficUpdate> updates;

    for (const auto& entry : trafficMultipliers) {

        int source =
            static_cast<int>(
                entry.first >> 32
            );

        int destination =
            static_cast<int>(
                entry.first & 0xFFFFFFFF
            );

        updates.push_back({
            source,
            destination,
            entry.second
        });
    }

    return updates;
}