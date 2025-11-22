#include "13_dynamic_cast.h"

namespace DynamicCast {
    void Animal::makeSound() { 
        std::cout << "Animal sound\n"; 
    }

    void Dog::makeSound() { 
        std::cout << "Woof!\n"; 
    }
    
    void Dog::bark() { 
        std::cout << "Bark bark!\n"; 
    }
    
    void Dog::wagTail() { 
        std::cout << "Wagging tail\n"; 
    }

    void Cat::makeSound() { 
        std::cout << "Meow!\n"; 
    }
    
    void Cat::meow() { 
        std::cout << "Meow meow!\n"; 
    }
    
    void Cat::purr() { 
        std::cout << "Purr purr\n"; 
    }

    void Bird::makeSound() { 
        std::cout << "Tweet!\n"; 
    }
    
    void Bird::fly() { 
        std::cout << "Flying high\n"; 
    }

    void execute() {
        std::cout << "\n=== 13: DYNAMIC CAST ===\n";
        std::cout << "Safe Type Conversion:\n";
        
        Animal* animals[] = {new Dog(), new Cat(), new Bird()};
        
        for (int i = 0; i < 3; i++) {
            std::cout << "\n--- Animal " << (i+1) << " ---\n";
            animals[i]->makeSound();
            
            // Safe downcasting with dynamic_cast
            Dog* dog = dynamic_cast<Dog*>(animals[i]);
            if (dog) {
                std::cout << "This is a dog! ";
                dog->wagTail();
            }
            
            Cat* cat = dynamic_cast<Cat*>(animals[i]);
            if (cat) {
                std::cout << "This is a cat! ";
                cat->purr();
            }
            
            Bird* bird = dynamic_cast<Bird*>(animals[i]);
            if (bird) {
                std::cout << "This is a bird! ";
                bird->fly();
            }
        }
        
        // Cleanup
        for (int i = 0; i < 3; i++) {
            delete animals[i];
        }
        
        std::cout << "\n• Dynamic cast returns nullptr for failed casts\n";
        std::cout << "• Safe runtime type identification\n";
    }
}