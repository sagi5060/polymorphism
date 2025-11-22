#include "12_virtual_destructors.h"

namespace VirtualDestructors {
    Base::Base() { 
        std::cout << "Base Constructor\n"; 
    }
    
    Base::~Base() { 
        std::cout << "Base Destructor\n"; 
    }

    Derived::Derived() { 
        std::cout << "Derived Constructor\n"; 
    }
    
    Derived::~Derived() { 
        std::cout << "Derived Destructor\n"; 
    }

    void execute() {
        std::cout << "\n=== 12: VIRTUAL DESTRUCTORS ===\n";
        std::cout << "Proper Destructor Chain:\n";
        
        std::cout << "\nCreating Derived object through Base pointer:\n";
        Base* obj = new Derived();
        
        std::cout << "\nDeleting Base pointer:\n";
        delete obj; // Correctly calls Derived destructor first due to virtual destructor
        
        std::cout << "\n• Virtual destructors prevent memory leaks\n";
        std::cout << "• Ensures proper cleanup of derived objects\n";
    }
}