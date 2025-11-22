#include "01_polymorphism_concept.h"

namespace PolymorphismConcept {
    void execute() {
        std::cout << "\n=== 01: POLYMORPHISM CONCEPT ===\n";
        Animal* pets[] = {new Dog(), new Cat(), new Dog()};
        
        std::cout << "Polymorphism in action:\n";
        for (int i = 0; i < 3; i++) {
            pets[i]->speak();  // Same call, different behaviors
        }
        
        // Cleanup
        for (int i = 0; i < 3; i++) {
            delete pets[i];
        }
    }
}