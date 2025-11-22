#pragma once
#include <iostream>

namespace VirtualDestructors {
    class Base {
    public:
        Base();
        virtual ~Base(); // Virtual destructor
        // ~Base(); // Bad Destructor
    };
    
    class Derived : public Base {
    public:
        Derived();
        ~Derived();
    };

    void execute();
}