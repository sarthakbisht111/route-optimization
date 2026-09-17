#include <cassert>
#include <cmath>
#include <iostream>

#include "traffic_simulator.h"

void testDefaultTraffic() {
    TrafficSimulator simulator;

    assert(
        simulator.getMultiplier(1, 2) == 1.0
    );

    assert(
        simulator.getTravelTime(1, 2, 10.0) == 10.0
    );

    std::cout << "PASS: default traffic\n";
}

void testTrafficUpdate() {
    TrafficSimulator simulator;

    simulator.setTraffic(1, 2, 2.0);

    assert(
        simulator.getMultiplier(1, 2) == 2.0
    );

    assert(
        simulator.getTravelTime(1, 2, 10.0) == 20.0
    );

    std::cout << "PASS: traffic update\n";
}

void testTrafficUpdateReplacement() {
    TrafficSimulator simulator;

    simulator.setTraffic(1, 2, 2.0);
    simulator.setTraffic(1, 2, 3.0);

    assert(
        simulator.getMultiplier(1, 2) == 3.0
    );

    assert(
        simulator.getTravelTime(1, 2, 10.0) == 30.0
    );

    std::cout << "PASS: traffic update replacement\n";
}

void testClearTraffic() {
    TrafficSimulator simulator;

    simulator.setTraffic(1, 2, 2.5);

    simulator.clearTraffic();

    assert(
        simulator.getMultiplier(1, 2) == 1.0
    );

    assert(
        simulator.getTravelTime(1, 2, 10.0) == 10.0
    );

    std::cout << "PASS: clear traffic\n";
}

void testInvalidMultiplier() {
    TrafficSimulator simulator;

    bool threw = false;

    try {
        simulator.setTraffic(1, 2, 0.0);
    }
    catch (...) {
        threw = true;
    }

    assert(threw);

    std::cout << "PASS: invalid multiplier handling\n";
}

int main() {
    testDefaultTraffic();
    testTrafficUpdate();
    testTrafficUpdateReplacement();
    testClearTraffic();
    testInvalidMultiplier();

    std::cout << "\nAll traffic simulator tests passed!\n";

    return 0;
}