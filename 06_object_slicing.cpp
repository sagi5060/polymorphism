#include "06_object_slicing.h"

namespace ObjectSlicing {
    void Animal::speak() {
        std::cout << "Generic animal sound" << std::endl;
    }

    void Dog::speak() {
        std::cout << "Woof! Woof!" << std::endl;
    }

    // BAD: Pass by value causes slicing
    void feedAnimal_Bad(Animal animal) {
        std::cout << "Feeding animal (by value): ";
        animal.speak();  // Always calls Animal::speak() due to slicing
    }

    // GOOD: Pass by reference preserves polymorphism
    void feedAnimal_Good(Animal& animal) {
        std::cout << "Feeding animal (by reference): ";
        animal.speak();  // Calls correct speak() method based on actual object type
    }

    void execute() {
        std::cout << "\n=== 06: OBJECT SLICING ===\n";
        std::cout << "Demonstrating Object Slicing Problem:\n";
        
        Dog myDog;
        Animal myAnimal;
        
        std::cout << "\n--- Direct Method Calls ---\n";
        std::cout << "Dog speaks: ";
        myDog.speak();
        
        std::cout << "Animal speaks: ";
        myAnimal.speak();
        
        std::cout << "\n--- Object Slicing Problem (Pass by Value) ---\n";
        std::cout << "Passing Dog to function that takes Animal by VALUE:\n";
        feedAnimal_Bad(myDog);  // Object slicing occurs here!
        std::cout << "^ Notice: Dog's bark is lost - only Animal part is copied!\n";
        
        std::cout << "\n--- Correct Approach (Pass by Reference) ---\n";
        std::cout << "Passing Dog to function that takes Animal by REFERENCE:\n";
        feedAnimal_Good(myDog);  // No slicing - polymorphism preserved
        std::cout << "^ Correct: Dog's bark is preserved!\n";
        
        std::cout << "\n--- Polymorphic Behavior Comparison ---\n";
        Animal* dogPtr = &myDog;
        std::cout << "Through pointer: ";
        dogPtr->speak();  // Works correctly - no slicing
        
        std::cout << "\n--- Key Learning Points ---\n";
        std::cout << "• Object slicing occurs when passing derived objects by VALUE\n";
        std::cout << "• Only the BASE part of the object is copied\n";
        std::cout << "• Derived class functionality is 'sliced off'\n";
        std::cout << "• Use REFERENCES or POINTERS to preserve polymorphism\n";
        std::cout << "• Pass by value breaks virtual function calls\n";
    }
}