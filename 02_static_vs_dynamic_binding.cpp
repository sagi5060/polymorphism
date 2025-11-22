#include "02_static_vs_dynamic_binding.h"

namespace StaticVsDynamicBinding {
    void Calculator::add(int a, int b) {
        std::cout << "Base Calculator: Sum is " << (a + b) << std::endl;
    }

    void Calculator::multiply(int a, int b) {
        std::cout << "Base Calculator: Product is " << (a * b) << std::endl;
    }

    void ScientificCalculator::add(int a, int b) {
        std::cout << "Scientific Calculator: Advanced Sum is " << (a + b) << std::endl;
    }

    void ScientificCalculator::multiply(int a, int b) {
        std::cout << "Scientific Calculator: Advanced Product is " << (a * b) << std::endl;
    }

    void execute() {
        std::cout << "\n=== 02: STATIC VS DYNAMIC BINDING ===\n";
        std::cout << "Demonstrating the key difference between Static and Dynamic Binding:\n";
        
        Calculator calc;
        ScientificCalculator sciCalc;
        
        std::cout << "\n--- Direct Object Calls (Normal behavior) ---\n";
        std::cout << "Calculator.add(5, 3): ";
        calc.add(5, 3);
        
        std::cout << "Calculator.multiply(5, 3): ";
        calc.multiply(5, 3);
        
        std::cout << "ScientificCalculator.add(5, 3): ";
        sciCalc.add(5, 3);
        
        std::cout << "ScientificCalculator.multiply(5, 3): ";
        sciCalc.multiply(5, 3);
        
        std::cout << "\n--- CRITICAL DEMONSTRATION: Base Pointer to Derived Object ---\n";
        Calculator* pCalc = &sciCalc;  // Base pointer points to Derived object
        
        std::cout << "\n*** STATIC BINDING (Non-Virtual Function) ***\n";
        std::cout << "pCalc->add(7, 2): ";
        pCalc->add(7, 2);  // STATIC: Calls Calculator::add (BASE class method!)
        std::cout << "^ NOTICE: Called BASE version even though pointer points to ScientificCalculator!\n";
        
        std::cout << "\n*** DYNAMIC BINDING (Virtual Function) ***\n";
        std::cout << "pCalc->multiply(7, 2): ";
        pCalc->multiply(7, 2);  // DYNAMIC: Calls ScientificCalculator::multiply (DERIVED class method!)
        std::cout << "^ NOTICE: Called DERIVED version because it's virtual!\n";
        
        std::cout << "\n--- Comparison Side by Side ---\n";
        std::cout << "Same pointer (pCalc), same object (ScientificCalculator), different behavior:\n";
        std::cout << "NON-VIRTUAL add():      ";
        pCalc->add(10, 5);      // Static binding -> Base class
        std::cout << "VIRTUAL multiply():     ";
        pCalc->multiply(10, 5);  // Dynamic binding -> Derived class
        
        std::cout << "\n--- Key Learning Points ---\n";
        std::cout << "• STATIC BINDING (non-virtual): Function chosen at COMPILE TIME based on POINTER TYPE\n";
        std::cout << "• DYNAMIC BINDING (virtual): Function chosen at RUNTIME based on ACTUAL OBJECT TYPE\n";
        std::cout << "• Even with same pointer to same object, behavior differs based on 'virtual' keyword\n";
        std::cout << "• Static binding = pointer type decides, Dynamic binding = object type decides\n";
    }
}