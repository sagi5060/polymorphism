#include "07_abstract_classes.h"

namespace AbstractClasses {
    void Shape::info() {
        std::cout << "Area: " << area() << "\n";
    }

    Rectangle::Rectangle(double w, double h) : width(w), height(h) {}

    void Rectangle::draw() {
        std::cout << "Drawing rectangle\n";
    }

    double Rectangle::area() {
        return width * height;
    }

    void execute() {
        std::cout << "\n=== 07: ABSTRACT CLASSES ===\n";
        // Shape s;  // ERROR: Cannot instantiate abstract class
        Rectangle rect(5.0, 3.0);
        rect.draw();
        rect.info();
    }
}