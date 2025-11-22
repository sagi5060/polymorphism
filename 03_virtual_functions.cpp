#include "03_virtual_functions.h"

namespace VirtualFunctions {
    void Shape::draw() {
        std::cout << "Drawing generic shape\n";
    }

    void Circle::draw() {
        std::cout << "Drawing circle\n";
    }

    void Square::draw() {
        std::cout << "Drawing square\n";
    }

    void execute() {
        std::cout << "\n=== 03: VIRTUAL FUNCTIONS ===\n";
        Shape* shapes[] = {new Circle(), new Square()};

        std::cout << "Virtual function calls:\n";
        for (int i = 0; i < 2; i++) {
            shapes[i]->draw();  // Calls correct derived version
        }

        // Cleanup
        for (int i = 0; i < 2; i++) {
            delete shapes[i];
        }
    }
}