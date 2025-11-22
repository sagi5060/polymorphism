// Unified Main - All Polymorphism Examples
// Runs all 14 polymorphism examples in sequence
#include <iostream>
#include <memory>
#include <vector>
#include <typeinfo>

// Include all polymorphism example headers
#include "01_polymorphism_concept.h"
#include "02_static_vs_dynamic_binding.h"
#include "03_virtual_functions.h"
#include "04_function_overriding.h"
#include "05_vtable_vptr.h"
#include "06_object_slicing.h"
#include "07_abstract_classes.h"
#include "08_virtual_inheritance.h"
#include "09_final_keyword.h"
#include "10_stack_interface.h"
#include "11_smart_pointers.h"
#include "12_virtual_destructors.h"
#include "13_dynamic_cast.h"
#include "14_interface_segregation.h"

int main() {
    std::cout << "C++ POLYMORPHISM - COMPLETE EXAMPLES COLLECTION\n";
    std::cout << "===============================================\n";
    
    // Core Polymorphism Concepts
    // std::cout << "CORE POLYMORPHISM CONCEPTS:\n";
    // std::cout << "===========================\n";
    // PolymorphismConcept::execute();
    StaticVsDynamicBinding::execute();
    // VirtualFunctions::execute();
    // FunctionOverriding::execute();
    // VTableAndVPtr::execute();
    
    // Advanced Concepts
    // std::cout << "\n\nADVANCED CONCEPTS:\n";
    // std::cout << "==================\n";
    // ObjectSlicing::execute();
    // AbstractClasses::execute();
    // VirtualInheritance::execute();
    // FinalKeyword::execute();
    // StackInterface::execute();
    
    // Modern C++ Features
    // std::cout << "\n\nMODERN C++ FEATURES:\n";
    // std::cout << "====================\n";
    // SmartPointers::execute();
    VirtualDestructors::execute();
    DynamicCast::execute();
    InterfaceSegregation::execute();
    
    std::cout << "\n\n===============================================\n";
    std::cout << "All polymorphism examples completed successfully!\n";
    
    return 0;
}