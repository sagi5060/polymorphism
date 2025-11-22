#include "08_virtual_inheritance.h"

namespace VirtualInheritance {
    Animal::Animal() { 
        std::cout << "Creating Animal\n"; 
    }
    
    void Animal::eat() { 
        std::cout << "Animal eating\n"; 
    }

    Horse::Horse() { 
        std::cout << "Creating Horse\n"; 
    }
    
    void Horse::gallop() { 
        std::cout << "Horse galloping\n"; 
    }

    Donkey::Donkey() { 
        std::cout << "Creating Donkey\n"; 
    }
    
    void Donkey::bray() { 
        std::cout << "Donkey braying\n"; 
    }

    Mule::Mule() { 
        std::cout << "Creating Mule\n"; 
    }
    
    void Mule::showAbilities() {
        gallop();  // From Horse
        bray();    // From Donkey
        eat();     // From Animal (only one copy!)
    }

    void execute() {
        std::cout << "\n=== 08: VIRTUAL INHERITANCE ===\n";
        std::cout << "Diamond Problem Solution:\n";
        std::cout << "Creating Mule with virtual inheritance:\n";
        Mule mule;
        
        std::cout << "\nMule abilities:\n";
        mule.showAbilities();
        
        std::cout << "\n• Virtual inheritance prevents duplicate Animal objects\n";
        std::cout << "• Only one Animal constructor called, not two\n";
    }
}