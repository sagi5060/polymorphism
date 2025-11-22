#include "04_function_overriding.h"

namespace FunctionOverriding {
    void Vehicle::start() {
        std::cout << "Vehicle starting\n";
    }

    void Car::start() {
        std::cout << "Car engine started\n";
    }

    void Bike::start() {
        std::cout << "Bike engine started\n";
    }

    void execute() {
        std::cout << "\n=== 04: FUNCTION OVERRIDING ===\n";
        Vehicle* vehicles[] = {new Car(), new Bike()};
        
        std::cout << "Starting vehicles:\n";
        for (int i = 0; i < 2; i++) {
            vehicles[i]->start();  // Calls overridden versions
        }
        
        // Cleanup
        for (int i = 0; i < 2; i++) {
            delete vehicles[i];
        }
    }
}