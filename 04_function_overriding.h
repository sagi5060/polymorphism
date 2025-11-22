#pragma once
#include <iostream>

namespace FunctionOverriding {
    class Vehicle {
    public:
        virtual void start();
        virtual ~Vehicle() = default;
    };

    class Car : public Vehicle {
    public:
        void start() override;  // override ensures correct signature
    };

    class Bike : public Vehicle {
    public:
        void start() override;
    };

    void execute();
}