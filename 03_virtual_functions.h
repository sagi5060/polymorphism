#pragma once
#include <iostream>

namespace VirtualFunctions {
    class Shape {
    public:
        virtual void draw();
        virtual ~Shape() = default;
    };

    class Circle : public Shape {
    public:
        void draw() override;
    };

    class Square : public Shape {
    public:
        void draw() override;
    };

    void execute();
}