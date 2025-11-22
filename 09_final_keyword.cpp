#include "09_final_keyword.h"

namespace FinalKeyword {
    void Animal::speak() {
        std::cout << "Animal sound\n";
    }
    
    void Animal::move() {
        std::cout << "Animal moving\n";
    }

    void Dog::move() {
        std::cout << "Dog running\n";
    }

    void Cat::move() {
        std::cout << "Cat walking\n";
    }

    void execute() {
        std::cout << "\n=== 09: FINAL KEYWORD ===\n";
        std::cout << "Final prevents overriding:\n";
        
        Animal a;
        a.speak();
        a.move();
        
        std::cout << "\nDog (cannot override final speak()):\n";
        Dog d;
        d.speak();  // Calls Animal::speak (final)
        d.move();   // Calls Dog::move (overridden)
        
        std::cout << "\nCat (final class):\n";
        Cat c;
        c.speak();  // Calls Animal::speak (final)
        c.move();   // Calls Cat::move (overridden)
        
        std::cout << "\n• Final methods cannot be overridden\n";
        std::cout << "• Final classes cannot be inherited\n";
    }
}