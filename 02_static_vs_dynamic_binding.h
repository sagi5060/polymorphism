#pragma once
#include <iostream>

namespace StaticVsDynamicBinding {
    class Calculator {
    public:
        // Non-virtual function - static binding
        void add(int a, int b);
        
        // Virtual function - dynamic binding
        virtual void multiply(int a, int b);
        
        virtual ~Calculator() = default;
    };

    class ScientificCalculator : public Calculator {
    public:
        // Function hiding (static binding)
        void add(int a, int b);
        
        // Function overriding (dynamic binding)
        void multiply(int a, int b) override;
    };

    void execute();
}