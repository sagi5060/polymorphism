#include "11_smart_pointers.h"

namespace SmartPointers {
    void Shape::draw() const {
        std::cout << "Drawing Shape\n";
    }

    void Circle::draw() const {
        std::cout << "Drawing Circle\n";
    }

    void Rectangle::draw() const {
        std::cout << "Drawing Rectangle\n";
    }

    void execute() {
        std::cout << "\n=== 11: SMART POINTERS ===\n";
        std::cout << "Polymorphism with Smart Pointers:\n";
        
        std::unique_ptr<Shape> shape1 = std::make_unique<Circle>();
        std::unique_ptr<Shape> shape2 = std::make_unique<Rectangle>();
        
        shape1->draw(); // Drawing Circle
        shape2->draw(); // Drawing Rectangle
        
        // Automatic cleanup - no manual delete needed!
        std::cout << "\n• Automatic memory management\n";
        std::cout << "• No manual delete calls\n";
        std::cout << "• Exception safe\n";
    }
}