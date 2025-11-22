#pragma once
#include <iostream>
#include <memory>

namespace SmartPointers {
    class Shape {
    public:
        virtual ~Shape() {}
        virtual void draw() const;
    };

    class Circle : public Shape {
    public:
        void draw() const override;
    };

    class Rectangle : public Shape {
    public:
        void draw() const override;
    };

    void execute();
}