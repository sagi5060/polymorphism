#pragma once
#include <iostream>

namespace AbstractClasses {
    // Abstract class - cannot be instantiated
    class Shape {
    public:
        // Pure virtual functions must be implemented by derived classes
        virtual void draw() = 0;
        virtual double area() = 0;

        // Can have regular virtual functions too
        virtual void info();

        virtual ~Shape() = default;
    };

    class Rectangle : public Shape {
    private:
        double width, height;
    public:
        Rectangle(double w, double h);

        void draw() override;
        double area() override;
    };

    void execute();
}